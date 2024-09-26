#include<iostream>

using namespace std;

//复数
typedef struct Complex{
    double real,imag;

    Complex operator+(const Complex &c){
        return { real+c.real,imag+c.imag };
    }
    Complex operator-(const Complex &c){
        return { real-c.real,imag-c.imag };
    }
    Complex operator*(const Complex &c){
        return { real*c.real-imag*c.imag,real*c.imag+imag*c.real };
    }
    Complex operator/(const Complex &c){
        double denominator=c.real*c.real+c.imag*c.imag;
        return { (real*c.real+imag*c.imag)/denominator,(imag*c.real-real*c.imag)/denominator };
    }
}Complex;

int main(){
    double real,imag;
    cin>>real>>imag;
    Complex c1={real,imag};
    cin>>real>>imag;
    Complex c2={ real,imag };
    cout<<(c1+c2).real<<" "<<(c1+c2).imag<<endl;

    return 0;
}