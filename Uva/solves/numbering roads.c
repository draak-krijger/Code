#include <stdio.h>
#include <math.h>
int main()
{
    int a , b , c , i = 0 ;
    while(scanf("%d %d",&a,&b) == 2)
    {
        i++;
        if(a == 0 && b==0 )
            break;
        c = ceil((double)a/b);
        if(c-1>26)
        {
            printf("Case %d: impossible\n",i);
            continue;
        }
        printf("Case %d: %d\n",i,c-1);
    }
    return 0;
}

