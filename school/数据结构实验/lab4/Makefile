# 编译器和编译选项
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
INCLUDES = -Iinclude

# 目录定义
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# 源文件和目标文件
SOURCES = $(wildcard $(SRC_DIR)/*.c) main.c
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SOURCES)))
TARGET = $(BIN_DIR)/sort_system

# 默认目标
all: directories $(TARGET)

# 创建必要的目录
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@echo "编译完成：$@"

# 编译源文件生成目标文件
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 运行程序
run: $(TARGET)
	@echo "运行排序算法模拟系统..."
	@./$(TARGET)

# 调试模式
debug: CFLAGS += -DDEBUG
debug: $(TARGET)
	@echo "调试版本编译完成"

# 清理生成的文件
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "清理完成"

# 重新编译
rebuild: clean all

# 安装（可选）
install: $(TARGET)
	@echo "安装到 /usr/local/bin/sort_system"
	@sudo cp $(TARGET) /usr/local/bin/sort_system

# 帮助信息
help:
	@echo "可用的make目标："
	@echo "  all      - 编译程序（默认）"
	@echo "  run      - 编译并运行程序"
	@echo "  debug    - 编译调试版本"
	@echo "  clean    - 清理生成的文件"
	@echo "  rebuild  - 重新编译"
	@echo "  install  - 安装到系统"
	@echo "  help     - 显示此帮助信息"

# 声明伪目标
.PHONY: all directories run debug clean rebuild install help