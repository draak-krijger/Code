#include <stdio.h>
int sorting(int a[] , int n)
{
    int i , j , k ;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=a[j];
            }
        }
    }
}
int main()
{
    int a[3] , i , j , t ;
    scanf("%d",&t);
    for(i=0 ; i<t ; i++)
    {
        for(j=0 ; j<3 ; j++)
            scanf("%d",&a[j]);
        sorting(a,3);
        if((a[0] + a[1]) > a[2])
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}

