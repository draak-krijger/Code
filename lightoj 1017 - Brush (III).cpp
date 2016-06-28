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
#define Max 1000

set<string>myset ;
string a , b ;
long long int dp[110][110] ;

int n , k , w ;
long long yindx[112] ;
long long _0_1_napsak(int pos , int mv);

int main()
{
    int tcase  , a ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf3(n,w,k);

        forln(i,0,n)
        {
            scanf("%d %lld",&a,&yindx[i]);
        }

        sort(yindx,yindx+n);
        clr(dp,-1);
        long long ans = _0_1_napsak(0,0);

        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}

long long _0_1_napsak(int pos , int mv)
{
    if(pos == n)
        return 0;

    if(mv == k)
        return 0;

    if(dp[pos][mv] != -1)
        return dp[pos][mv] ;

    long long tmp = 1 , ret ;
    int j ;

    for(j=pos+1 ; j<n and yindx[j]-yindx[pos]<=w ; j++)
        tmp += 1 ;

    tmp += _0_1_napsak(j,mv+1);
    ret = max(tmp,_0_1_napsak(pos+1,mv));

    return dp[pos][mv] = ret ;
}
