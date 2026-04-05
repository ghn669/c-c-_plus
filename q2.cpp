//N皇后问题
#include<stdio.h>
#define n 8
int arr[n][n]={0};
int count = 0;
int line(int y)
{
    for(int i=0;i<n;i++)
    {
        if(arr[y][i]==1)
        {
            return 0;
        }
    }
    return 1;
}
int column(int x)
{
    for(int j=0;j<n;j++)
    {
        if(arr[j][x]==1)
        {
            return 0;
        }
    }
    return 1;
}
int in_range(int x,int y)
{
    return x>=0&&y>=0&&x<n&&y<n;
}
int diagnol(int x,int y)
{
    int i,j;
    for(i=x,j=y;in_range(i,j);i++,j--)
    {
        if(arr[j][i]==1) return 0;
    }
    for(i=x,j=y;in_range(i,j);i--,j++)
    {
        if(arr[j][i]==1) return 0;
    }
    for(i=x,j=y;in_range(i,j);i++,j++)
    {
        if(arr[j][i]==1) return 0;
    }
    for(i=x,j=y;in_range(i,j);i--,j--)
    {
        if(arr[j][i]==1) return 0;
    }
    return 1;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                printf("Q ");
            }
            else printf(". ");
        }
        printf("\n");
    }
}
void func(int y)
{
    if(y==n)
    {
        count++;
        print();
        printf("-------------------------------------\n");
        return;
    }
    for(int x=0;x<n;x++)
    {
        if(arr[y][x]==1||(line(y)&&column(x)&&diagnol(x,y)))
        {
            if(arr[y][x]==1)
            {
                func(y+1);
            }
            else
            {
                arr[y][x]=1;
                func(y+1);
                arr[y][x]=0;
            }
        }
    }
}
int main()
{
    // arr[1][1]=1;
    func(0);
    printf("共有%d种情况",count);
    return 0;
}