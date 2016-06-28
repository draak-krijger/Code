#include <stdio.h>
#include <string.h>
int main()
{
    int a , t ;
    long long b ;
    char s[10];

    while(scanf("%d",&t) != EOF)
    {
        b = 0 ;
        while(t--)
        {
            scanf("%s",s);

            if(strcmp(s,"donate") == 0)
            {
                scanf("%d",&a);
                b += a ;
                continue ;
            }

            if(strcmp(s,"report") == 0)
            {
                printf("%lld\n",b);
            }
        }
    }
    return 0 ;
}

