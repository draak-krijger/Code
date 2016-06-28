// Coin change bottom up
#include <bits/stdc++.h>

using namespace std ;

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000000+10
#define MOD 100000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll dp[10000+10] ;
int n ;
int arra[110] ;

ll rec(int sum)
{
    clr(dp,0);
    dp[0] = 1 ;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=arra[i] ; j<=sum ; j++)
        {
            dp[j] += dp[j-arra[i]] ;
            dp[j] = dp[j]%MOD ;
        }
    }

    return dp[sum] ;
}

int main()
{
    int tcase , k ;
    ll res ;
    sf1(tcase);

    for(int cas=1;cas<=tcase;cas++)
    {
        sf1(n);
        sf1(k) ;
        forln(i,0,n)
        {
            sf1(arra[i]);
        }

        res = rec(k) ;
        printf("Case %d: %lld\n",cas,res);
    }
    return 0;
}
