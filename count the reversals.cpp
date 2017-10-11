#include<bits/stdc++.h>.
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    int count;
    for(int m=0;m<t;m++)
    {
        count=0;
        cin>>s;
        if(s.size()%2==0)
        {
            stack<char> newStack;
        for(int i=0;i<s.size();i++)
        {
            if(newStack.empty() && s[i]=='}')
            {
               count++;
               newStack.push('{');
            }
            else if(newStack.empty() && s[i]=='{')
                newStack.push('{');
            else if(s[i]=='{')
                newStack.push('{');
            else if(s[i]=='}')
            {
                if(!newStack.empty() && newStack.top()=='{')
                    newStack.pop();
                else if(newStack.empty())
                {
                  count++;
                  newStack.push('{');

                }
                else if(!newStack.empty() && newStack.top()!='{')
                    {
                        newStack.push('}');
                    }
            }
        }
        count=count+ newStack.size()/2;
        cout<<count<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}
