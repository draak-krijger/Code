#include <stdio.h>
int main()
{
    unsigned int a , b ;
    int c ;
    while(scanf("%u %u",&a,&b) != EOF)
    {
        c = a^b ;
        printf("%d\n",c);
    }
    return 0 ;
}

