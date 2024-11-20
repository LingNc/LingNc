import os
import subprocess
import random
import sys

# 定义生成数据的函数
def generate_data(data_type, data_range, num_data):
    if data_type == 'int':
        return [random.randint(data_range[0], data_range[1]) for _ in range(num_data)]
    elif data_type == 'float':
        return [random.uniform(data_range[0], data_range[1]) for _ in range(num_data)]
    elif data_type == 'str':
        return [''.join(random.choices('abcdefghijklmnopqrstuvwxyz', k=random.randint(data_range[0], data_range[1]))) for _ in range(num_data)]
    else:
        raise ValueError("Unsupported data type")

# 定义运行AC代码的函数
def run_ac_code(input_file, output_file, ac_code_path, is_multi_instance):
    with open(input_file, 'r') as infile:
        if is_multi_instance:
            # 多实例运行
            with open(output_file, 'w') as outfile:
                subprocess.run([ac_code_path], stdin=infile, stdout=outfile)
        else:
            # 单实例运行
            with open(output_file, 'w') as outfile:
                subprocess.run([ac_code_path], stdin=infile, stdout=outfile)

# 主函数
def main():
    # 创建./test文件夹
    test_dir = "./test"
    if not os.path.exists(test_dir):
        os.makedirs(test_dir)

    # 用户输入参数
    num_tests = int(input("请输入要生成的测试数据组数: "))
    num_data = int(input("代码输入由几个数据组成: "))
    data_types = []
    data_ranges = []

    for i in range(num_data):
        data_type = input(f"请输入第 {i+1} 个数据的类型 (int/float/str): ")
        data_types.append(data_type)
        if data_type == 'int' or data_type == 'float':
            data_range = tuple(map(int, input(f"请输入第 {i+1} 个数据的数据范围 (例如: 1 100): ").split()))
        elif data_type == 'str':
            data_range = tuple(map(int, input(f"请输入第 {i+1} 个数据的长度范围 (例如: 1 10): ").split()))
        else:
            raise ValueError("Unsupported data type")
        data_ranges.append(data_range)

    ac_code_path = input("请输入AC代码的路径: ")
    is_multi_instance = input("是否为多实例 (yes/no): ").lower() == 'yes'

    # 如果为多实例，询问实例个数的范围
    if is_multi_instance:
        instance_range = tuple(map(int, input("请输入实例个数的范围 (例如: 1 10): ").split()))

    # 生成测试数据并运行AC代码
    for i in range(num_tests):
        input_file = os.path.join(test_dir, f"test_{i+1}.in")
        output_file = os.path.join(test_dir, f"test_{i+1}.out")

        # 生成数据
        if is_multi_instance:
            num_instances = random.randint(instance_range[0], instance_range[1])
            data = []
            for _ in range(num_instances):
                instance_data = []
                for j in range(num_data):
                    instance_data.append(generate_data(data_types[j], data_ranges[j], 1)[0])
                data.append(instance_data)
        else:
            data = []
            for j in range(num_data):
                data.append(generate_data(data_types[j], data_ranges[j], 1)[0])

        with open(input_file, 'w') as f:
            if is_multi_instance:
                f.write(f"{num_instances}\n")
                for instance in data:
                    for d in instance:
                        f.write(f"{d}\n")
            else:
                for d in data:
                    f.write(f"{d}\n")

        # 运行AC代码
        run_ac_code(input_file, output_file, ac_code_path, is_multi_instance)

        print(f"测试数据 {input_file} 和输出文件 {output_file} 已生成。")

if __name__ == "__main__":
    main()