#include <stdio.h>
int main()
{
    int a ,b ,c ,d ,e ,i ,j  ;
    long long total ;
    while(scanf("%d",&a) != EOF)
    {
        for(i=0 ; i<a ; i++)
        {
            total = 0;
            scanf("%d",&b) != EOF ;
            for(j=0 ; j<b ; j++)
            {
                scanf("%d %d %d",&c ,&d ,&e);
                total = total + (c*e);
            }
            printf("%lld\n",total);
        }
    }
    return 0;
}

