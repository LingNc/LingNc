#include <iostream>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class CRAFT{
protected:
    double speed;
public:
    CRAFT(double speed):speed(speed){
        cout<<"创建航行器(";
        print("速度",speed);
        cout<<')'<<endl;
    }
    virtual ~CRAFT(){
        cout<<"销毁航行器(";
        print("速度",speed);
        cout<<')'<<endl;
    }
    virtual void print(string str,double key){
        cout<<str<<": "<<key;
    }
    virtual void Show(){
        cout<<"航行(";
        print("速度",speed);
        cout<<')'<<endl;
    }
};
class PLANE:virtual public CRAFT{
protected:
    double width;
public:
    PLANE(double speed,double width):CRAFT(speed),width(width){
        cout<<"创建飞机(";
        print("翼展",width);
        cout<<')'<<endl;
    }
    ~PLANE(){
        cout<<"销毁飞机(";
        print("翼展",width);
        cout<<')'<<endl;
    }

    void Show(){
        cout<<"航行(";
        print("速度",speed);
        cout<<", ";
        print("翼展",width);
        cout<<')'<<endl;
    }
};
class SHIP:virtual public CRAFT{
protected:
    //吃水深度
    double depth;
public:
    SHIP(double speed,double depth):CRAFT(speed),depth(depth){
        cout<<"创建船(";
        print("吃水",depth);
        cout<<')'<<endl;
    }
    ~SHIP(){
        cout<<"销毁船(";
        print("吃水",depth);
        cout<<')'<<endl;
    }
    void Show(){
        cout<<"航行(";
        print("速度",speed);
        cout<<", ";
        print("吃水",depth);
        cout<<')'<<endl;
    }
};
class SEAPLANE:public PLANE,public SHIP{
public:
    SEAPLANE(double speed,double width,double depth):PLANE(speed,width),SHIP(speed,depth),CRAFT(speed){
        cout<<"创建水上飞机"<<endl;
    }
    ~SEAPLANE(){
        cout<<"销毁水上飞机"<<endl;
    }
    void Show(){
        cout<<"航行(速度: "<<speed<<", 翼展: "<<width<<", 吃水: "<<depth<<')'<<endl;
    }
};

int main(){
    double s,w,d;
    CRAFT *p;
    cin>>s>>w>>d;
    p=new SEAPLANE(s,w,d);
    p->Show();
    delete p;
    return 0;
}