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
#define Max 500+10
#define sz 1005
#define MOD 10056
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int ncr[sz][sz] , dp[sz] ;

int nCr(int n , int r)
{
    if(r==1)
        return n ;

    if(n==r)
        return 1 ;

    int& rat = ncr[n][r] ;

    if(rat != -1)
        return rat ;

    rat = 0 ;
    rat = (nCr(n-1,r) + nCr(n-1,r-1))%MOD ;

    return rat ;
}

int rec(int pos)
{
    if(pos == 0)
        return 1 ;

    int& rat = dp[pos] ;

    if(rat != -1)
        return rat ;

    rat = 0 ;

    for(int i=1 ; i<=pos ; i++)
    {
        rat += (nCr(pos,i) * rec(pos-i)%MOD)%MOD ;
        rat %= MOD ;
    }

    return rat ;
}

int main()
{
    int tcase , ans , n ;
    clr(dp,-1);
    clr(ncr,-1);

    sf1(tcase) ;

    foren(cas,1,tcase)
    {
        sf1(n) ;
        ans = rec(n) ;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
