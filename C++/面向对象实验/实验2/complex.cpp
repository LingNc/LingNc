#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//复数类
class Complex{
    double real,image; //复数的实部和虚部
public:
    //构造函数
    Complex(double _real,double _image):real(_real),image(_image){}
    //使用在操作类内和类外两种方法实现类的以下运算符重载函数
    //1、运算符输入>>和输出<<，并能够实现连续运算
    friend istream &operator>>(istream &in,Complex &com){
        return in>>com.real>>com.image;
    }
    friend ostream &operator<<(ostream &out,const Complex &com){
        double image=abs(com.image);
        return (com.real
            ?((image!=0)
                ?((image==1)
                    ?out<<com.real<<(com.image<0
                        ?"-i"
                        :"+i")
                    :(out<<com.real<<(com.image<0
                        ?'-'
                        :'+')
                        <<image<<'i'))
                :out)
            :((image!=0)
                ?((image==1)
                    ?out<<(com.image<0
                        ?"-i"
                        :"i")
                    :(out<<(com.image<0
                        ?"-"
                        :"")
                        <<image<<'i'))
                :out))
            <<endl;
    }
    //2、运算符乘法*，并能够实现连续运算
    friend Complex operator*(const Complex &a,const Complex &b){
        return Complex(a.real*b.real-a.image*b.image,a.real*b.image+a.image*b.real);
    }
    friend Complex operator*(const double &A,const Complex &b){
        return Complex(A,0.0)*b;
    }
    friend Complex operator*(const Complex &a,const double &B){
        return a*Complex(B,0.0);
    }
    //3、运算符下标[]，下标值为0时返回实部、为1时返回虚部
    double operator[](int x){
        return (x)?image:real;
    }
    //4、运算符前置++和后置++，对实部加1
    Complex &operator++(){
        real++;
        return *this;
    }
    Complex operator++(int){
        Complex com=*this;
        real++;
        return com;
    }
    //5、运算符强制类型转换()，把浮点型数强制转换为实部为0虚部为此数的复数
    Complex(double _image=0.0):real(0.0),image(_image){}
    operator Complex(){
        return Complex(0.0,real);
    }
    //6、运算符加法+
    friend Complex operator+(const Complex &a,const Complex &b){
        return Complex(a.real+b.real,a.image+b.image);
    }
    friend Complex operator+(const double &A,const Complex &b){
        return Complex(A,0.0)+b;
    }
    friend Complex operator+(const Complex &a,const double &B){
        return a+Complex(B,0.0);
    }
};

int main(){
    Complex c1(2.0,3.5),c2(5,8.5),c3,c4;
    cin>>c3>>c4;
    cout<<c2++*c3<<c4;
    cout<<++(Complex)c2[0];
    cout<<c1+c3+4.7;
    cout<<Complex(0.0,1);
}
