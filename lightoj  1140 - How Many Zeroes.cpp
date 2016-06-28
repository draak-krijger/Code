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
#define sz 1005
#define MOD 10056
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll dp[10][2][2][10] ;
int visit[10][2][2][10] , len , vi ;
char str[20] ;

ll rec(int pos,int pre,int zero, int z)
{
    if(pos == len)
        return z ;

    ll& rat = dp[pos][pre][zero][z] ;
    int& vis = visit[pos][pre][zero][z] ;

    if(vis == vi)
        return rat ;

    int ed = pre?str[pos] - '0' : 9 ;

    rat = 0 ;

    for(int i=0 ; i<=ed ; i++)
        rat += rec(pos+1,pre and i==ed,zero or i,zero?i?z:z+1:z) ;
    vis = vi ;
    return rat ;
}

int main()
{
    int tcase ;
    unsigned a , b ;
    ll ans ;
    clr(dp,0) ;
    clr(visit,0);
    vi = 0 ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%u %u",&a,&b);
        sprintf(str,"%u",b);
        len = strlen(str);
        vi++;
        ans = rec(0,1,0,0)+1;
//cout<<ans<<endl;
        if(a==0)
        {
            printf("Case %d: %lld\n",cas,ans);
            continue;
        }

        sprintf(str,"%u",a-1);
        len = strlen(str);
        vi++;
        ans -= (rec(0,1,0,0)+1);
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0 ;
}
