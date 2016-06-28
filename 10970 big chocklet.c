#include <stdio.h>

int main()
{
    int a , b ;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        b = a*b-1 ;
        printf("%d\n",b);
    }
    return 0 ;
}

