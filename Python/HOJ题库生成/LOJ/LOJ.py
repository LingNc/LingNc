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

    # 打开文件并读取内容
    with open('base_question.txt', 'r') as file:
        base_question = file.read()

    #进入循环读取
    for index,ques in enumerate(questions):
        if index + 1!=66:
            continue

        #判断问题是不是简单问题

        #生成问题
        question=base_question+ques

        # 接入ai请求结果
        # 得到json结构,载入对象
        result=deepseek(question,4096)
        #异常处理
        try:
            res_json=json.loads(result)
        except Exception as e:
            print("error: 生成有误")
            with open('error.json', 'r') as file:
                res_json=json.load(file)
            #把异常写入error.log
            with open("error.log", "a") as f:
                f.write(ques + "\n")
                f.write(result + "\n")
                f.write(str(e) + "\n")
            continue

        else:
            print(res_json["json"][0]["problem"]["problemId"] + "生成成功")
        finally:
            #保存结果到文件
            save_json(res_json)


def judge():

def diff():

def easy():

def save_json(res_json):
    #res_json=json.load(open("test.json",'r'))

    #载入对象
    json_problem=res_json["json"][0]
    json_data=res_json["json"][1]

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