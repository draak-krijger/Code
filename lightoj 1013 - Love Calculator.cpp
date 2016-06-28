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
long long int dp[110][110] , unq , dp2[110][110] ;

long long int lcs(int i, int j);
long long alllcs(int i, int j);
void reset();

int main()
{
    int tcase ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        cin>>a>>b ;
        reset();
        unq = 0 ;
        lcs(0,0) ;
        alllcs(0,0);
        printf("Case %d: %lld %lld\n",cas,dp[0][0],dp2[0][0]);
    }
    return 0;
}

void reset()
{
    foren(i,0,a.length())
    {
        foren(j,0,b.length())
        {
            dp[i][j] = -1 ;
            dp2[i][j] = -1 ;
        }
    }
}
long long int lcs(int i, int j)
{
    long long int ans = 0 ;

    if(a[i] == '\0' && b[j] == '\0')
    {
//        unq++;
        return 0 ;
    }

    if(dp[i][j] != -1)
    {
//        unq++;
        return dp[i][j] ;
    }

    if(a[i] == '\0')
        ans = 1+lcs(i,j+1);

    else if(b[j] == '\0')
        ans = 1 + lcs(i+1,j);

    else if(a[i] == b[j])
    {
        ans = 1 + lcs(i+1,j+1);
    }

    else
        ans =1 + min(lcs(i+1,j),lcs(i,j+1));

    return dp[i][j] = ans ;
}

long long alllcs(int i, int j)
{

    if(a[i] == '\0' && b[j] == '\0')
        return 1 ;

    if(dp2[i][j] != -1)
        return dp2[i][j] ;

    if(a[i] == '\0')
        return dp2[i][j] = alllcs(i,j+1);

    else if(b[j] == '\0')
        return dp2[i][j] = alllcs(i+1,j);

    else if(a[i] == b[j])
        return dp2[i][j] = alllcs(i+1,j+1);

    else
    {
        if(dp[i][j+1]<dp[i+1][j])
            return dp2[i][j] = alllcs(i,j+1);

        else  if(dp[i+1][j]<dp[i][j+1])
            return dp2[i][j] = alllcs(i+1,j);

        else
            return dp2[i][j] = alllcs(i,j+1) + alllcs(i+1,j) ;
    }
}
