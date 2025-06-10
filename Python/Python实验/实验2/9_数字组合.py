numbers = []
for i in range(10):
    num = int(input(f"请输入第{i+1}个整数："))
    numbers.append(num)

print("所有两个数的组合：")
for i in range(len(numbers)):
    for j in range(i+1, len(numbers)):
        print(f"({numbers[i]}, {numbers[j]})")
