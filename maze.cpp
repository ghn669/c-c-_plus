#include<iostream>
using namespace std;
#define len 5
#define width 5
#define dir 4
int dx[dir]={0,0,-1,1};
int dy[dir]={1,-1,0,0};

int maze[len][width] =
{
    {1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1}
};

bool visited[len][width]={false};
bool findway(int x,int y)
{
    if(x<0||x>=len||y<0||y>=width)
    {
        return false;
    }
    if(maze[x][y]==0)
    {
        return false;
    }
    if(visited[x][y]==true)
    {
        return false;
    }
    visited[x][y] = true;
    if(x==len-1&&y==len-1)
    {
        cout<<"("<<x<<","<<y<<")";
        return true;
    }
    for(int i=0;i<dir;i++)
    {
        int new_x = x+ dx[i];
        int new_y = y+ dy[i];
        if(findway(new_x,new_y))
        {
            cout<<"("<<x<<","<<y<<")";
            return true;
        }
    }
    return false;
}
int main()
{
    findway(0,0);
    return 0;
}
