# 1. 求一个整数各个数字的和

def sum_digits(n):
    """计算一个整数各个数字的和"""
    n = abs(n)  # 取绝对值处理负数
    total = 0
    while n > 0:
        total += n % 10  # 取个位数
        n //= 10  # 去掉个位数
    return total


number = int(input("请输入一个整数："))
result = sum_digits(number)
print(f"{number} 各个数字的和是：{result}")
