#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int c , d , t , i ;
    double final_c ;

    while(cin >> t)
    {
        for(i=1 ; i<=t ; i++)
        {
            cin >> c >> d ;

            final_c = c + ((double)d * 5/9);

            printf("Case %d: %.2lf\n",i,final_c) ;
        }
    }
    return 0 ;
}

