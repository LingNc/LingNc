#include<iostream>
#include"manager.h"
#define foe(i,a,b) for(int i=(a);i<=(b);i++)

int Manager::scoresAvg(Student &s){
    int sum=0;
    foe(i,0,2){
        sum+=s.scores[i];
    }
    return sum/3;
}
#undef foe(i,a,b)