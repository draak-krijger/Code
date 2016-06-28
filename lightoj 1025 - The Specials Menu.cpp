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

char str[110] ;
long long dp[65][65] ;

long long lcs(int i , int j);

int main()
{
    int tcase ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%s",str);

        clr(dp,-1);

        long long ans = lcs(0,strlen(str)-1);

        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}

long long lcs(int i , int j)
{
    if(i>j)
        return 0;

    if(i == j)
        return 1 ;

    long long int temp = 0 ;

    if(dp[i][j] != -1)
        return dp[i][j] ;

    if(str[i] == str[j])
        temp += 1 + lcs(i+1,j-1);

    temp += lcs(i+1,j) + lcs(i,j-1) - lcs(i+1,j-1);

    return dp[i][j] = temp;
}
