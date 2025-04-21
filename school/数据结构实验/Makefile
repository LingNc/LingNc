# 使用的编译器
CC = clang
# 编译选项
FLAG = -std=c99 -Wall -Wextra -g
# 链接库 m
LIB = -lm

#头文件文件夹
Include = include

# 创建 build 目录
$(shell mkdir -p build)

# 构建实验1 main1
# 链接文件
main1 : build/main1.o build/sqlist.o build/linklist.o
	@echo "正在链接 实验一 主函数..."
	$(CC) $(FLAG) $^ -o $@ $(LIB)

# 编译文件
build/main1.o : main1.c
	@echo "正在编译 实验一 主函数..."
	$(CC) $(FLAG) -I$(Include) -c $< -o $@

# 编译文件
build/sqlist.o : src/sqlist.c
	@echo "正在编译 实验一 顺序线性表..."
	$(CC) $(FLAG) -I$(Include) -c $< -o $@

# 编译文件
build/linklist.o : src/linklist.c
	@echo "正在编译 实验一 链式线性表..."
	$(CC) $(FLAG) -I$(Include) -c $< -o $@

# 获取当前工作目录的绝对路径
CURRENT_DIR := $(shell pwd)

# 创建clangd文件
.PHONY : clangd
clangd :
	@echo "正在创建 .clangd 文件..."
	@echo "CompileFlags:" > .clangd
	@echo "  Add: [-I$(CURRENT_DIR)/$(Include)]" >> .clangd
	@echo ".clangd 文件创建完成！"

# 清理文件
.PHONY : clean
clean :
	@echo "正在清理..."
	@rm .clangd
	@rm -rf build/*.o
	@rm -rf main[1-4]
	@echo "清理完成！"