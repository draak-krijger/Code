#include <stdio.h>
int swap(int a[],int c)
{
    int i,d,swa;
    for(i=0;i<c-1;i++)
    {
        for(d=0;d<c-i-1;d++)
        {
            if(a[d]>a[d+1])
            {
                swa = a[d];
                a[d]=a[d+1];
                a[d+1]=swa;
            }
        }
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    int ara[a],i,j;
    for(i=0;i<a;i++)
    {
        scanf("%d",&ara[i]);
    }
    swap(ara,a);
    for(i=0;i<a;i++)
    {
        printf("%d ",ara[i]);
    }
    return 0;
}

