#include <stdio.h>
int main()
{
    long long int a , b ;
    int i , j , k ,c , d ;
    while(scanf("%lld %lld",&a,&b) == 2)
    {
        if(a == 0 && b == 0)
            break;
        i = 0 ;
        j=0;
        while(a>0 || b>0){
        if(a%10 + b%10 +j >= 10)
        {
            a=a/10;
            b=b/10;
            i++;
            j=1;
        }
        else
        {
            j = 0;
            b=b/10;
            a=a/10;
        }
        }
        if(i==0)
            printf("No carry operation.\n");
        else if(i==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n",i);
    }
    return 0;
}

