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
#define Max 50000+10
#define MOD 1000000007
#define ll long long

bool arra[Max] ;
vector<long long>primes ;

ll calculation(ll base , ll exp);
ll big_mod(ll base, ll expo , ll mod);
void seave();

int main()
{
    int tcase ;
    ll x , y , b , p ;
    seave();
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld %lld",&b,&p);
        printf("Case %d: %lld\n",cas,calculation(b,p));

    }
    return 0;
}

ll big_mod(ll base, ll expo , ll mod)
{
    ll result = 1 ;

    while(expo)
    {
        if(expo&1)
            result = (result*base)%mod ;

        base = (base*base)%mod ;
        expo = floor(expo/2) ;
    }

    return result ;
}

void seave()
{
    arra[1] = true;

    for(int i=4 ; i<Max ; i+=2)
        arra[i] = true;

    primes.pb(2) ;

    for(int i=3 ; i<220 ; i+=2)
    {
        if(!arra[i])
        {
            primes.pb(i) ;

            for(int j=i+i ; j<Max ; j+=i)
                arra[j] = true;
        }
    }

    for(int i=221 ; i<Max ; i+=2)
        if(!arra[i])
            primes.pb(i);
}

ll calculation(ll base , ll exp)
{
    ll result = 1 , n = base , x , y ;
    ll cont ;

    for(int i=0 ; (primes[i]*primes[i])<=base ; i++)
    {
        if(n%primes[i] == 0)
        {
            cont = 0 ;

            while(n%primes[i] == 0)
            {
                n = n/primes[i] ;
                cont++;
            }
            cont *= exp ;

            x = big_mod(primes[i],cont+1,MOD)-1 ;
            y = big_mod(primes[i]-1,MOD-2,MOD) ;
            x = (x*y)%MOD ;

            if(x<0)
                x = x+MOD ;

            result = (result*x)%MOD ;
        }

        if(n==1)
            break;
    }

    if(n != 1)
    {
        x = (big_mod(n,exp+1,MOD)-1)%MOD ;
        y = big_mod(n-1,MOD-2,MOD) ;
        x = (x*y)%MOD ;

        if(x<0)
            x = x+MOD ;

        result = (result*x)%MOD ;
    }

    return result;
}
