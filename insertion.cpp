#include<iostream>
using namespace std;

void in_sort(int *a,int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        x=a[i];
        j=i-1;
        while(j>=0 && a[j] > x)
        {
            a[j+1]=a[j];
            j--;
        }
            a[j+1]=x;
    }
}

int main(void)
{
    int a[]={89,23,19,101,99,128,1,1000,10,139};
    int n=sizeof(a)/sizeof(a[0]);
    in_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}