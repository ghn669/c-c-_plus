//丑数：因子只有2，3，5
//1是第一个丑数
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//三指针(太优雅了！)
int UglyNumber(int n)
{
    int *dp = new int[n+1];
    dp[1] = 1;
    for(int i=2,i1=1,i2=1,i3=1;i<=n;i++)
    {
        int a1 = dp[i1]*2;
        int a2 = dp[i2]*3;
        int a3 = dp[i3]*5;
        int res = min(min(a1,a2),a3);
        if(res==a1) i1++;
        if(res==a2) i2++;
        if(res==a3) i3++;
        dp[i]=res;
    }
    return dp[n];
}
int main()
{
    
    return 0;
}