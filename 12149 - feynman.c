#include <stdio.h>
int main()
{
    int a ,c ,i ;
    long long b ;
    while(scanf("%d",&a) == 1)
    {
        b = 0;
        if(a == 0)
            break;
        for(i=1;i<=a;i++)
        {
            c = i*i ;
            b = b+c;
        }
        printf("%lld\n",b);
    }
    return 0;
}

