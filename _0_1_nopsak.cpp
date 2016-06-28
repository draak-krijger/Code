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
#define sz 100

using namespace std ;

int cost[sz] , weight[sz] , n , dp[sz][sz] , cap ;

int _0_1_nopsak(int i , int w);

int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%d %d",&n,&cap);

    for(int i=0 ; i<n ; i++)
        scanf("%d %d",&weight[i],&cost[i]);

    printf("%d\n",_0_1_nopsak(0,0));
    return 0;
}

int _0_1_napsak(int i , int w)
{
    if(i == n)
        return 0;

    if(dp[i][w] != -1)
        return dp[i][w] ;

    int profit1 = 0 , profit2 = 0 ;

    if(w+weight[i]<=cap)
        profit1 = cost[i] + _0_1_nopsak(i+1,w+weight[i]);

    profit2 = _0_1_nopsak(i+1,w);

    dp[i][w] = max(profit1,profit2);

    return dp[i][w] ;
}

