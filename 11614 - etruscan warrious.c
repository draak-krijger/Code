#include <stdio.h>
#include <math.h>

int main()
{
    long long a , i , b , j ;
    int t ;
    while(scanf("%d",&t) != EOF)
    {
        while(t--)
        {

            scanf("%lld",&a);

            b =(sqrt(8*a+1)+1)/2;
            printf("%lld\n",b-1);
        }
    }
    return 0;
}

