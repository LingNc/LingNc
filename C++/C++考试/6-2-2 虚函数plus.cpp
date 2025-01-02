#include <iostream>
#include <string.h>
using namespace std;
class Animal{
    int speed;
    float jpheight;
    char food[21];         //长度不超过十个汉字，这里可以使用数组，不必用指针
public:
    Animal(int s, float h, char f[]=""){
        speed = s; jpheight = h;
        strcpy(food,f);
    }

    virtual void Show()=0;
    void Set(int s, float h, char f[]=""){
        speed = s; jpheight = h;
        strcpy(food,f);
    }
    friend ostream& operator<<(ostream& o, Animal& a);
};
ostream& operator<<(ostream& o, Animal& a){
    o<<a.speed<<" "<<a.jpheight<<" "<<a.food;
    return o;
}
/* 请在这里填写答案 */
class Cat:public Animal{
    int night;
public:
    Cat():Animal(0,0){}
    void Set(){
        int s; float h; char f[21];
        cin>>s>>h>>f>>night;
        Animal::Set(s,h,f);
    }
    void Show(){
        cout<<*this<<' '<<night<<endl;
    }
};

class Dog:public Animal{
    int weight;
public:
    Dog(int s, float h, char f[], int w):Animal(s,h,f){
        weight = w;
    }
    void Show(){
        cout<<*this<<' '<<weight<<endl;
    }
};

void ShowAnimal(Animal &a){
    a.Show();
}

int main(){
    Cat mao;                            //定义对象mao
    mao.Set();                            //输入mao的参数
    Dog gou(8, 1.3, "筒子骨", 30);        //定义对象狗并初始化

    ShowAnimal(mao);
    ShowAnimal(gou);
}