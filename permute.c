#include<stdio.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int* arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void permute(int* arr,int n,int start)
{
    if(start==n){
        print(arr,n);
        return;
    }
    for(int i=start;i<n;i++){
        swap(arr+i,arr+start);
        permute(arr,n,start+1);
        swap(arr+i,arr+start);
    }
}
int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        arr[i] = i+1;
    }
    permute(arr,n,0);
    return 0;
}