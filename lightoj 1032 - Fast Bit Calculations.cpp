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
#define Max 1000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll dp[35][35][2] , num[35] ;

ll rec(int pos,int cont,int pre,bool flag)
{
    if(pos==-1)
        return cont ;

    if(flag && dp[pos][cont][pre] != -1)
        return dp[pos][cont][pre] ;

    ll ans = 0 ;
    int ed ;
    ed = flag?1:num[pos] ;

    for(int i=0 ; i<=ed ; i++)
    {
//        if(pre == 1 && pre == i)
//            cont++;
        ans += rec(pos-1,cont+(pre == 1 && pre == i),i,flag || i<ed) ;
    }

    if(flag)
        dp[pos][cont][pre] = ans ;

    return ans ;
}

ll precal(ll n)
{
    int i = 0 ;

    while(n)
    {
        num[i++] = n%2 ;//cout<<num[i-1];
        n /= 2 ;
    }//cout<<endl;
    clr(dp,-1) ;
    return rec(i-1,0,-1,0);
}

int main()
{
    int tcase ;
    ll n ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1ll(n);
        printf("Case %d: %lld\n",cas,precal(n));
    }
    return 0;
}
