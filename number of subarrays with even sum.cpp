#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n,count,count1,count2,total;
    for(int m=0;m<t;m++)
    {
        count=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]=a[i]%2;
            if(a[i]%2==0)
                count++;
        }
        for(int i=1;i<n;i++)
        {
            a[i]=(a[i]+a[i-1])%2;
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                count1++;
            else count2++;
        }

        total=count1+ ((count1*(count1-1))/2)+((count2*(count2-1))/2);
        cout<<total<<endl;
    }
    return 0;
}
