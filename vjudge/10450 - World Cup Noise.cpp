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
#define MOD 131071
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll fs[55] ;

void feb()
{
    fs[1] = 2 ;
    fs[2] = 3 ;

    for(int i=3 ; i<51 ; i++)
        fs[i] = fs[i-1] + fs[i-2] ;
}

int main()
{
    feb();
    int tcase , n ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(n) ;
        printf("Scenario #%d:\n",cas);
        printf("%lld\n\n",fs[n]);
    }
    return 0;
}
