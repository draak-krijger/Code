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
#define Max 10000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

bool flag[Max] ;
vector<ll>primes ;

void seave();

int main()
{
    int tcase ;
    ll a , cont , b ;
    seave();
    sf1(tcase);
//cout<<primes[primes.size()-1]<<endl;
    foren(cas,1,tcase)
    {
        scanf("%lld",&a);
        cont = 0;

        for(int i=0 ; primes[i]<=(a/2) ; i++)
        {
            if(!flag[a-primes[i]])
                cont++;
        }

        printf("Case %d: %lld\n",cas,cont);
    }
    return 0;
}

void seave()
{
    primes.pb(2);
    flag[1] = true;

    for(int i=4 ; i<Max-5 ; i+=2)
        flag[i] = true;

        for(int i=3 ; i<3164 ; i+=2)
        {
            if(!flag[i])
            {
                primes.pb(i);

                for(int j=i+i ; j<Max-5 ; j+=i)
                    flag[j] =true;

            }
        }

        for(int i=3165 ; i<=(Max/2)+5 ; i+=2)
            if(!flag[i])
                primes.pb(i);
}
