#include <iostream>
#include <string>
using namespace std;
//定义公共基类Person
class Person{
public:
    Person(string nam,char s,int a){
        name=nam;sex=s;age=a;
    }
protected:
    string name;
    char sex;
    int age;
};
//定义类Teacher
class Teacher:virtual public Person{
public:
    Teacher(string nam,char s,int a,string t):Person(nam,s,a){
        title=t;
    }
protected:
    string title;
};
//定义类Student
class Student:virtual public Person{
public:
    Student(string nam,char s,int a,float sco):
        Person(nam,s,a),score(sco){}
protected:
    float score;
};

/*这里添加派生类的定义*/
class Graduate:public Teacher,public Student{
    float wage;
    template<typename T>
    void print(string str,T key){
        cout<<str<<':'<<key<<endl;
    }
public:
    Graduate(string nam,char s,int a,string t,float sco,float w):
        Person(nam,s,a),
        Teacher(nam,s,a,t),
        Student(nam,s,a,sco),
        wage(w){}
    void show(){
        print("name",name);
        print("age",age);
        print("sex",sex);
        print("score",score);
        print("title",title);
        print("wages",wage);
    }
};

int main(){
    Graduate grad1("Wang-li",'f',24,"assistant",89.5,1234.5);
    grad1.show();
    return 0;
}