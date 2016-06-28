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
#define mod 100000007

using namespace std ;

long long int dp[60][1100] ;
int coin[60] , idxlen[60] , n ;

void inpcal(int cas);
long long int coin_make(int indx , int amount);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }
    return 0;
}

long long int coin_make(int indx , int amount)
{
    if(indx>=n)
    {
        if(amount == 0)
            return 1 ;

        else
            return 0 ;
    }

    if(amount == 0)
        return 1 ;

    else if(amount<0)
        return 0 ;

    if(dp[indx][amount] != -1)
        return dp[indx][amount];

    long long int ret = 0 ;

    for(int i=0 ; i<idxlen[indx] ; i++)
    {
        if(amount-((i+1)*coin[indx])>=0)
        {
            ret += coin_make(indx+1,amount-((i+1)*coin[indx]))%mod;
        }

        else
            break;
    }

    ret += coin_make(indx+1,amount)%mod;

    return dp[indx][amount] = ret%mod;
}

void inpcal(int cas)
{
    memset(dp,-1,sizeof(dp));
    int k ;

    scanf("%d %d",&n,&k);

    for(int i=0 ; i<n ; i++)
        scanf("%d",&coin[i]);

    for(int i=0 ; i<n ; i++)
        scanf("%d",&idxlen[i]);

    printf("Case %d: %lld\n",cas,coin_make(0,k));
}
