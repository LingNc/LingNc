import os
import json

def main():
# 当前工作目录
    current_dir = os.getcwd()

    # 遍历当前目录下的所有文件夹
    for folder_name in os.listdir(current_dir):
        # 检查是否是以problem_export_开头的文件夹
        if folder_name.startswith('problem_export_'):
            # 获取文件夹的完整路径
            folder_path = os.path.join(current_dir, folder_name)
            print(folder_path)

            # 调用函数重命名文件
            rename_files(folder_path)


def rename_files(folder_path):
    # 遍历文件夹下的所有文件
    for filename in os.listdir(folder_path):
        if filename.startswith('problem_') and filename.endswith('.json'):
            # 构建完整的文件路径
            file_path = os.path.join(folder_path, filename)

            # 读取JSON文件
            with open(file_path, 'r', encoding='utf-8') as file:
                data = json.load(file)

            # 提取problemID
            problem_id = data.get('problem', {}).get('problemId', '')
            if problem_id:
                # 提取10xx部分
                new_filename = 'problem_' + problem_id.split('C')[1] + '.json'

                # 重命名文件
                new_file_path = os.path.join(folder_path, new_filename)
                os.rename(file_path, new_file_path)

                # 打印重命名信息
                print(f'Renamed {filename} to {new_filename}')

                #重命名对应文件夹名
                os.rename(os.path.join(folder_path, filename.split('.')[0]), os.path.join(folder_path, new_filename.split('.')[0]))

                # 打印重命名信息
                print(f'Renamed {filename.split(".")[0]} to {new_filename.split(".")[0]}')

                #删除对应文件夹下的info文件
                os.remove(os.path.join(folder_path, filename.split('.')[0], 'info'))

                # 打印删除信息
                print(f'Deleted info file in {filename.split(".")[0]}')

            else:
                print(f'No problemID found in {filename}')

if __name__ == '__main__':
    main()