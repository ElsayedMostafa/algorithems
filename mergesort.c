#include<stdio.h>
int a[10]={9,8,7,6,5,4,3,2,1,0};
void merge(int L[],int R[], int LL, int LR, int O[])
{
    int i=0,j=0,k=0;
    while(i<LL&&j<LR)
    {
        if(L[i]<=R[j])
        {
            O[k]=L[i];
            i++;
        }
        else
        {
            O[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<LL)
    {
        O[k]=L[i];
        k++;
        i++;
    }
    while(j<LR)
    {
        O[k]=R[j];
        k++;
        j++;
    }
}
void mergesort(int a[],int l)
{
    if(l<2)
    {
        return ;
    }
    int mid = l/2;
    int left[mid];
    int right[l-mid];
    int i ,j;
    for(i=0;i<mid;i++)left[i]=a[i];
    for(j=mid;j<l;j++)right[j-mid]=a[j];
    mergesort(left,mid);
    mergesort(right,l-mid);
    merge(left,right,mid,l-mid,a);

}
int main()
{
    int l = sizeof(a)/sizeof(int);
    mergesort(a,l);
    int i;
    for(i=0;i<l;i++) printf("%d\n",a[i]);
    return 0;
}
