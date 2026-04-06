#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100;
int n;
int mem[N];
//记忆化搜索
int dfs(int x)
{
    int sum;
    if(x<=0) return 0;
    if(x==1) return 1;
    if(x==2) return 1;
    if(mem[x]) return mem[x];
    sum = dfs(x-1)+dfs(x-2);
    mem[x]=sum;
    return sum;
}
//dp
int dp(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    int lastlast = 0,last = 1;
    for(int i=2,cur;i<=n;i++)
    {
        cur = lastlast+last;
        lastlast = last;
        last = cur;
    }
    return last;
}
int main()
{
    cin>>n;
    cout<<dfs(n)<<endl;
    return 0;
}
