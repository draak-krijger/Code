#include <stdio.h>
int main()
{
    long long int a ;
    int b , i , j ,ara[3000];
    while(scanf("%lld",&a) == 1)
    {
        if(a<0)
            break;
        if(a==0)
            printf("0");
        else {
        for(i=0 ; a>0 ; i++)
        {
            ara[i]=a%3;
            a = a/3;
        }
        for(j=i-1;j>=0 ;j--)
        {
            printf("%d",ara[j]);
        }
        }
        printf("\n");
    }
    return 0;
}

