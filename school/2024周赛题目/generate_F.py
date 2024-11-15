# -*- coding: utf-8 -*-

# 生成随机数据并运行AC代码以生成答案
# 本脚本用于生成C++算法问题的随机数据，并将数据保存为.in文件，然后运行AC代码生成对应的.out文件

import os
import random
import subprocess

# 问题编号
problem_num = 'F'

# 数据目录
data_dir = f'./{problem_num}_data/'

# 创建数据目录
if not os.path.exists(data_dir):
    os.makedirs(data_dir)

# 提示用户输入需要生成的数据集数量
num_sets = int(input('请输入需要生成的数据集数量: '))

# 生成随机数据并保存到.in文件，然后运行AC代码生成.out文件
for i in range(1, num_sets + 1):
    # 生成随机数据
    n = random.randint(1, 10**9)
    m = random.randint(1, n)
    
    # 保存到.in文件
    with open(f'{data_dir}{i}.in', 'w') as f:
        f.write(f'{n} {m}\n')
    
    # 运行AC代码生成.out文件
    result = subprocess.run(['./ac_executable'], input=f'{n} {m}\n', text=True, capture_output=True)
    with open(f'{data_dir}{i}.out', 'w') as f:
        f.write(result.stdout)

print(f'已生成{num_sets}组数据，保存在{data_dir}目录下。')
