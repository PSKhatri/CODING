//gives k largest elements (unsorted) in linear time

#include<bits/stdc++.h>
using namespace std;
int temp1,temp2,temp3;
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
            temp2=a[p];
            a[p]=a[q];
            a[q]=temp2;
        }
    }
        temp3=a[p+1];
        a[p+1]=a[j];
        a[j]=temp3;
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
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int r;
    cin>>r;
    int val=rFindRank(a,0,n-1,r);
    for(int i=val;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
