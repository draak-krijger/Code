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
#define Max 500+10
#define MOD 100000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

double dp[Max][Max] ;
int visit[Max][Max] , vi ;

double rec(int red,int blue)
{
    if(red <= 0 || blue <= 0)
    {
        if(red == 0 && blue>=0)
            return 1 ;

        return 0 ;
    }

    double& ret = dp[red][blue] ;
    int& vis = visit[red][blue] ;

    if(vis == vi)
        return ret ;

    ret = (double)blue/(double)(red+blue) * rec(red,blue-2) ;
    ret += (double)red/(double)(red+blue) * rec(red-1,blue-1) ;

    vis = vi ;
    return ret ;
}

int main()
{
    int tcase , red , blue ;
    sf1(tcase);
    vi = 1 ;
    clr(visit,0);

    foren(cas,1,tcase)
    {
        sf2(red,blue);
        double ans ;
        ans = rec(red,blue);
        printf("Case %d: %.6lf\n",cas,ans);
    }
    return 0 ;
}
