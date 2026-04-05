#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    int n;
    cout<<"请输入需要打印的层数:";
    cin>>n;
    q.push(1);
    for(int i=1;i<=n;i++)
    {
        q.push(0);
        for(int j=1;j<=i;j++)
        {
            int val1 = q.front();
            q.pop();
            int val2 = q.front();
            int result = val1+val2;
            q.push(result);
            cout<<result<<" ";
        }
        cout<<endl;
    }
    return 0;
}