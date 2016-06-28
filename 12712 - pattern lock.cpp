#include <iostream>
#include <cstdio>
#define mod 10000000000007

using namespace std ;

int main()
{
    long long int per , l , m , n , ans , test , minmum ;
    int i , j , k ;

    while(cin >> test)
    {

        for(i=1 ; i<=test ; i++)
        {
            cin >> l >> m >> n ;
            l = l*l ;
            ans = 0 ;
            minmum = 1 ;

            for(k=l-m+1 ; k<=l ; k++)
            {
                minmum = (minmum%mod)*k ;
            }

            ans = minmum ;

            for(j=l-m ; j>(l-n) ; j--)
            {
                ans = (ans%mod)*j ;
                minmum = (minmum + ans) % mod ;
            }

            minmum = minmum %mod ;

            printf("Case %d: %lld\n",i,minmum);
        }
    }
    return 0 ;
}

