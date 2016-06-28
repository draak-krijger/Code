// coin change
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
#define difcoin 10
#define amnt 100

using namespace std ;

int dp[difcoin][amnt] ;
int coin[] = {5,8,11,15,18} ;
int make ;

int call(int i , int amount);

int main()
{
    while(scanf("%d",&make))
    {
        memset(dp,-1,sizeof(dp));
        cout<<call(0,0)<<endl;
    }
    return 0;
}

int call(int i , int amount)
{
    if(i>=5)
    {
        if(amount == make)
            return 1;

        return 0;
    }

    if(amount == make)
        return 1;

    else if(amount>make)
        return 0;

    if(dp[i][amount] != -1)
        return dp[i][amount];

    int ret1 = 0 , ret2 = 0 ;

    if(amount+coin[i]<=make)
        ret1 = call(i,amount+coin[i]);

    ret2 = call(i+1,amount);

    return dp[i][amount] = ret1|ret2;
}
