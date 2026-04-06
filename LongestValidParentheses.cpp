#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp(string s)
{
    int* dp = new int[s.size()]();
    int res = 0;
    for(int i=1,pre;i<s.size();i++)
    {
        if(s[i]==')'){
            pre = i-dp[i-1]-1;
            if(pre>=0&&s[pre]=='(')
            {
                dp[i]=dp[i-1]+2+(pre>0?dp[pre-1]:0);
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}
int main()
{
    return 0;
}