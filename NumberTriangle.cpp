// 给定一个倒三角 / 正三角数字矩阵：
// plaintext
//       7
//     3   8
//   8   1   0
// 2   7   4   4
// 规则：
// 从顶部出发，走到最底层；
// 每一步只能走到下一行正下方 / 下一行右下方；
// 求经过所有数字之和的最大值
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000;
int n;
int arr[N][N];
int mem[N][N];
int f[N][N];
int dfs(int x,int y)
{
    if(mem[x][y]) return mem[x][y];
    int sum;
    if(x>n||y>x) sum=0;
    else sum = max(dfs(x+1,y),dfs(x+1,y+1))+arr[x][y];
    mem[x][y]=sum;
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>arr[i][j];
        }
    }
    int res = dfs(1,1);
    //递推
    // memset(f,0,sizeof(f));
    // for(int i=n;i>=1;i--)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         f[i][j]=max(f[i+1][j],f[i+1][j+1])+arr[i][j];
    //     }
    // }
    cout<<res<<endl;
    return 0;
}