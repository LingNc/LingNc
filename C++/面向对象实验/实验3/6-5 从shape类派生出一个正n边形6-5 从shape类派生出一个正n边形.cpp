#include <iostream>
#include <cmath>
using namespace std;
/*
在一个正n边形（Regular Polygon）中，所有边的边长都相等，且所有角的度数相同（即这个多边形是等边、等角的）。请从下列的抽象类shape类扩展出一个正n边形类RegularPolygon,这个类将正n边形的边数n和边长s作为私有成员，类中包含初始化边数n和边长s的构造函数。

class shape {// 形状类
public:
 double getArea()  // 求面积
 {return -1;}
 double getPerimeter() // 求周长
 {return -1;}
};
计算正n边形的面积公式为： Area=n×a×a/(tan((180度/n))×4);

注意：需要将角度转换成弧度后再计算三角函数。π取3.1415926

函数接口定义：
类名：RegularPolygon
*/
class shape{// 形状类
public:
    double getArea()  // 求面积
    {
        return -1;
    }
    double getPerimeter() // 求周长
    {
        return -1;
    }
};
/* 请在这里填写答案 */
//Your code will be embed-ed here.
class RegularPolygon:public shape{
    int n;
    double s;
public:
    RegularPolygon(int n,double s):n(n),s(s){}
    double getArea(){
        return n*s*s/(tan(3.1415926/n)*4);
    }
    double getPerimeter(){
        return n*s;
    }
};

int main(){
    int n;
    double s;

    cin>>n>>s;
    RegularPolygon p(n,s);
    cout<<p.getArea()<<endl;

    cout<<p.getPerimeter()<<endl;

    return 0;
}