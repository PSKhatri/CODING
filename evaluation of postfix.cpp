#include<bits/stdc++.h>
using namespace std;
int operation(int y,int x,char ch)
{
    int z;
    switch(ch)
    {
        case '+':
        {
           z=y+x;
           break;
        }
        case '-':
        {
            z=y-x;
            break;
        }
        case '*':
        {
            z=y*x;
            break;
        }
        case '/':
        {
            z=y/x;
            break;
        }
        case '^':

        {
            z=y^x;
            break;
        }
        case '%':
        {
            z=y%x;
            break;
        }
        return z;
    }
}
int main()
{
    int t;
    cin>>t;
    string s;
    int x,y,z;
    for(int j=0;j<t;j++)
    {
        cin>>s;
        stack<int> newStack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                newStack.push(s[i]-'0');
            }
            else
            {

                x=newStack.top();
                newStack.pop();
                y=newStack.top();
                newStack.pop();
                z=operation(y,x,s[i]);
                newStack.push(z);
            }
        }
        cout<<newStack.top()<<endl;
    }
}
