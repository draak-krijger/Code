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
#define Max 100000+10
#define ll long long

int dp[15][15] , arra[15] , m ;
int rec(int taken , int rem );

int main()
{
    int tcase , n , result ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(m,n);

        forln(i,0,m)
            sf1(arra[i]);

        result = 0 ;
        clr(dp,-1);

        forln(i,0,m)
            result += rec(i,n);

        printf("Case %d: %d\n",cas,result);
    }
    return 0;
}

int rec(int taken , int rem )
{
    if(rem<=1)
        return 1 ;

    if(dp[taken][rem] != -1)
        return dp[taken][rem] ;

    dp[taken][rem] = 0 ;

    for(int i=0 ; i<m ; i++)
    {
        if(abs(arra[taken]-arra[i])<=2)
            dp[taken][rem] += rec(i,rem-1);
    }

    return dp[taken][rem] ;
}
