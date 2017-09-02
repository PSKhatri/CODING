//this algo gives r th largest element in the array in o(n) time average and o(n^2).
#include<bits/stdc++.h>
using namespace std;
int x,temp1,temp2,temp3,p,q;
int partition(int *a,int i,int j,int pivot)
{
    temp1=a[pivot];
    a[pivot]=a[j];
    a[j]=temp1;
    x=a[j];
    p=i-1;
    for(q=i;q<j;q++)
    {
        if(a[q]<=x)
        {
            p++;
            temp2=a[q];
            a[q]=a[p];
            a[p]=temp2;
        }
    }
        temp3=a[p+1];
        a[p+1]=a[j];
        a[j]=temp3;

        return (p+1);

}
int rFindRank(int *a,int i,int j,int r)
{
        if(i==j) return a[i];
        int pivot=i+rand()%(j-i+1);
        int k=partition(a,i,j,pivot);
        if(r==(j-k+1))
            return a[k];
        else if(r<(j-k+1))
            rFindRank(a,k+1,j,r);
        else
            rFindRank(a,i,k-1,(r-(j-k+1)));

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
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
