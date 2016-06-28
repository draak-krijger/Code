#include <stdio.h>
int main()
{
    int t,i,c,a ,b , d ;
    scanf("%d",&t) != EOF;
    for(i=0 ; i<t ; i++)
    {
        scanf("%d %d %d",&a,&b,&c) != EOF ;
        c = c*(a+a-b)/(a+b);
        if(c<=0)
            printf("0\n");
        else
            printf("%d\n",c);
    }
    return 0 ;
}

