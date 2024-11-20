# -*- coding: utf-8 -*-
# 该文件用于生成C++算法问题的随机数据，并将其保存为.in文件，然后运行给定的AC可执行文件生成对应的.out文件

import os
import random
import subprocess

# 生成随机数据
def generate_random_data(format_str, num_commands):
    format_data=format_str
    # 对于每个字符有1/2的概率在其后面添加一个:
    format_str = ''.join(c + (':' if random.choice([True, False]) else '') for c in format_data)
    data = [format_str,str(num_commands)]
    command_base = ''.join(random.sample('abcdefghijklmnopqrstuvwxyz0123456789-',k=random.randint(1,11)))
    for _ in range(num_commands):
        command_line = command_base
        nums = random.randint(1,100)
        for i in range(nums):
            if random.choices([True,False], weights=[15,1], k=1)[0]:
                if random.choices([True,False], weights=[10,1], k=1)[0]:
                    command_line += " -"+''.join(random.choice(format_data))
                else:
                    command_line += " -"+''.join(random.choice('abcdefghijklmnopqrstuvwxyz0123456789-'))
                if random.choice([True,False]):
                    command_line += ' ' + ''.join(random.choices('abcdefghijklmnopqrstuvwxyz0123456789-', k=random.randint(1, 20)))
            else:
                command_line += ' ' + ''.join(random.choices('abcdefghijklmnopqrstuvwxyz0123456789-', k=random.randint(1, 20)))
        data.append(command_line)
    return data

# 保存数据到.in文件
def save_data_to_file(data, file_path):
    with open(file_path, 'w') as f:
        for line in data:
            f.write(line + '\n')

# 运行AC可执行文件并保存输出到.out文件
def run_ac_executable(in_file_path, out_file_path):
    with open(out_file_path, 'w') as out_file:
        subprocess.run(['./ac_executable'], stdin=open(in_file_path), stdout=out_file)

# 主函数
def main():
    # 提示用户输入需要生成的数据集数量
    num_sets = int(input('请输入需要生成的数据集数量: '))
    problem_number = 'H'  # 假设问题编号为A
    data_folder = f'{problem_number}_data'
    os.makedirs(data_folder, exist_ok=True)

    for i in range(1, num_sets + 1):
        # 随机选择不同的字母，最多26个
        format_str = random.sample('abcdefghijklmnopqrstuvwxyz', random.randint(1, 26))
        random.shuffle(format_str)  # 打乱顺序
        format_str = ''.join(format_str)
        num_commands = random.randint(1, 25)
        data = generate_random_data(format_str, num_commands)
        in_file_path = os.path.join(data_folder, f'{i}.in')
        out_file_path = os.path.join(data_folder, f'{i}.out')
        save_data_to_file(data, in_file_path)
        run_ac_executable(in_file_path, out_file_path)

if __name__ == '__main__':
    main()