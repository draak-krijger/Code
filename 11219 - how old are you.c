#include <stdio.h>
int main()
{
    int a ,b , c ,i , j ,p[3],bd[3];
    char d ;
    scanf("%d",&a) != EOF ;
    for(i=0 ; i<a ; i++)
    {
        j = 0 ;
        scanf("%d %c %d %c %d",&p[0] ,&d ,&p[1] ,&d ,&p[2]) != EOF;
        scanf("%d %c %d %c %d",&bd[0] ,&d ,&bd[1] ,&d ,&bd[2]) != EOF;
        if(p[0]<bd[0])
            j = 1;
        else
            j = 0 ;
        if((bd[1]+j)> p[1])
            j = 1;
        else j = 0;
        c = p[2] - (bd[2]+j);
        if(c<0)
            printf("Case #%d: Invalid birth date\n",i+1);
        else if(c >130)
            printf("Case #%d: Check birth date\n",i+1);
        else printf("Case #%d: %d\n",i+1 ,c);

    }
    return 0;
}

