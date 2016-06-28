#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    long long int permutation , l , m , n , ans , test , diff ;
    int i , j , k ;

    while(cin >> test)
    {
        ans = 0 ;

        for(i=1 ; i<=test ; i++)
        {
            cin >> l >> m >> n ;
            l = l*l ;
            permutation = 0 ;

            for(k=m ; k<=n ; k++)
            {
                diff = l-k ;

                for(j=diff+1 ; j<=l ; j++)
                {
                    permutation = (permutation%10000000000007)*j ;
                }
                ans += permutation ;
            }

            ans = ans%10000000000007;

            printf("Case %d: %lld\n",i,ans);
        }
    }

    return 0 ;
}
