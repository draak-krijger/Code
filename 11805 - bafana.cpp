#include <cstdio>
#include <iostream>

using namespace std ;

int main()
{
    int t , a , b , c , d , i ;

    while(cin >> t)
    {
        i = t ;
        while(t--)
        {
            cin >> a >> b >> c ;

            d = b+c ;

            while(a<d)
                d = d-a ;

            cout << "Case " << i-t << ": " << d << endl ;
        }
    }
    return 0 ;
}

