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
#define Max 100000000+100
#define MOD 4294967296
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int arra[3125100] , cont ;
unsigned int res[5761461+5] ;
int primes[5761461+5] ;

bool check(int n, int pos);
int set_bit(int n,int pos);
void seave();
ll calculation(ll n);
ll big_mod(ll base,ll pw);

int main()
{
    int tcase ;
    ll n , result ;
    seave();
//cout<<primes.size()<<endl;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld",&n);
        result = calculation(n);
        printf("Case %d: %lld\n",cas,result);
    }
    return 0;
}

bool check(int n, int pos)
{
    return n&(1<<pos);
}

int set_bit(int n,int pos)
{
    n = n | (1<<pos);
    return n ;
}

void seave()
{
    arra[0] = 0 ;
    res[0] = 2 ;
    cont = 1 ;

    arra[0] = set_bit(0,1);

    for(int i=4 ; i<Max-5 ; i+=2)
        arra[i>>5] = set_bit(arra[i>>5],i&31) ;

    primes[cont-1] = 2;

    for(int i =3 ; i<10002 ; i+=2)
    {
        if(!check(arra[i>>5],i&31))
        {
            primes[cont] = i ;
            res[cont] = res[cont-1]*i;
            cont++;

            for(int j=i+i ; j<Max-5 ; j+=i)
            {
                arra[j>>5] = set_bit(arra[j>>5],j&31);
            }
        }
    }

    for(int i =10003 ; i<Max-5 ; i+=2)
    {
        if(!check(arra[i>>5],i&31))
        {
            primes[cont] = i ;
            res[cont] = res[cont-1]*i;
            cont++;
        }
    }
}

ll calculation(ll n)
{
    ll result = (upper_bound(primes,primes+cont,(int)n) - primes) - 1, sq , i , b , cont ;
    sq = sqrt((double)n) ;

    //cout<<result<<endl;
    result = res[result]%MOD ;
    //cout<<result<<endl;
    for(i=0 ; primes[i]<=sq ; i++)
    {
        b = n ;
        cont = 0 ;

        while(b/primes[i])
        {
            b = b/primes[i];
            cont++;
        }
        //cout<<primes[i] << " " <<cont<<endl;
        result = (result*big_mod(primes[i],cont-1))%MOD ;
    }
    //cout<<result<<endl;
//    for(;primes[i]<=n ; i++)
//    {
//        result = (result*primes[i])%MOD ;
//    }

    return result ;
}

ll big_mod(ll base,ll pw)
{
    ll result = 1 ;

    while(pw)
    {
        if(pw&1)
            result = (result*base)%MOD ;
        base = (base*base)%MOD ;
        pw /= 2 ;
    }
    return result;
}
