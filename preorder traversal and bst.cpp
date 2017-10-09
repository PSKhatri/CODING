#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int r=0;r<t;r++)
    {
        stack<int> newStack;
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int root=INT_MIN;
        newStack.push(a[0]);
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>root)
            {
                if(!newStack.empty() && a[i]<newStack.top())
                    newStack.push(a[i]);
                else
                {
                    while(!newStack.empty() && a[i]>newStack.top())
                    {
                        root=newStack.top();
                        newStack.pop();
                    }
                    newStack.push(a[i]);
                }
            }
            else
            {
                cout<<"0"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"1"<<endl;
    }
    return 0;
}
