#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

bool isLeapYear(int year){
    //四年一闰，百年不闰，四百年又闰
    if(year%400==0)
        return true;
    else if(year%100==0)
        return false;
    else  if(year%4==0)
        return true;
    else
        return false;
}

//请在此处定义Date类
int m[]={ 31,28,31,30,31,30,31,31,30,31,30,31 };
class Date{
    int year,month,day;
public:
    Date(int year,int month,int day):year(year),month(month),day(day){
        if(isLeapYear(year))
            m[1]=29;
        else
            m[1]=28;
    }
    Date nextDay(){
        Date temp(year,month,day);
        if(day==m[month-1]){
            if(month==12){
                temp.year++;
                temp.month=1;
                temp.day=1;
            }
            else{
                temp.month++;
                temp.day=1;
            }
        }
        else{
            temp.day++;
        }
        return temp;
    }
    Date prevDay(){
        Date temp(year,month,day);
        if(day==1){
            if(month==1){
                temp.year--;
                temp.month=12;
                temp.day=31;
            }
            else{
                temp.month--;
                temp.day=m[month-2];
            }
        }
        else{
            temp.day--;
        }
        return temp;
    }
    string toText(){
        string s=to_string(year)+'-'+to_string(month)+'-'+to_string(day);
        return s;
    }
};


int main(){
    int year=2000,month=1,day=1;
    cin>>year>>month>>day;
    Date d(year,month,day);
    cout<<"Date: "<<d.toText()<<", Next Day: "<<d.nextDay().toText()
        <<", Prev Day: "<<d.prevDay().toText();
    return 0;
}