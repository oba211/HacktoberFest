#include <stdio.h>

int isGood(int a[],int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    sum=sum+a[i];

    for(i=0;i<n;i++)
    {
        if(2*a[i]==sum)
        break;
    }
    if(i<n)
    return 1;
    else
    return 0;
}
void nice(int a[],int n)
{
    int x=isGood(a,n),idx,value,m;

    if(x)
    return;
    else
    {
        int cnt=0,i;
        for(i=0;i<n;i++)
        {
            value=a[i];
            a[i]=0;
            x=isGood(a,n);

            if(x)
            {
                idx=i;
                cnt++;
                m=value;
                continue;
            }
            else
                a[i]=value;
        }
    }
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    a[idx]=m;
    for(i=0;i<n;i++)
    {
        if(i==idx)
            continue;
        else
        {
            value=a[i];
            a[i]=0;
            x=isGood(a,n);
            if(x)
                continue;
            else
                a[i]=value;
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}
int main()
{
    int i,n;
    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    nice(a,n);
}