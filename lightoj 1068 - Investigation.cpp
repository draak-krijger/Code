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
#define MOD 100000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int dp[10][2][90][90] , visit[10][2][90][90] , len , vi , k ;
char str[20] ;

int rec(int pos , int pre , int digit , int num)
{
    if(pos >= len)
        return digit%k == 0 and num == 0 ;

    int& ret = dp[pos][pre][digit][num] ;

    if(visit[pos][pre][digit][num] == vi)
        return ret ;

    ret = 0 ;
    int end = pre?str[pos]-'0':9 ;

    for(int i=0 ; i<=end ; i++)
    {
        ret+=rec(pos+1,pre and i==end,digit+i,(num*10 + i)%k) ;
    }

    visit[pos][pre][digit][num] = vi ;
    return ret ;
}

int main()
{
    int tcase , a , b , ans ;
    vi = 0 ;
    sf1(tcase);
    clr(visit,0);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        sf1(a);
        sf2(b,k);

        if(k>=90)
        {
            printf("Case %d: 0\n",cas);
            continue;
        }

        vi++ ;
        sprintf(str,"%d",b);
        len = strlen(str);
        ans = rec(0,1,0,0);
        vi++;
        sprintf(str,"%d",a-1);
        len = strlen(str);
        ans -= rec(0,1,0,0);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
