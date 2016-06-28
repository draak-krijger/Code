#include <stdio.h>
int main()
{
    int a , b ,c , d , i , j , sum ;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        sum = 0;
        scanf("%d %d",&b ,&c);
        if(c<b)
        {
            d = b;
            b = c;
            c = d;
        }
        for(b ; b<=c ; b++)
        {
            if(b%2 != 0){
                sum +=b;
            }
        }
        printf("Case %d: %d\n",i+1,sum);
    }
    return 0;
}

