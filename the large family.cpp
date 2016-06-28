#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int a ;
    double g , d , c , x ;

    while(scanf("%d",&a) != EOF)
    {

        if(a==0)
            break;

        d = c = a/7;
        x = a%7;

        if(x>5)
        {
            c++;
            x = x - 5 ;

            if(x==1)
                d = d + .5;

            else
                d = d + 1;
        }

        else
        {
            if(x>=2.5)
            {
                c = c + .5;
                x = x-2.5;

                if(x>=1)
                {
                    d = d +.5 ;
                    x = x-1;
                }

                if(x>=1)
                {
                    d = d + .5 ;
                    x = x - 1;
                }
            }

            else if(x>=1)
            {
                d = d + .5 ;
            }
        }

        g = a - (d*2 + c*5);
        printf("%.1lf %.1lf %.1lf %.1lf\n",g,d,d,c);
    }
    return 0 ;
}
