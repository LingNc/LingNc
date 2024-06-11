from openai import OpenAI
import json
import os

# for backward compatibility, you can still use `https://api.deepseek.com/v1` as `base _url`.
client = OpenAI(api_key="sk-9011b751ed194e12bc0876ed3256f172", base_url="https://api.deepseek.com")
# 读取JSON文件
def read_json_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        return json.load(file)

# 写入文件
def write_file(file_path, content):
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(content)

# deepseek向ai问问题设定最大token
def deepseek(question,max,tem):
    response = client.chat.completions.create(
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "You are a helpful assistant with the code problem solving skills."},
                {"role": "user", "content": question},
        ],
            max_tokens=max,
            temperature=tem,
            stream=False
        )
    return response.choices[0].message.content[8:-4]

def JSON(result,id):
    #异常处理
    try:
        res_json=json.loads(result)
    except Exception as e:
        print(f"error: {id}JSON解析失败")
        #把异常写入error.log
        with open("reData_error.log", "a") as f:
            f.write(id + ":\n")
            f.write(result + "\n")
            f.write(str(e) + "\n")
            return "error"
    else:
        return res_json
def solve(json_file_path,base_path):
    # 读取JSON文件
    json_data = read_json_file(json_file_path)

    # 提取所需信息
    ques = json_data['problem']['description']
    id = json_data['problem']['problemId']
    description = json_data['problem']['description']
    input_data = json_data['problem']['input']
    output_data = json_data['problem']['output']

    # 创建新的JSON对象
    new_json = {
        "description": description,
        "input": input_data,
        "output": output_data
    }

    # 合并prompt_answer.txt和新生成的JSON对象
    with open('prompt_answer.txt', 'r', encoding='utf-8') as prompt_file:
        prompt_text = prompt_file.read()
    request_text = prompt_text + json.dumps(new_json)

    temperature = 0.1
    # 调用deepseek函数
    while(temperature<=1):
        result_json_str = deepseek(request_text,4096,temperature)
        result_dict = JSON(result_json_str,id)
        if(result_dict!="error"):
            break
        temperature += 0.3

    # 如果出现错误，返回0
    if(result_dict=="error"):
        return 0


    # 提取RightCode
    right_code = result_dict['RightCode']

    # 创建answer字典
    answer = {
        "question": ques,
        "RightCode": right_code
    }

    # 合并prompt_data.txt和answer字典
    with open('prompt_data.txt', 'r', encoding='utf-8') as prompt_file:
        prompt_text = prompt_file.read()
    request_text = prompt_text + json.dumps(answer)

    # 再次调用deepseek函数
    while(temperature<=1):
        result_json_str = deepseek(request_text,4096,temperature)
        data = JSON(result_json_str,id)
        if(data!="error"):
            break
        temperature += 0.3

    # 如果出现错误，返回0
    if(data=="error"):
        return 0

    # 创建文件夹和文件
    problem_folder = os.path.join(base_path,f'problem_{id}')
    os.makedirs(problem_folder, exist_ok=True)

    # 写入.in和.out文件
    for key, value in data.items():
        for test_case, content in value.items():
            if test_case.endswith('.in'):
                file_path = os.path.join(problem_folder, f'{key}.in')
                write_file(file_path, content)
            elif test_case.endswith('.out'):
                file_path = os.path.join(problem_folder, f'{key}.out')
                write_file(file_path, content)
# 主函数
def main():

    # 当前工作目录
    current_dir = os.getcwd()

    # 遍历当前目录下的所有文件夹
    for folder_name in os.listdir(current_dir):
        # 检查是否是以problem_export_开头的文件夹
        if folder_name.startswith('problem_export_'):
            # 构建基础路径
            base_path = os.path.join(current_dir, folder_name)

            # 遍历基础路径下的所有文件
            for file_name in os.listdir(base_path):
                # 检查是否是json文件
                if file_name.endswith('.json'):
                    # 构建完整的json文件路径
                    json_file_path = os.path.join(base_path, file_name)
                    solve(json_file_path,base_path)


if __name__ == '__main__':
    main()