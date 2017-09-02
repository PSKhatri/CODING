//gives the r th smallest element int the array
#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int i,int j,int pivot)
{
    int temp1=a[pivot];
    a[pivot]=a[j];
    a[j]=temp1;
    int x=a[j];
    int p=i-1;
    for(int q=i;q<j;q++)
    {
        if(a[q]<=x)
        {
            p++;
            int temp2=a[p];
            a[p]=a[q];
            a[q]=temp2;
        }
    }
    int temp3=a[p+1];
    a[p+1]=a[j];
    a[j]=temp3;
    return (p+1);
}
int rFindRank(int *a,int i,int j,int r)
{
    if(i==j) return a[i];
    int pivot=i+rand()%(j-i+1);
    int k=partition(a,i,j,pivot);
    if(r==(k-i+1))
    return a[k];
    else if(r<(k-i+1))
        rFindRank(a,i,k-1,r);
    else
        rFindRank(a,k+1,j,r-(k-i+1));
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
    int t;
    cin>>t;
    int r;
    for(int m=0;m<t;m++)
    {
        cin>>r;
        int val=rFindRank(a,0,n-1,r);
        cout<<val<<endl;
    }
    return 0;
}
