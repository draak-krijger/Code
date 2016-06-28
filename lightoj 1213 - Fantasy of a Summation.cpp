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
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 2147483647+10
#define MOD 1000000007
#define ll long long
#define ull unsigned long long

ll big_mod(ll base, ll pw , ll mod);

int main()
{
    int tcase , tmp ;
    ll result , k , mod , n;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld %lld %lld",&n,&k,&mod);
        result = 0 ;

        forln(i,0,n)
        {
            scanf("%d",&tmp);

            result = (result+tmp)%mod;
        }
        result = (result * big_mod(n,k-1,mod))%mod ;
        result = (result*k)%mod ;

        printf("Case %d: %lld\n",cas,result);
    }
    return 0 ;
}

ll big_mod(ll base, ll pw , ll mod)
{
    ll result = 1 ;

    while(pw)
    {
        if(pw&1)
            result = (result*base)%mod ;

        base = (base*base)%mod ;
        pw /= 2;
    }

    return result ;
}
