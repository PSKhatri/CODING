#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int,int> > newStack;
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
   newStack.push(make_pair(a[0],0));
    for(int i=1;i<n;i++)
    {
        if(!newStack.empty() && newStack.top().first>a[i])
        {
            newStack.push(make_pair(a[i],i));
        }
        else
        {
        while(!newStack.empty() && newStack.top().first<a[i])
        {
            b[newStack.top().second]=a[i];
            newStack.pop();
        }
        newStack.push(make_pair(a[i],i));
        }
    }
    while(!newStack.empty())
    {
         b[newStack.top().second]=-1;
        newStack.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}
