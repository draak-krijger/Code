#include <stdio.h>
int main()
{
    int a , b , c , i=0 , j , k ;
    while(scanf("%d",&a) == 1)
    {
        if(a<0)
            break;
        b=1;
        j = 0 ;
        i++;
        while(a>1)
        {
            j++;
            b = b*2;
            if(b>=a)
            {
                b = b + (b-a);
                break;
            }
        }
        printf("Case %d: %d\n",i ,j);
    }
    return 0 ;
}

