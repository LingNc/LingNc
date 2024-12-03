#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Animal{
protected:
    int m_nWeightBase;
protected:
    int m_nAgeBase;
public:
    void set_weight(int nWeight){
        m_nWeightBase=nWeight;
    }
    void set_age(int nAge){
        m_nAgeBase=nAge;
    }
    int get_weight(){
        return m_nWeightBase;
    }
    int get_age(){
        return m_nAgeBase;
    }
};
class Cat:public Animal{
    string m_strName;
public:
    Cat(string strName):m_strName(strName){}
    void set_print_age(){
        set_age(5);
        cout<<m_strName<<", age = "<<get_age()<<endl;
    }
    void set_print_weight(){
        set_weight(6);
        cout<<m_strName<<", weight = "<<get_weight();
    }
};
int main(){
    Cat cat("Persian");     //定义派生类对象cat
    cat.set_print_age();
    cat.set_print_weight(); //派生类对象调用自己的公有函数
    return 0;
}
