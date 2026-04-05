#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000;
int n,m;
int v[N],w[N];
int mem[N][N];
int dp[N];
//暴力dfs
int dfs(int x,int spV)
{
    if(x>n) return 0;
    else if(spV<v[x])
    {
        return dfs(x+1,spV);
    }
    else if(spV>=v[x])
    {
        return max(dfs(x+1,spV),dfs(x+1,spV-v[x])+w[x]);
    }
}
//记忆化搜索
int mem_dfs(int x,int spV)
{
    if(x>n) return 0;
    if(mem[x][spV]) return mem[x][spV];
    int res;
    if(spV<v[x]) res = mem_dfs(x+1,spV);
    else if(spV>=v[x]) res = max(mem_dfs(x+1,spV),mem_dfs(x+1,spV-v[x])+w[x]);
    mem[x][spV] = res;
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    //一维dp
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    return 0;
}