C = gcc
# 只能使用 gcc 编译器 使用了typeof
Cflags = -Wall -Wextra -std=gnu99 -g

Include = -I./include

Src_files = $(wildcard src/*.c)
Obj_files = $(patsubst src/%.c, build/src/%.o, $(Src_files))

Test_src = $(wildcard tests/*.c)
Test_obj = $(patsubst tests/%.c, build/tests/%.o, $(Test_src))
Test_bin = $(patsubst tests/%.c, build/tests/%, $(Test_src))

Main = main

all : $(Main)
	@echo "构建main成功,在 main"

$(Main): $(Obj_files) build/main.o
	@echo "正在链接"
	$(C) $(CFLAGS) $(INCLUDE) -o $@ $^
	@echo "链接成功"

build/src/%.o: src/%.c
	@mkdir -p build/src
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译链接文件成功"

build/main.o : main.c
	@mkdir -p build
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译main.c文件成功"

# 测试目标
tests: $(Test_bin)
	@echo "构建测试成功"

# 调试频率统计程序
debug_freq: build/tests/debug_freq
	@echo "构建debug_freq成功"
	@echo "运行: ./build/tests/debug_freq"

# 分析大文件程序
analyze_large: build/tests/analyze_large
	@echo "构建analyze_large成功"
	@echo "运行: ./build/tests/analyze_large"

# 效率分析程序
efficiency_analysis: build/tests/efficiency_analysis
	@echo "构建efficiency_analysis成功"
	@echo "运行: ./build/tests/efficiency_analysis"

# 简单分析程序
simple_analysis: build/tests/simple_analysis
	@echo "构建simple_analysis成功"
	@echo "运行: ./build/tests/simple_analysis"

# 分析大文件total.txt
analyze_total: build/tests/analyze_total
	@echo "构建analyze_total成功"
	@echo "运行: ./build/tests/analyze_total"

# 调试字长表程序
debug_length_table: build/tests/debug_length_table
	@echo "构建debug_length_table成功"
	@echo "运行: ./build/tests/debug_length_table"

# 简化分析程序
simple_analysis: build/tests/simple_analysis
	@echo "构建simple_analysis成功"
	@echo "运行: ./build/tests/simple_analysis"

build/tests/%: build/tests/%.o $(Obj_files)
	@echo "正在链接测试程序 $@"
	$(C) $(Cflags) $(Include) -o $@ $^ -lm
	@echo "链接测试程序成功"

build/tests/%.o: tests/%.c
	@mkdir -p build/tests
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译测试文件成功"

# 清理
clean:
	rm -rf build
	rm -f $(Main)

.PHONY: all tests run_tests clean