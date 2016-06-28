#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std ;

int main()
{
    long long int a  , b , c , d , e , l , i ;

    while(cin >> a >> b)
    {
        if(b>a)
        {
            cout << "Impossible" << endl ;
            continue ;
        }
        l=0 ;
        c = a-b+2 ;
        d = sqrt(a) ;
        e = b-2 ;

        if(e<d)
        {
            for(i=e+1 ; i<=d ; i++)
            {
                if(a%i + 2 == b )
                {
                    a=i ;
                    break ;
                }
            }
        }

        else
        {
            for(i=d ; i>0 ; i--)
            {
                if((a%(c/i)) +2 == b )
                {
                    a=c/i ;
                    break ;
                }
            }
        }

        cout << a << endl ;
    }
    return 0 ;
}

