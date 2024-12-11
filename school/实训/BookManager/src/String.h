#ifndef _string_lib
#define _string_lib

#include <string.h>
#include <stddef.h>

// String 结构体的前向声明
typedef struct String String;
typedef String *string;

// String 结构体的定义
struct String {
    // 成员变量
    // 指向字符串数据的指针
    char *str;
    // 字符串的长度
    size_t length;
    // 表示无位置的常量
    size_t npos;

    // 获取 C 风格字符串函数
    // 返回 char* 指向该字符串地址
    char *(*c_str)(string);

    // 追加字符
    // 返回追加后的字符串
    string (*append_char)(string, char);

    // 追加 C 风格字符串
    // 返回追加后的字符串
    string (*append_cstr)(string, const char*);

    // 追加 String 对象
    // 返回追加后的字符串
    string (*append_string)(string, string);

    // 插入字符
    // 返回插入后的字符串
    string (*insert_char)(string, size_t, char);

    // 插入 C 风格字符串
    // 返回插入后的字符串
    string (*insert_cstr)(string, size_t, const char*);

    // 插入 String 对象
    // 返回插入后的字符串
    string (*insert_string)(string, size_t, string);

    // 查找字符
    // 返回字符位置，未找到返回 npos
    size_t (*find_char)(string, size_t, char);

    // 查找 C 风格字符串
    // 返回字符串位置，未找到返回 npos
    size_t (*find_cstr)(string, size_t, const char *);

    // 查找 String 对象
    // 返回字符串位置，未找到返回 npos
    size_t (*find_string)(string, size_t, string);

    // 获取字符串的大小
    // 返回字符串的大小
    size_t (*size)(string);

    // 获取字符串的长度
    // 返回字符串的长度
    size_t (*length_func)(string);

    // 获取指定位置的字符
    // 返回指定位置的字符
    char (*at)(string, size_t);

    // 清空字符串
    // 无返回值
    void (*clear)(string);

    // 检查字符串是否为空
    // 返回 1 表示为空，0 表示不为空
    int (*empty)(string);

    // 获取字符串的原始数据
    // 返回 const char* 指向字符串数据
    const char *(*data)(string);
};

// 初始化 String 对象
// 无返回值
void string_init(string this);

// 销毁 String 对象
// 无返回值
void string_destroy(string this);

#endif
