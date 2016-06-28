/*
    name : nazim
    id : 16062
*/

//header file

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <cstdlib>
#include <sstream>
#include <climits>

using namespace std ;

//define function

#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define MAX 17
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0)
#define jora_i pair<int,int>
#define jora_l pair<long long,long long>

//other

int dp[110][110] , leng ;
char str[120] ;

int palindrome(int i,int j)
{
    if(i==j || i>j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j] ;

    int ret = 0 ;

    if(str[i] == str[j])
        ret = palindrome(i+1,j-1);

    else
    {
        ret = min(palindrome(i+1,j),palindrome(i,j-1)) + 1 ;
    }

    return dp[i][j] = ret ;
}

int main()
{
    int tcase , ans ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%s",str);
        mem(dp,-1);
        leng = strlen(str);
        ans = palindrome(0,leng-1);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
