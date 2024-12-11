# Makefile

# 编译器
CC = gcc

# 编译器选项
CFLAGS = -Wall -g -I BookManager/include

# 目标文件
TARGET = main

# 源文件
SRCS = main.c BookManager/src/String.c

# 对象文件
OBJS = $(SRCS:.c=.o)

# 编译目标
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译规则
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# 清理
.PHONY: clean
clean:
    rm -f $(TARGET) $(OBJS)