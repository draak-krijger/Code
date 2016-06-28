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
#define Max 2000000+100
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll arra[Max] ;

ll big_mod(ll base,ll pw);
void factorial();

int main()
{
    int tcase , n , k ;
    ll result ;
    factorial();

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,k);
        result = (arra[n]*arra[k-1])%MOD ;
        result = (arra[n+k-1]*big_mod(result,MOD-2))%MOD ;
        printf("Case %d: %lld\n",cas,result);
    }
    return 0;
}

void factorial()
{
    arra[0] = 1 ;

    for(int i=1 ; i<Max-50 ; i++)
        arra[i] = (arra[i-1]*i)%MOD ;
}

ll big_mod(ll base,ll pw)
{
    ll result = 1 ;

    while(pw)
    {
        if(pw&1)
            result = (result*base)%MOD;

        base = (base*base)%MOD ;
        pw /= 2 ;
    }
    return result;
}
