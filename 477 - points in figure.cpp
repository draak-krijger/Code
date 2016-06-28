#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    int i , j , k ,l ;
    double x[50] , y[50] , r[50] , x1[50] , y1[50] , x2[50] , y2[50] , m , n , d ;
    char s[100] , p ;
    bool check ;
    i=0;

    while(scanf("%c",&s[i]) && s[i] != '*')
    {
        if(s[i] == 'c')
        {
            scanf("%lf %lf %lf",&x[i],&y[i],&r[i]);
            i++;
        }

        else if(s[i] == 'r')
        {
            scanf("%lf %lf %lf %lf",&x1[i],&y1[i],&x2[i],&y2[i]);
            i++;
        }
    }

    k=0 ;

    while(scanf("%lf %lf",&m,&n))
    {
        if(m == 9999.9 && n == 9999.9)
            return 0 ;

        k++;
        check = true ;

        for(l=0 ; l<i ; l++)
        {
            if(s[l] == 'r')
            {
                if(m>=x1[l] && m<=x2[l] && n<=y1[l] && n>=y2[l])
                {
                    check = false ;
                    printf("Point %d is contained in figure %d\n",k,l+1);
                }
            }
            else if(s[l] == 'c')
            {
                d = sqrt(pow((m-x[l]),2.0) + pow((n-y[l]),2.0));

                if(d<=r[l])
                {
                    check = false;
                    printf("Point %d is contained in figure %d\n",k,l+1);
                }
            }
        }

        if(check)
            printf("Point %d is not contained in any figure\n",k);
    }
    return 0 ;
}
