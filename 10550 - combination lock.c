#include <stdio.h>
int main()
{

    int a , b , c , d ;

    while(scanf("%d %d %d %d",&a,&b,&c,&d) != EOF)
    {
        if(a==0 && b==0 && c==0 && d==0)
            break ;

        if(a>=b)
            a = a-b ;
        else
            a = 40-b+a  ;

        if(b>c)
            b = 40-b+c ;
        else
            b = c-b ;

        if(c>=d)
            c = c-d;
        else
            c = 40-d+c ;

        d= 1080 + ((a+b+c)*9);

        printf("%d\n",d);
    }
    return 0 ;
}

