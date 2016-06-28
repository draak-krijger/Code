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
#define inf 40000

using namespace std ;

int colour[23][5] , dp[23][4] , n ;

int inpcal(int cas);
int colour_cont(int row,int col);

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcal(cas);

    return 0;
}

int colour_cont(int row,int col)
{

    if(row>=n)
        return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

        int ret = inf ;

        for(int i=0 ; i<3 ; i++)
        {
            if(i == col)
                continue;

            ret = min(ret,colour_cont(row+1,i)+colour[row][col]);
        }

        return dp[row][col] = ret;
}

int inpcal(int cas)
{
    int ans;

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            scanf("%d",&colour[i][j]);
        }
    }

    memset(dp,-1,sizeof(dp));

    ans = min(colour_cont(0,0),min(colour_cont(0,1),colour_cont(0,2)));

    printf("Case %d: %d\n",cas,ans);
}
