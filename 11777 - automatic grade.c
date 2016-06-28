#include <stdio.h>
#include <math.h>

int bubble(int a[])
{
    int i , j , temp ;

    for(i=0 ; i<2 ; i++)
    {
        for(j=0 ; j<2-i ; j++)
        {
            if(a[j+1] > a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp ;
            }
        }
    }
}
int main()
{
    int a , i , t , b , j , term[3];
    while(scanf("%d",&t) != EOF)
    {
        for(j=0 ; j<t ; j++)
        {
            b = 0 ;

            for(i=0 ; i<4 ; i++)
            {
                scanf("%d",&a);
                b += a ;
            }

            for(i=0 ; i<3 ; i++)
                scanf("%d",&term[i]);

            bubble(term);
            b +=  (term[0] +term[1])/2 ;

            if(b>=90)
            {
                printf("Case %d: A\n",j+1);
                continue ;
            }

            if(b>=80)
            {
                printf("Case %d: B\n",j+1);
                continue ;
            }

            if(b>=70)
            {
                printf("Case %d: C\n",j+1);
                continue ;
            }

            if(b>=60)
            {
                printf("Case %d: D\n",j+1);
                continue ;
            }

            else
            {
                printf("Case %d: F\n",j+1);
                continue ;
            }

        }
    }
    return 0 ;
}

