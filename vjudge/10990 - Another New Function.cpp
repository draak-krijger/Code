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
#define Max 2000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int phi[Max] , sphi[Max];
ll csphi[Max] ;

ll con(ll n)
{
    ll cont = 1 ;
    n = phi[n] ;

    while(n != 1)
    {
        cont++;
        n = phi[n] ;
    }

    return cont ;
}

void seave()
{
    for(int i=1 ; i<Max-2 ; i++)
        phi[i] = i ;

    for(int i=2 ; i<Max-2 ; i+=2)
    {
        phi[i] -= (phi[i]/2) ;
    }

    for(int i=3 ; i<Max-2 ; i+=2)
    {
        if(phi[i] == i)
        {
            for(int j=i ; j<Max-2 ; j+=i)
                phi[j] -= (phi[j]/i) ;
        }
    }

    sphi[1] = 0 ;
    csphi[1] = 0 ;
    //cout<<"ok"<<endl;
    for(int i=2 ; i<Max-3 ; i++)
    {
        sphi[i] = sphi[phi[i]]+1 ;
        csphi[i] = csphi[i-1] + sphi[i] ;
    }
    //cout<<csphi[10]<<endl;
}

int main()
{
    seave();
    int tcase , a , b ;
    ll res ;

    sf1(tcase) ;

    foren(cas,1,tcase)
    {
        sf2(a,b) ;
        res = csphi[b] - csphi[a-1] ;
        printf("%lld\n",res);
    }
    return 0;
}
