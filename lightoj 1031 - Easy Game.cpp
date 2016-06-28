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
#define Max 100000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll dp[110][110] , sum[110] ;

ll rec(int i,int j)
{
    if(dp[i][j] != -1)
        return dp[i][j] ;

    ll ans = sum[j] - sum[i-1] ;

    for(int k=i ; k<=j ; k++)
    {
        ans = max(ans,sum[k] - sum[i-1] - rec(k+1,j));
        ans = max(ans,sum[j] - sum[j-(k-i)-1]-rec(i,j-(k-i)-1));
    }

    return dp[i][j] = ans ;
}

int main()
{
    int tcase , a , n ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(n);
        sum[0] = 0 ;

        foren(i,1,n)
        {
            sf1(a);
            sum[i] = sum[i-1] + a ;
        }

        clr(dp,-1);

        printf("Case %d: %lld\n",cas,rec(1,n));
    }
    return 0;
}
