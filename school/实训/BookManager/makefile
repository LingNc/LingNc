# Makefile

# 编译器
cxx = g++

# 编译器选项
cxxflags = -std=c++20 -Wall -g

# 目标文件
target = main

# 查找所有的 .cpp 文件
srcs = $(wildcard *.cpp)

# 生成对应的 .o 文件
objs = $(srcs:.cpp=.o)

# 目标规则
$(target): $(objs)
	$(cxx) $(cxxflags) -o $(target) $(objs)

# .cpp 文件生成 .o 文件的规则
%.o: %.cpp
	$(cxx) $(cxxflags) -c $< -o $@

# 清理规则
.PHONY: clean
clean:
	rm -f $(target) $(objs)