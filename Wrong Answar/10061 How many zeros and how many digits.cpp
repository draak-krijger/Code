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
#define MOD 131071
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

vector<int>primes ;
map<int,int>mp ;
bool isprimes[1010] ;
double lg[1100000] ;

void seave()
{
    lg[0] = 0;

    for(int i=1 ; i<1100000-10 ; i++)
        lg[i] = lg[i-1] + log10((double)i);

    isprimes[1] = true;

    for(int i=4 ; i<1009 ; i+=2)
        isprimes[4] = true ;

    primes.pb(2) ;

    for(int i=3 ; i<1009 ; i+=2)
    {
        if(!isprimes[i])
        {
            primes.pb(i);
            for(int j = i+i ; j<1009 ; j+=i)
                isprimes[j] = true;
        }
    }
}

void cal(int n)
{
    mp.clear();
    int b = n ;

    for(int i=0 ; (ll)(primes[i]*primes[i])<=n ; i++)
    {
        if(b%primes[i] == 0)
        {
            while(b%primes[i] == 0)
            {
                b /= primes[i];
                mp[primes[i]]++;
            }
        }

        if(b == 1)
            break;
    }

    if(b!=1)
        mp[b]++;
}

ll POW(ll base,ll pw)
{
    ll res = 1 ;

    for(int i=0 ; i<pw ; i++)
        res *= base;

    return res ;
}

int main()
{
    ll n , bf , tmp , tmp2 , cont , m , tm , res , res2 ;;
    int b  ;
    seave();

    while(scanf("%lld %d",&n,&b) != EOF)
    {
        cal(b) ;
        map<int,int>::iterator it ;
        res = 2147483647 ;

        for(it = mp.begin() ; it!=mp.end() ; it++)
        {
            bf = it->first ;
            tmp2 = bf ;
            tmp = n ;
            cont = 0 ;
            m = 2 ;
            while(tmp/bf)
            {
                cont += tmp/bf ;
                bf = POW(tmp2,m++) ;
            }
            tm = it->second ;
            res = min(res,(ll)(cont/tm));
        }

        res2 = floor((lg[n]/log10((double)b)))+1;

        printf("%lld %lld\n",res,res2);
    }
    return 0;
}
