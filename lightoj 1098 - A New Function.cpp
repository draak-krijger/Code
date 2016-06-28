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
#define Max 2147500
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    int tcase ;
    ll a , sq , lft , p , result , i ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld",&a);
        //sq = sqrt((double)a);
        result = 0;
        lft = a ;

        for(i=2 ; i*i<=a ; i++)
        {
            result += ((a/i)-1)*i ;
            p = a/i + 1 ;

            result += (ull)(lft+p)*(lft-p+1)/2*(i-2) ;
            lft = a/i ;
        }

        for(; i<=lft ; i++)
            result += (ull)i*(a/i-1) ;

        printf("Case %d: %lld\n",cas,result);
    }
    return 0;
}
