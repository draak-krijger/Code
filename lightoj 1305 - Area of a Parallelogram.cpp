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
#define Max 10000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,tcase ;
    double a , b , c , s ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(ax,ay);
        sf2(bx,by);
        sf2(cx,cy);

        dx = cx - (bx-ax) ;
        dy = cy - (by-ay) ;

        a = sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by))) ;
        b = sqrt(((bx-cx)*(bx-cx))+((by-cy)*(by-cy))) ;
        c = sqrt(((ax-cx)*(ax-cx))+((ay-cy)*(ay-cy))) ;

        s = (a+b+c)/2.0 ;
        s = sqrt(s*(s-a)*(s-b)*(s-c)) ;

        printf("Case %d: %d %d %.0lf\n",cas,dx,dy,2*s);
    }
    return 0;
}
