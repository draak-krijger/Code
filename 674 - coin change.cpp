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

int coin[] = {50,25,10,5,1} , dp[7][7500] ;

int make_cent(int i , int amount);

int main()
{
    memset(dp,-1,sizeof(dp));

    int make ;

    while(scanf("%d",&make) != EOF)
    {
        printf("%d\n",make_cent(0,make));
    }
    return 0;
}

int make_cent(int i , int amount)
{
    if(i>=5)
    {
        if(amount == 0)
            return 1;

        else
            return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount] ;

    int ret1 = 0 , ret2 = 0 ;

    if(amount-coin[i]>=0)
        ret1 = make_cent(i,amount-coin[i]);

    ret2 = make_cent(i+1,amount);

    return dp[i][amount] = ret1+ret2;
}
