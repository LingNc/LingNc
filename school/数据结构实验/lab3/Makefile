C = gcc
# 只能使用 gcc 编译器 使用了typeof
Cflags = -Wall -Wextra -std=gnu99 -g

Include = -I./include -I./ext/include

# 收集源文件
Src_files = $(wildcard src/*.c)
Ext_src_files = $(wildcard ext/src/*.c)
Obj_files = $(patsubst src/%.c, build/src/%.o, $(Src_files))
Ext_obj_files = $(patsubst ext/src/%.c, build/ext/src/%.o, $(Ext_src_files))

# 收集测试文件
Test_src = $(wildcard tests/*.c)
Test_obj = $(patsubst tests/%.c, build/tests/%.o, $(Test_src))
Test_bin = $(patsubst tests/%.c, tests/%, $(Test_src))

Main = main

all : $(Main)
	@echo "构建main成功,在 main"

$(Main): $(Ext_obj_files) $(Obj_files) build/main.o
	@echo "正在链接"
	$(C) $(Cflags) $(Include) -o $@ $^
	@echo "链接成功"

build/src/%.o: src/%.c ext/src/%.c
	@mkdir -p build/src
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译项目链接文件成功"

build/ext/src/%.o: ext/src/%.c
	@mkdir -p build/ext/src
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译扩展链接文件成功"

build/main.o : main.c
	@mkdir -p build
	$(C) $(Cflags) $(Include) -c $< -o $@
	@echo "编译main.c文件成功"

# 测试目标
tests: $(Test_bin)
	@echo "构建测试成功"

tests/%: build/tests/%.o $(Obj_files)
	@echo "正在链接测试程序 $@"
	$(C) $(Cflags) $(Include) -o $@ $^
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