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

bool flag[100000+10] ;
vector<int>primes ;

void seave();
ll segment_seave(ll a , ll b);

int main()
{
    int tcase ;
    ll a , b ;
    seave();
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case %d: %lld\n",cas,segment_seave(a,b));
    }
    return 0;
}

void seave()
{
    flag[1] = true ;

    for(int i=4 ; i<=46360 ; i+=2)
        flag[i] = true;

    primes.pb(2) ;

    for(int i=3 ; i<216 ; i+=2)
    {
        if(!flag[i])
        {
            primes.pb(i);

            for(int j=i+i ; j<=46360 ; j+=i)
            {
                flag[j] = true;
            }
        }
    }

    for(int i=217 ; i<=46360 ; i+=2)
    {
        if(!flag[i])
        {
            primes.pb(i);
        }
    }
}

ll segment_seave(ll a , ll b)
{
    int n = sqrt((double)b) ;
    ll j , cont = 0 ;
    fill(flag,flag+(b-a+2),false);

    for(int i=0 ; primes[i]<=n ; i++)
    {
        if(primes[i]>=a)
            j = 2*primes[i] ;

        else
        {
            j = (a/(ll)primes[i])*(ll)primes[i] ;

            if(j<a || j==primes[i])
            {
                j+=(ll)primes[i] ;
            }
        }

        for(;j<=b ; j+=primes[i])
            flag[j-a] = true;
    }

    for(ll i=a ; i<=b ; i++)
    {
        if(!flag[i-a])
        {
            cont++;
        }
    }

    if(a == 1)
        cont--;

    return cont ;
}
