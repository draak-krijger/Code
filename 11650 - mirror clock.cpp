#include <cstdio>
#include <iostream>

using namespace std ;

int main()
{
    int a , b , c , d , t ;
    char s ;

    while(cin >> t)
    {
        while(t--)
        {
            cin >> a >> s >> b;
            c = 12 - a ;
            d = 60-b ;

            if(c == 0 && b == 0)
            {
                c=a ;
                d=0 ;
            }

            else if(c==0 && d>0)
                c=a-1 ;

            else
                c=c-1 ;

            if(c==0)
                c=12 ;

            if(d==60)
            {
                d=0;

                if(c!=12)
                    c++ ;
                else
                    c=1 ;
            }

            printf("%02d:%02d\n",c,d);
        }
    }
    return 0 ;
}

