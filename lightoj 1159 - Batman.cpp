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

int dp[51][51][51] , visit[51][51][51] , vi ;
char str1[51] , str2[51] , str3[51] ;

int rec(int i,int j, int k)
{
    if(str1[i] == '\0' || str2[j] == '\0' || str3[k] == '\0')
        return 0 ;

    int& rat = dp[i][j][k] ;
    int& vis = visit[i][j][k] ;

    if(vis == vi)
        return rat ;

    rat = 0 ;

    if(str1[i] == str2[j] && str2[j] == str3[k])
        rat = 1 + rec(i+1,j+1,k+1) ;

    else
    {
        rat = rec(i,j,k+1) ;
        rat = max(rat,rec(i,j+1,k));
        rat = max(rat,rec(i+1,j,k));
        rat = max(rat,rec(i+1,j+1,k));
        rat = max(rat,rec(i+1,j,k+1));
        rat = max(rat,rec(i,j+1,k+1));
    }

    vis = vi ;
    return rat ;
}

int main()
{
    int tcase , ans ;
    clr(visit,0);
    vi = 0 ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%s %s %s",str1,str2,str3);
        vi++;
        ans = rec(0,0,0);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0 ;
}
