#include<iostream>
using namespace std;
int m = 0;
void move(char A,int n,char C)
{
    cout << ++m <<","<<n<<","<<A<<","<<C<<endl;
}
void hanoi(int n,char A,char B,char C)
{
    if(n==1) move(A,1,C);
    else
    {
        hanoi(n-1,A,C,B);
        move(A,n,C);
        hanoi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    cin >> n;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    hanoi(n,A,B,C);
    return 0;
}
