# -*- coding: utf-8 -*-
# 该文件用于生成随机数据并运行AC可执行文件以生成对应的输出文件

import os
import random
import subprocess

# 提示用户输入需要生成的数据集数量
num_sets = int(input('请输入需要生成的数据集数量: '))

# 创建数据目录
data_dir = 'A_data'
if not os.path.exists(data_dir):
    os.makedirs(data_dir)

# 生成随机数据并保存到.in文件中，然后运行AC可执行文件生成.out文件
for i in range(1, num_sets + 1):
    # 生成随机测试用例数量
    t = 0
    # n总数
    n_total=10**5
    input_data = ''
    while 1:
        # 生成随机蛋糕数量
        n = random.randint(2, n_total)
        n_total -= n
        if(n_total < 2): break
        t+=1
        input_data += f'{n}\n'
        # 生成随机蛋糕大小
        cakes = [random.randint(1, 10**5) for _ in range(n)]
        input_data += ' '.join(map(str, cakes)) + '\n'

    input_t = f'{t}\n'
    input_t+=input_data

    # 保存输入数据到.in文件
    with open(f'{data_dir}/{i}.in', 'w') as f:
        f.write(input_t)

    # 运行AC可执行文件生成输出数据
    result = subprocess.run(['./ac_executable'], input=input_data, text=True, capture_output=True)

    # 保存输出数据到.out文件
    with open(f'{data_dir}/{i}.out', 'w') as f:
        f.write(result.stdout)

print(f'成功生成{num_sets}组数据，并保存到{data_dir}目录下。')