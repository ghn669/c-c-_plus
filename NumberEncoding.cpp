// 给你一个只包含数字的字符串 s，请计算它有多少种解码方式，规则如下：
// A → 1，B → 2，…，Z → 26
// 解码时，每个数字可以单独解码（1~9），或者和下一个数字组合解码（10~26）
// 例如：
// s = "12"：可以解码为 AB（1+2）或 L（12），共 2 种方式
// s = "226"：可以解码为 BZ、VF、BBF，共 3 种方式

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int mem[1000];
//递归法 i后面有多少种组合方法
int dfs(string s,int i)
{
    if(i==s.size()) return 1;
    int res;
    if(s[i]=='0') res = 0;
    else
    {
        res = dfs(s,i+1);
        if(i+1<s.size()&&((s[i]-'0')*10+s[i+1]-'0')<=26)
        {
            res += dfs(s,i+2);
        }
    }
    return res;
}
//记忆化搜索
int dp(string s,int i)
{
    if(i==s.size()) return 1;
    if(mem[i]) return mem[i];
    int res;
    if(s[i]=='0') res = 0;
    else
    {
        res = dfs(s,i+1);
        if(i+1<s.size()&&((s[i]-'0')*10+s[i+1]-'0')<=26)
        {
            res += dfs(s,i+2);
        }
    }
    mem[i]=res;
    return res;
}
//严重位置依赖dp + 空间规划
int dp1(string s)
{
    //dp[n]=1;
    int next = 1;
    //dp[n+1]不存在
    int nextnext = 0;
    for(int i=s.size()-1,cur;i>=0;i--)
    {
        
    }
    return next;
}
int main()
{

    return 0;
}