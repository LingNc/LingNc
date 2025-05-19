#ifndef EXCEPTION_H
#define EXCEPTION_H

// 错误信号
enum Status{
    // 成功
    SUCCESS=1,
    // 警告
    WARRING,
    // 失败
    ERROR,
};
typedef enum Status Status;
typedef Status status;

// 信号转字符串
#define to_str(status) #status

// 状态退化函数，状态按照 success,warring,error 等级向下递减，从不会上升
status status_down(status *self,status new_status);

// 如果没有引入string库
#ifndef STRING_H
    typedef char *string;
    // 动态字符串拼接函数
    // 拼接字符串创建新的指针来存储
    string nstrcat(const string _str1,const string _str2);
    // 尽可能再源指针上进行拼接，返回新的指针或者源指针
    string strapp(string _dest,const string _str);
#endif

// 异常捕获
struct Exception{
    // 错误类型
    status status;
    // 错误信息
    string msg;
};
typedef struct Exception Exception;
typedef Exception *exception;

// 新建异常
Exception new_exception(status status,string msg);
// 异常的累积
Exception exception_pass(exception self,Exception e);
// 异常的捕获
Exception exception_catch(exception self,Exception e);
// 获取异常的状态
status exception_get(exception self);
// 异常降级
Exception exception_down(exception self,status new_status);
// 释放异常
status free_exception(exception self);


#endif //EXCEPTION_H