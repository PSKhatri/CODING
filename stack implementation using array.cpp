#include<bits/stdc++.h>
#define STACKSIZE 100
using namespace std;
int top=-1;
void push(int *s,int x)
{
    if(top==STACKSIZE)
        {
            cout<<"Stack Full"<<endl;
            return;
        }
    top=top+1;
    s[top]=x;
}
int pop(int *s)
{
    if(top==-1)
    {
        cout<<"Stack empty"<<endl;
        return -1;
    }
    int y=s[top];
    top=top-1;
    return y;
}
int peek(int *s)
{
    return s[top];
}
bool isEmpty(int *a)
{
    if(top==-1)
        return true;
    else
        return false;
}
void display(int *s)
{
    if(top==-1)
    {
        cout<<"Stack empty"<<endl;
    }
    else
        {
    for(int i=0;i<=top;i++)
        cout<<s[i]<<" ";
    cout<<endl;
        }
}
int main()
{
    int s[STACKSIZE];
    push(s,50);
    display(s);
    push(s,24);
    display(s);
    int x=pop(s);
    cout<<x<<endl;
    display(s);
    push(s,30);
    display(s);
    int y=peek(s);
    cout<<y<<endl;
    bool m=isEmpty(s);
    cout<<m<<endl;
    return 0;
}
