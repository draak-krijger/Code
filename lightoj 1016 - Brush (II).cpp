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
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int arra[Max] ;

int main()
{
    int tcase , n , w ;
    ll x , y , cont ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,w);

        for(int i=0 ; i<n ; i++)
        {
            scanf("%lld %lld",&x,&y);
            arra[i] = y ;
        }

        sort(arra,arra+n);
        x = -1000000000-20 ;
        cont = 0 ;

        for(int i=0 ; i<n ; i++)
        {
            if(arra[i]>x){
                x = arra[i]+ w ;
                cont++;
            }
        }

        printf("Case %d: %lld\n",cas,cont);
    }
    return 0;
}
