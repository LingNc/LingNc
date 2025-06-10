str1 = input("请输入第一个字符串：")
str2 = input("请输入第二个字符串：")

found = False
index = -1

for i in range(len(str2) - len(str1) + 1):
    if str2[i:i+len(str1)] == str1:
        found = True
        index = i
        break

if found:
    print(f"'{str1}' 是 '{str2}' 的子串，位置在索引 {index}")
else:
    print(f"'{str1}' 不是 '{str2}' 的子串")
