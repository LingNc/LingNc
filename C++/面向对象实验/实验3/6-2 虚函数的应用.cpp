/*
6-2 虚函数的应用
分数 15
作者 李廷元
单位 中国民用航空飞行学院
补充下列代码，使得程序的输出为：

A:3

A:15

B:5

3

15

5
输入样例：
None
输出样例：
A:3
A:15
B:5
3
15
5
*/

#include <iostream>
using namespace std;
class CMyClassA {
    int val;
public:
    CMyClassA(int);
    void virtual print();
};
CMyClassA::CMyClassA(int arg) {
    val = arg;
    printf("A:%d\n", val);
}
void CMyClassA::print() {
    printf("%d\n", val);
    return;
}

/* 在这里填写代码 */
class CMyClassB: public CMyClassA{
protected:
    int val2;
public:
    CMyClassB(int arg):CMyClassA(15),val2(arg){
        printf("B:%d\n",arg);
    }
    void print(){
        printf("%d\n",val2);
    }
};


int main(int argc, char** argv) {
    CMyClassA a(3), *ptr;
    CMyClassB b(5);
    ptr = &a;
    ptr->print();
    a = b;
    a.print();
    ptr = &b;
    ptr->print();
    return 0;
}