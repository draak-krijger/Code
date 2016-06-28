#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
#define jora pair<int,int>
#define pb push_back

using namespace std ;

int dp[1100][35] , n  , cost[1100] , weight[1100] , cap ;

void inpcal();
int _0_1_nopsak(int i,int w);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcal();

    return 0;
}

int _0_1_nopsak(int i,int w)
{
    if(i == n)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w] ;

    int profit1 = 0 , profit2  = 0 ;

    if(w+weight[i]<=cap)
        profit1 = cost[i] + _0_1_nopsak(i+1,w+weight[i]);

    profit2 = _0_1_nopsak(i+1,w);

    dp[i][w] = max(profit1,profit2);

    return dp[i][w] ;
}

void inpcal()
{
    scanf("%d",&n);
    int g , mw ;
    long long int profit = 0 ;

    for(int i=0 ; i<n ; i++)
        scanf("%d %d",&cost[i],&weight[i]);

    scanf("%d",&g);

    for(int i=0 ; i<g ; i++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&mw);
        cap = mw ;
        profit +=  _0_1_nopsak(0,0);
    }

    printf("%lld\n",profit);
}
