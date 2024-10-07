#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<typename T>
T add(T a,T b){
    return a+b;
}


int main()
{
    int a, b;
    double c, d;
    string s1, s2;

    cin >> a >> b;
    cin >> c >> d;
    cin >> s1 >> s2;

    cout << add(a, b) << endl;
    cout << fixed << setprecision(2) << add(c, d) << endl;
    cout << add(s1, s2) << endl;

    return 0;
}