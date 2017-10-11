#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    for(int m=0;m<t;m++)
    {
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        stack<string> newStack;
        newStack.push(s[0]);
        for(int i=1;i<n;i++)
        {
            if(!newStack.empty() && s[i]==newStack.top() )
                newStack.pop();
            else
                newStack.push(s[i]);
        }
        cout<<newStack.size()<<endl;
    }
    return 0;
}
