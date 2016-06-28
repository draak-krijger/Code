#include <stdio.h>
int main()
{
    int a,i;
    scanf("%d",&a);
    long long int b,c;
    for(i=0; i<a; i++)
    {
        scanf("%lld %lld",&b,&c);
        if(b>c)
            printf(">\n");
        else if(b<c)
            printf("<\n");
        else if(c==b)
            printf("=\n");
    }
    return 0;
}

