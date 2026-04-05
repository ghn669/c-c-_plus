#include<iostream>
using namespace std;
#define ElemType char
#define OVERFLOW -1
#define OK 1
typedef struct stack
{
    ElemType c;
    stack* next;
}stack;
stack* init()
{
    stack* s = new stack;
    s->next = nullptr;
    return s;
}
bool empty(stack* s)
{
    return s->next == NULL;
}
bool is_number(ElemType c)
{
    if(c>='0'&&c<='9')
    {
        return true;
    }
    return false;
}
int push(stack* s,ElemType c)
{
    stack* temp = new stack;
    if(temp==nullptr)
    {
        return OVERFLOW;
    }
    temp->c = c;
    temp->next = s->next;
    s->next = temp;
    return OK;
}
ElemType pop(stack* s)
{
    if(empty(s))
    {
        cout<<"栈空，无法出栈"<<endl;
    }
    ElemType c = s->next->c;
    stack* temp = s->next;
    s->next = s->next->next;
    delete temp;
    return c;
}
int postfix(stack* s,ElemType* str)
{
    ElemType* p = str;
    while(*p!='\0')
    {
        if(is_number(*p))
        {
            push(s,*p);
        }
        else
        {
            int a1 = pop(s)-'0';
            int a2 = pop(s)-'0';
            switch(*p)
            {
                case '+':
                    push(s,ElemType(a2+a1+'0'));
                    break;
                case '-':
                    push(s,ElemType(a2-a1+'0'));
                    break;
                case '*':
                    push(s,ElemType(a2*a1+'0'));
                    break;
                case '/':
                    if(a1==0)
                    {
                        cout<<"表达式错误!零不能做除数!"<<endl;
                    }
                    push(s,ElemType(a2/a1+'0'));
                    break;
            }
        }
        p++;
    }
    return int(pop(s)-'0');
}
int main()
{
    stack* s = init();
    ElemType* str = "952+4*-";
    int a = postfix(s,str);
    cout<<a<<endl;
    return 0;
}