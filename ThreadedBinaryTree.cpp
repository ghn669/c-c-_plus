#include<iostream>
using namespace std;
typedef struct ThreadTree
{
    ThreadTree* left;
    ThreadTree* right;
    int val;
    int ltag,rtag;
    ThreadTree(int _val){
        val = _val;
        ltag = 0;
        rtag = 0;
        left = nullptr;
        right = nullptr;
    }
}ThreadTree;
ThreadTree* pre = nullptr;
void CreateTree(ThreadTree*& t)
{
    int val;
    cin>>val;
    if(val==-1)
    {
        t=nullptr;
        return;
    }
    t = new ThreadTree(val);
    CreateTree(t->left);
    CreateTree(t->right);
}
void InThread(ThreadTree* t)
{
    if(t)
    {
        InThread(t->left);
        if(t->left==nullptr)
        {
            t->ltag = 1;
            t->left = pre;
        }
        if(pre != nullptr&&pre->right==nullptr)
        {
            pre->rtag = 1;
            pre->right = t;
        }
        pre = t;
        InThread(t->right);
    }
}
void CreateInThread(ThreadTree*& t)
{
    pre = nullptr;
    if(t)
    {
        InThread(t);
        pre->right = nullptr;
        pre->rtag = 1;
    }
}
void InOrderTraverse(ThreadTree* t)
{
    ThreadTree* p = t;
    while(p)
    {
        while(p->ltag==0)
        {
            p=p->left;
        }
        cout<<p->val<<" ";
        while(p->right!=nullptr&&p->rtag==1)
        {
            p=p->right;
            cout<<p->val<<" ";
        }
        p = p->right;
    }
}
int main() {
    ThreadTree* T;
    cout << "请输入二叉树节点（-1为空，按先序输入，示例：1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1）：\n";
    CreateTree(T);
    CreateInThread(T);
    
    cout << "中序线索二叉树遍历结果：";
    InOrderTraverse(T);
    cout << endl;
    
    return 0;
}