#include <stdio.h>
int sorting(int a[],int n)
{
    int i , j, k;
    for(i=0 ; i< n-1; i++)
    {
        for(j=0;j< n -i -1;j++)
        {
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j]=a[j+1];
                a[j+1] = k;
            }
        }
    }
}
int main()
{
    int a , b ,i,j,k;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&b);
        int res[b];
        for(j=0;j<b;j++)
            scanf("%d",&res[j]);
        sorting(res,b);
        printf("Case %d: %d\n",i+1,res[b-1]);
    }
    return 0;
}

