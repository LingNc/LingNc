import re

# 读取文件内容
with open('log.txt', 'r') as file:
    text = file.read()

# 正则表达式模式，用于匹配包含"Action"的行并提取目标字符串
pattern = re.compile(r'Action \d+:\d+:\d+: Verifying model hash\. Verifying integrity of (.+?)(?=\s|$)')

# 查找所有匹配的行
matches = pattern.findall(text)

with open('res.txt', 'w') as file:
    # 输出结果
    for match in matches:
        file.write(f"http://models-bal.topazlabs.com/v1/{match}\n")

