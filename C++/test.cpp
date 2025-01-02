#include<iostream>
using namespace std;
class A {
public:
    A(int i) {    x = i;  }
    void dispa() {
        cout << x << ',';
    }
private:
    int x;
};
class B: public A {
public:
    B(int i) : A(i + 10) {
        x = i;
    }
    void dispb() {
        dispa();
        cout << x << endl;
    }
private:
    int x;
};
int main() {
    B b(2);
    b.dispb();
    return 0;
}