numbers_str = input("请输入一个整数列表（用空格分隔）：")
numbers = [int(x) for x in numbers_str.split()]

min_value = numbers[0]
min_index = 0

for i in range(1, len(numbers)):
    if numbers[i] < min_value:
        min_value = numbers[i]
        min_index = i

print(f"最小元素是 {min_value}，下标是 {min_index}")
