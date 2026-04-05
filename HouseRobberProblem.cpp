// 大盗阿福要去抢劫一排房子，每个房子里有价值为 ai​ 的财物，且不能同时抢劫相邻的两个房子。求他能抢到的最大总价值。
// 输入：数组 a[1..n]，表示每个房子的价值
// 输出：最大不相邻子序列和
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000;
int a[N];
int mem[N];
int f[N];
int n;
//递归法dfs+记忆化
int dfs(int x)
{
    if(mem[x]) return mem[x];
    int sum;
    if(x>n) sum = 0;
    else sum = max(dfs(x+1),dfs(x+2)+a[x]);
    mem[x]=sum;
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    // int res = dfs(1);
    // cout<<res<<endl;

    //迭代递推方法
    //f[i]为从第i个房子到最后一个房子所能赚到的最大值
    memset(f,0,sizeof(f));
    for(int i=n;i>=1;i--)
    {
        f[i]=max(f[i+1],f[i+2]+a[i]);
    }
    cout<<f[1]<<endl;
    return 0;
}