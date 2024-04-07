#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
 
class Solution {
    void dfs(vector<string>& ans, string cur, int left, int right, int n) {
        if (left == n && right == n) {//在左边和右边剩余的括号数都等于 n的时候结算。
            ans.push_back(cur);
            return;
        }
        if(left < right){//右边剩余可以使用的括号数量一定得在严格小于左边剩余的数量的时候，才可以产生分支
            return ;//直接返回，剪支
        }
        if (left< n) {
            dfs(ans, cur+'(', left + 1, right, n);//左括号都有小于n个，产生分支
        }
        if (right < n) {
            dfs(ans, cur+')', left, right + 1, n);//右括号都有小于n个，产生分支
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        // 特判
        if (n == 0) {
            return result;
        }
        dfs(result, current, 0, 0, n);
        return result;
    }
};

 
int main()
{
	int n = 8;
    vector<string>res;
    Solution s;
    res = s.generateParenthesis(n);
    for(string c:res){
        cout << c << " ";
    }
    cout<<res.size()<<endl;
	return 0;
}
