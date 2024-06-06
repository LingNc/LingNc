import os
from openai import OpenAI
import json

# for backward compatibility, you can still use `https://api.deepseek.com/v1` as `base_url`.
client = OpenAI(api_key="sk-9011b751ed194e12bc0876ed3256f172", base_url="https://api.deepseek.com")
def main():
    # 打开并读取JSON文件
    with open('question.json', 'r') as file:
        data = json.load(file)

    # 从JSON数据中提取数组
    questions = data["questions"]

    # # 打印数组内容
    # print(question)

    #进入循环读取
    for index,ques in enumerate(questions):
        
        index += 1
        # if index !=66:
        #     continue

        #判断问题是不是简单问题
        IsEasy = judge(ques)
        if IsEasy == 'error':
            print("第{index}个问题，判断难度失败")
            continue
        
        #选择执行
        if IsEasy:
            easy(ques,index)
        else:
            diff(ques,index)
        


def judge(ques):
    #载入prompt_judge文件
    with open('prompt_judge.txt', 'r') as file:
        prompt_judge = file.read()
    #合并问题
    question=prompt_judge+ques
    #请求答案
    result=deepseek(question,1024)
    #解析JSON
    res = JSON(result)
    #异常处理
    if res == 'error':
        return res
    else:
        return res["easy"]
    

def diff(ques,index):
    # 打开prompt_problem文件并读取内容
    with open('prompt_problem.txt', 'r') as file:
        prompt_problem = file.read()
    
    #合并问题
    question=prompt_problem+ques
    #请求答案
    result=deepseek(question,16384)
    #第一次解析配置文件
    res_1=JSON(result,ques)
    #异常处理
    if res_1=='error':
        print("第{index}个问题，解析配置文件失败")
        return 0
    
    #解析JSON
    json_problem=res_1["content"]
    # 获取第二次请求内容
    ques_2={}
    ques_2["question"]=res_1["question"]
    ques_2["RightCode"]=res_1["RightCode"]
    ques_2["testDataFileUse"]=res_1["testDataFileUse"]
    #载入prompt_data.txt
    with open('prompt_data.txt', 'r') as file:
        prompt_data = file.read()
    #合并问题
    question_2=prompt_data+ques_2
    
    # 发送第二次请求，获取测试数据点
    result_2=deepseek(question_2,32768)
    #第二次解析配置文件
    res_2=JSON(result_2,ques_2)
    #异常处理
    if res_2=='error':
        return 0
    #解析数据
    json_data=res_2
    
    # 保存数据
    save_json(json_problem,json_data)
    
def easy(ques,index):
    # 打开prompt文件并读取内容
    with open('base_question.txt', 'r') as file:
        base_question = file.read()
    
    #合并问题
    question=base_question+ques
    #请求答案JSON
    result=deepseek(question,16384)
    #解析JSON并存储
    res_json = JSON(result,ques)
    #异常处理
    if res_json == "error":
        print("第{index}个问题，解析配置文件失败")
        return 0
    #拆分JSON
    json_problem=res_json["json"][0]
    json_data=res_json["json"][1]
    #调用save储存
    save_json(json_problem,json_data)

def JSON(result,ques):
    #异常处理
    try:
        res_json=json.loads(result)
    except Exception as e:
        print("error: JSON解析失败")
        with open('error.json', 'r') as file:
            res_json=json.load(file)
        #把异常写入error.log
        with open("error.log", "a") as f:
            f.write(ques + "\n")
            f.write(result + "\n")
            f.write(str(e) + "\n")
            return "error"

    else:
        print(res_json["json"][0]["problem"]["problemId"] + "生成成功")
        
        return res_json
        # 保存结果到文件
        # save_json(res_json)
#返回problem_id
def save_problem(json_problem):
    #添加语言
    json_problem["languages"]=[
            "C",
            "C With O2",
            "C++",
            "C++ With O2",
            "C++ 17",
            "C++ 17 With O2",
            "C++ 20",
            "C++ 20 With O2",
            "Java",
            "Python3",
            "Golang",
            "C#",
            "JavaScript Node",
            "JavaScript V8"
        ]

    # 提取问题ID
    problem_id = json_problem["problem"]["problemId"][1:]

    # 生成文件结构
    # 确保problem目录存在
    problem_dir = "problem"
    if not os.path.exists(problem_dir):
        os.mkdir(problem_dir)

    # 在problem目录中创建JSON文件
    json_file_path = os.path.join(problem_dir, f"problem_{problem_id}.json")
    with open(json_file_path, 'w',encoding='utf-8') as json_file:
        json.dump(json_problem, json_file,ensure_ascii=False)

    # 在problem目录中创建problem_id文件夹
    problem_id_dir = os.path.join(problem_dir, "problem_"+problem_id)
    if not os.path.exists(problem_id_dir):
        os.mkdir(problem_id_dir)
        
def save_data(json_data,problem_id):
    #设置文件基础路径
    problem_dir = "problem"
    problem_id_dir = os.path.join(problem_dir, "problem_"+problem_id)
    
    # 遍历json_data中的data列表
    for data_set_name, data_set in json_data.items():
        for data in data_set:
            for filename, content in data.items():
                # 确保我们处理的是in或out文件
                if filename.endswith('.in') or filename.endswith('.out'):
                    # 创建文件路径
                    file_path = os.path.join(problem_id_dir, filename)
                    # 写入文件内容
                    with open(file_path, 'w',encoding='utf-8') as file:
                        file.write(content)

    

def save_json(json_problem,json_data):
    #res_json=json.load(open("test.json",'r'))

    # #载入对象
    # json_problem=res_json["json"][0]
    # json_data=res_json["json"][1]

    #添加语言
    json_problem["languages"]=[
            "C",
            "C With O2",
            "C++",
            "C++ With O2",
            "C++ 17",
            "C++ 17 With O2",
            "C++ 20",
            "C++ 20 With O2",
            "Java",
            "Python3",
            "Golang",
            "C#",
            "JavaScript Node",
            "JavaScript V8"
        ]


    # 提取问题ID
    problem_id = json_problem["problem"]["problemId"][1:]

    # 生成文件结构
    # 确保problem目录存在
    problem_dir = "problem"
    if not os.path.exists(problem_dir):
        os.mkdir(problem_dir)

    # 在problem目录中创建JSON文件
    json_file_path = os.path.join(problem_dir, f"problem_{problem_id}.json")
    with open(json_file_path, 'w',encoding='utf-8') as json_file:
        json.dump(json_problem, json_file,ensure_ascii=False)

    # 在problem目录中创建problem_id文件夹
    problem_id_dir = os.path.join(problem_dir, "problem_"+problem_id)
    if not os.path.exists(problem_id_dir):
        os.mkdir(problem_id_dir)

    # 遍历json_data中的data列表
    for data_set_name, data_set in json_data.items():
        for data in data_set:
            for filename, content in data.items():
                # 确保我们处理的是in或out文件
                if filename.endswith('.in') or filename.endswith('.out'):
                    # 创建文件路径
                    file_path = os.path.join(problem_id_dir, filename)
                    # 写入文件内容
                    with open(file_path, 'w',encoding='utf-8') as file:
                        file.write(content)

# deepseek向ai问问题设定最大token
def deepseek(question,max):
    response = client.chat.completions.create(
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "You are a helpful assistant with the code problem solving skills."},
                {"role": "user", "content": question},
        ],
            max_tokens=max,
            temperature=0.1,
            stream=False
        )
    return response.choices[0].message.content[8:-4]

if __name__ == "__main__":
    main()