#include<bits/stdc++.h>
using namespace std;
int temp1;
int partition(int *a,int i,int j,int pivot)
{
    temp1=a[pivot];
    a[pivot]=a[j];
    a[j]=temp1;
    int x=a[j];
    int p=i-1;
    for(int q=i;q<j;q++)
    {
        if(a[q]<=x)
        {
            p++;
            temp1=a[p];
            a[p]=a[q];
            a[q]=temp1;
        }
    }
    temp1=a[p+1];
    a[p+1]=a[j];
    a[j]=temp1;
    return (p+1);
}
int partition1(vector<pair<int,int> >& a,int i,int j,int pivot)
{
    pair<int,int>temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    pair<int,int>x1=a[j];
    int p=i-1;
    for(int q=i;q<j;q++)
    {
        if(a[q].first<=x1.first)
        {
            p++;
            temp=a[p];
            a[p]=a[q];
            a[q]=temp;
        }
    }
    temp=a[p+1];
    a[p+1]=a[j];
    a[j]=temp;
    return (p+1);
}
int rFindRank(int *a,int i,int j,int r)
{
    if(i==j) return i;
    int pivot=i+rand()%(j-i+1);
    int k=partition(a,i,j,pivot);
    if(r==(j-k+1))
        return k;
    else if(r<(j-k+1))
        rFindRank(a,k+1,j,r);
    else
        rFindRank(a,i,k-1,r-(j-k+1));
}
int rFindRank1(vector<pair<int,int> >& a,int i,int j,int r)
{
    if(i==j) return i;
    int pivot=i+rand()%(j-i+1);
    int k=partition1(a,i,j,pivot);
    if(r==(k-i+1))
        return k;
    else if(r<(k-i+1))
        rFindRank1(a,i,k-1,r);
    else
        rFindRank1(a,k+1,j,r-(k-i+1));
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
       {
         cin>>a[i];
       }
    int k;
    cin>>k;
    int val=rFindRank(a,0,n-1,n/2);
    vector<pair<int,int> > d;
    for(int i=0;i<n;i++)
    {
       d.push_back(make_pair(abs(a[i]-a[val]),a[i]));
    }

    int val1=rFindRank1(d,0,d.size()-1,k);
    for(int i=0;i<=val1;i++)
        cout<<d[i].second<<" ";
    return 0;
}
