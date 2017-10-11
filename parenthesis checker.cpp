#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    for(int m=0;m<t;m++)
    {
        cin>>s;
        stack<char> newStack;
        for(int i=0;i<s.size();i++)
        {

            if(!newStack.empty() && s[i]=='}' && newStack.top()=='{')
                newStack.pop();
            else if(!newStack.empty() && s[i]==')' && newStack.top()=='(')
                newStack.pop();
            else if(!newStack.empty() && s[i]==']' && newStack.top()=='[')
                newStack.pop();
            else
                newStack.push(s[i]);
        }
        if(newStack.size()>0)
            cout<<"not balanced"<<endl;
        else
            cout<<"balanced"<<endl;
    }
    return 0;
}
