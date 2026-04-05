#include<iostream>
using namespace std;
const int N=50;
int n;
int mem[N]={0};
//dfs算法
int dfs(int x)
{
    if(x==1) return 1;
    else if(x==2) return 2;
    else return dfs(x-1)+dfs(x-2);
}
//记忆化搜索=dfs+记录答案
int mem_dfs(int x)
{
    if(mem[x]) return mem[x];
    int sum = 0;
    if(x==1) sum = 1;
    else if(x==2) sum = 2;
    else sum = mem_dfs(x-1)+mem_dfs(x-2);
    mem[x]=sum;
    return sum;
}   
int main()
{
    cin>>n;
    int res1 = mem_dfs(n);
    int res2 = dfs(n);
    cout<<res1<<' '<<res2<<endl;
    return 0;
}
