/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    problem name:
*/

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
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int ncr[sz][sz] , fac[sz] ;

int nCr(int n , int r)
{
    if(r == 1)
        return n ;

    if( n == r || r == 0)
        return 1 ;

    int& rat = ncr[n][r] ;

    if(rat != -1)
        return ncr[n][r] ;

    int ans ;
    ans = (ll)((ll)nCr(n-1,r)%Mod + (ll)nCr(n-1,r-1)%Mod) % Mod ;

    return rat = ans ;
}

int factorial()
{
    fac[0] = 1 ;

    for(int i=1 ; i<1002 ; i++)
    {
        fac[i] = (ll)((ll)fac[i-1]*(ll)i)%Mod ;
    }
}

int main()
{
    int tcase , n , m , k ;
    ll ans ;
    clr(ncr,-1);
    nCr(1001,1000);
    factorial();
    sf1(tcase) ;

    foren(cas,1,tcase)
    {
        scanf("%d %d %d",&n,&m,&k);
        ans = 0 ;

        for(int i=0 ; i<=(m-k) ; i++)
        {
            if(i&1)
                ans = (ll)((ll)ans - (ll)(nCr(m-k,i)%Mod) * (ll)(fac[n-k-i]%Mod))%Mod ;

            else
                ans = (ll)((ll)ans + (ll)(nCr(m-k,i)%Mod) * (ll)(fac[n-k-i]%Mod))% Mod ;

            if(ans<0)
                ans += Mod ;
        }

        ans = (ll)(ans%Mod)*(ll)(nCr(m,k) % Mod)%Mod ;

        printf("Case %d: %lld\n",cas,ans);
    }
    return 0 ;
}
