# -*- coding: utf-8 -*-
# 该文件用于生成C++算法问题的随机数据，并使用生成的数据运行给定的AC可执行文件，生成对应的输出文件。

import os
import random
import subprocess

# 提示用户输入需要生成的数据集数量
num_sets = int(input('请输入需要生成的数据集数量: '))

# 创建数据目录
data_dir = 'B_data'
if not os.path.exists(data_dir):
    os.makedirs(data_dir)

# 生成随机数据并保存到.in文件中
for i in range(16, num_sets + 1):
    T = random.randint(1, 100000)
    with open(f'{data_dir}/{i}.in', 'w') as f:
        f.write(f'{T}\n')
        for _ in range(T):
            x = random.randint(1, 1000000)
            y = random.randint(1, 1000000)
            f.write(f'{x} {y}\n')

# 运行AC可执行文件，生成对应的.out文件
ac_executable = './ac_executable'
for i in range(1, num_sets + 1):
    with open(f'{data_dir}/{i}.in', 'r') as infile, open(f'{data_dir}/{i}.out', 'w') as outfile:
        result = subprocess.run([ac_executable], stdin=infile, stdout=outfile, text=True)
        if result.returncode != 0:
            print(f'运行可执行文件时出错: {result.stderr}')
            break

print(f'已成功生成{num_sets}组数据，并保存到{data_dir}目录中。')