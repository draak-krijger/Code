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
#define Max 1000000+10
#define MOD 1000000007
#define ll long long
#define ull unsigned long long

ll gcd(ll a, ll b);

int main()
{
    int tcase ;
    ll a , b , l , lcm , c , k ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld %lld %lld",&a,&b,&l);

        lcm = (a*b)/gcd(a,b);

        if(l%lcm)
            printf("Case %d: impossible\n",cas);

        else
        {
            k = l/lcm ;
            c = k ;

            while(gcd(lcm,k) != 1)
            {
                l = gcd(lcm,k);
                c *= l;
                lcm /= l;
            }
            printf("Case %d: %lld\n",cas,c);
        }
    }
    return 0;
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;

    return gcd(b,a%b);
}
