#include<bits/stdc++.h>
using namespace std;
int x,temp;
int partition(int *a,int p,int r,int pivot)
{
   x=a[pivot];
    a[pivot]=a[r];
    a[r]=x;
   int i=p-1;
   for(int j=p;j<r;j++)
   {
       if(a[j]<=x)
       {
         i=i+1;
         temp=a[j];
         a[j]= a[i];
         a[i]=temp;
       }
   }
   temp=a[i+1];
   a[i+1]=a[r];
   a[r]=temp;
   return (i+1);
}
void quick_sort(int *a,int p,int r)
{
    if(p<r)
    {
    int pivot=p+rand()%(r-p+1);
    int q=partition(a,p,r,pivot);
    quick_sort(a,p,q-1);
    quick_sort(a,q+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int p=0;
    int r=(n-1);
    quick_sort(a,p,r);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
