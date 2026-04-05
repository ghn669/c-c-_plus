//表达式求值
#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
#define MAX_SIZE 100
typedef struct
{
    char* c;
    int top;
}op_stack;
typedef struct
{
    double* c;
    int top;
}db_stack;
int op_init(op_stack& op)
{
    op.c = new char[MAX_SIZE];
    if(op.c==nullptr) return 0;
    op.top=-1;
    return 1;
}
int db_init(db_stack& db)
{
    db.c = new double[MAX_SIZE];
    if(db.c==nullptr) return 0;
    db.top=-1;
    return 1;
}
int op_full(op_stack op)
{
    return op.top==MAX_SIZE-1;
}
int db_full(db_stack db)
{
    return db.top==MAX_SIZE-1;
}
int op_empty(op_stack op)
{
    return op.top==-1;
}
int db_empty(db_stack db)
{
    return db.top==-1;
}
int op_push(op_stack& op,char val)
{
    if(op_full(op))
    {
        cout<<"op_stack is full!"<<endl;
        return 0;
    }
    op.c[++op.top]=val;
    return 1;
}
int db_push(db_stack& db,double val)
{
    if(db_full(db))
    {
        cout<<"db_stack is full!"<<endl;
        return 0;
    }
    db.c[++db.top]=val;
    return 1;
}
char op_pop(op_stack& op)
{
    if(op_empty(op))
    {
        cout<<"op_stack is empty!"<<endl;
        return '0';
    }
    char e=op.c[op.top--];
    return e;
}
double db_pop(db_stack& db)
{
    if(db_empty(db))
    {
        cout<<"db_stack is empty!"<<endl;
        return 0;
    }
    double e=db.c[db.top--];
    return e;
}
char op_top(op_stack op)
{
    return op.c[op.top];
}
int priority(char op)
{
    switch(op)
    {
        case '+':case '-': return 1;
        case '*':case '/': return 2;
        case '^':return 3;
    }
    return -1;
}
char compare(char in,char out)
{
    if(in =='(') return '<';
    int p1=priority(in);
    int p2=priority(out);
    if(p1 > p2) return '>';
    else if(p1 < p2) return '<';
    else {
        if(in == '^') return '<'; 
        else return '>'; 
    }
}
int is_number(char c)
{
    return (c>='0'&&c<='9')||c=='.';
}
double operate(double a,char ope,double b)
{
    switch(ope)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': 
            if(a == (int)a && b == (int)b) 
            {
                return (int)a / (int)b;
            }
            return a/b;
        case '^': return pow(a,b);
    }
    return -1;
}
double my_atof(char* str)
{
    char* p = str;
    double sum=0;
    while(*p>='0'&&*p<='9')
    {
        sum = sum*10 + (*p-'0');
        p++;
    }
    if(*p=='.')
    {
        p++;
        double n = 10.0;
        while(*p!='\0')
        {
            sum+=double((*p-'0')/n);
            n*=10;
            p++;
        }
    }
    return sum;
}
void deal_str(char* str,char& a,double& val)
{
    char* p = str;
    while(*p!=',')
    {
        p++;
        if(*p=='\0') return; 
    }
    p++;
    a=*p++;
    p++;
    char temp[20];
    int idx = 0;
    while(*p!='\0')
    {
        temp[idx++]=*p;
        p++;
    }
    temp[idx]='\0';
    val=my_atof(temp);
}
int main()
{
    op_stack op;
    db_stack db;
    op_init(op);
    db_init(db);
    char str[MAX_SIZE];
    cin>>str;
    char a;
    double val;
    deal_str(str,a,val);
    char* p = str;
    while(*p!='\0'&&*p!=',')
    {
        if(*p==a)
        {
            db_push(db,val);
            p++;
            continue;
        }
        if(is_number(*p))
        {
            char temp[20];
            int idx = 0;
            while(is_number(*p))
            {
                temp[idx++]=*p++;
            }
            temp[idx] = '\0';
            double num = my_atof(temp);
            db_push(db,num);
            continue;   //这里刚开始没加continue!
        }
        if(*p=='(')
        {
            op_push(op,*p);
            p++;
        }
        else if(*p==')')
        {
            while(!op_empty(op)&&op_top(op)!='(')
            {
                char ope;
                double a,b;
                ope=op_pop(op);
                b=db_pop(db);
                a=db_pop(db);
                db_push(db,operate(a,ope,b));
            }
            op_pop(op);
            p++;
        }
        else
        {
            while(!op_empty(op)&&compare(op_top(op),*p)=='>')
            {
                char ope;
                double a,b;
                ope=op_pop(op);
                b=db_pop(db);
                a=db_pop(db);
                db_push(db,operate(a,ope,b));
            }
            op_push(op,*p);
            p++;
        }
    }
    while(!op_empty(op))
    {
        char ope;
        double a,b;
        ope=op_pop(op);
        b=db_pop(db);
        a=db_pop(db);
        db_push(db,operate(a,ope,b));
    }
    double answer = db_pop(db);
    cout<<answer<<endl;
    delete[] op.c;
    delete[] db.c;
    return 0;
}