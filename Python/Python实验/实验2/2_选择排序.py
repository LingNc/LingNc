# 2. 选择排序

def selection_sort(lst, ascending=True):
    """实现选择排序算法，默认是升序排列"""
    result = lst.copy()  # 复制列表，不修改原列表
    n = len(result)

    for i in range(n):
        # 找到当前位置应该放置的元素的索引
        target_index = i
        for j in range(i + 1, n):
            if ascending:
                # 升序：找最小值
                if result[j] < result[target_index]:
                    target_index = j
            else:
                # 降序：找最大值
                if result[j] > result[target_index]:
                    target_index = j

        # 交换元素
        result[i], result[target_index] = result[target_index], result[i]

    return result

# 测试程序

numbers_str = input("请输入若干个整数（用空格分隔）：")
numbers = [int(x) for x in numbers_str.split()]

sorted_numbers = selection_sort(numbers, ascending=True)
print(f"原始数列：{numbers}")
print(f"升序排序后：{sorted_numbers}")
