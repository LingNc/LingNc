#include<vector>
#include<iostream>
template<typename T> void primap(std::vector<std::vector<T>> map){
    int n=map.size();
    int m=map[0].size();
    foee(i,0,n-1,j,0,m-1){
        printf("%-4d ",map[i][j]);
        if(j==m-1) putchar(endl);
    }
    putchar(endl);
}