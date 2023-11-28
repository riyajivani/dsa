#include<iostream>
using namespace std;

void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;

    int *b=new int [h+1];

    while(i<=mid && j<=h)
    {
        if(a[i] < a[j])
        {
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }

    for(;i<=mid;i++)
    b[k++]=a[i];

    for(;j<=h;j++)
    b[k++]=a[j];

    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}

void merge_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

int main(void)
{
    int a[]={0,89,23,19,101,99,128,1,1000,10,139};
    int n=sizeof(a)/sizeof(a[0]);
    merge_sort(a,0,n-1);

    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}