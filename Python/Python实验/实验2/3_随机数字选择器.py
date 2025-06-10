# 3. 随机数字选择器

import random

def shuffle(lst):
    """打乱一个列表并返回这个列表"""
    result = lst.copy()  # 复制列表，不修改原列表
    n = len(result)

    # Fisher-Yates洗牌算法
    for i in range(n - 1, 0, -1):
        # 生成0到i之间的随机索引
        j = random.randint(0, i)
        # 交换元素
        result[i], result[j] = result[j], result[i]

    return result

# 测试程序
numbers_str = input("请输入一个数字列表（用空格分隔）：")
numbers = [int(x) for x in numbers_str.split()]

shuffled_numbers = shuffle(numbers)
print(f"原始列表：{numbers}")
print(f"打乱后的列表：{shuffled_numbers}")
