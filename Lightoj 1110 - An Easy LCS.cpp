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

int dp[110][110] ;
string sdp[110][110] ;
char str1[110] , str2[110] ;
bool ck;
string p , q ;

void rset()
{
    for(int i=0 ; i<105 ; i++)
    {
        for(int j=0 ; j<105 ; j++)
        {
            dp[i][j] = -1 ;
            sdp[i][j].clear() ;
        }
    }
}

string lcs(int i , int j)
{
    string ans ;
    ans.clear();

    if(str1[i] == '\0' || str2[j] == '\0')
        return ans ;

    if(dp[i][j] != -1)
        return sdp[i][j] ;

    if(str1[i] == str2[j])
        ans = str1[i] + lcs(i+1,j+1);

    else
    {
        string val1 = lcs(i+1,j);
        string val2 = lcs(i,j+1);

        if(val1.size()>val2.size())
            ans = val1;

        else if(val1.size()<val2.size())
            ans = val2;

        else if(val1.size() == val2.size())
            ans = min(val1,val2) ;
    }

    dp[i][j] = 1 ;
    return sdp[i][j] = ans ;
}

int main()
{
    int tcase , k ;
    ll res ;
    string ans ;
    sf1(tcase);

    for(int cas=1; cas<=tcase; cas++)
    {
        scanf("%s %s",str1,str2);
        rset();
        ans = lcs(0,0);

        if(ans.size() == 0)
        {
            printf("Case %d: :(\n",cas);
        }

        else
        {
            printf("Case %d: ",cas);
            cout<<ans<<endl;
        }
    }
    return 0;
}
