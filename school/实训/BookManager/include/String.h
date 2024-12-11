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
    char *str;         // 指向字符串数据的指针
    size_t length;     // 字符串的长度
    size_t npos;       // 表示无位置的常量

    // c_str 函数
    char *(*c_str)(string);  // 获取 C 风格字符串的函数

    // Append 函数，追加字符或字符串
    string (*append_char)(string, char);
    string (*append_cstr)(string, const char*);
    string (*append_string)(string, string);

    // Insert 函数，插入字符或字符串
    string (*insert_char)(string, size_t, char);
    string (*insert_cstr)(string, size_t, const char*);
    string (*insert_string)(string, size_t, string);

    // Find 函数，查找字符或字符串
    size_t (*find_char)(string, size_t, char);
    size_t (*find_cstr)(string, size_t, const char *);
    size_t (*find_string)(string, size_t, string);

    size_t (*size)(string);        // 获取字符串的大小
    size_t (*length_func)(string); // 获取字符串的长度

    char (*at)(string, size_t);    // 获取指定位置的字符
    void (*clear)(string);         // 清空字符串
    int (*empty)(string);          // 检查字符串是否为空
    char *(*data)(string);         // 获取字符串的原始数据
};

// 初始化和销毁 String 对象的函数
void string_init(string this);
void string_destroy(string this);

#endif
