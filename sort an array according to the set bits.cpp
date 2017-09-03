#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,x,p;
    for(int m=0;m<t;m++)
    {
     cin>>n;
     int a[n];
     vector<vector<int> >counts(32);
     for(int i=0;i<n;i++)
           {
             cin>>a[i];
             x=a[i];
             p=0;
             while(x!=0)
             {
                if((x&1)==1)
                    p++;
                x=x>>1;
             }
             counts[p].push_back(a[i]);
           }
           for(int j=31;j>=0;j--)
           {
               for(int k=0;k<counts[j].size();k++)
                cout<<counts[j][k]<<" ";
           }
           cout<<endl;
    }
    return 0;
}
