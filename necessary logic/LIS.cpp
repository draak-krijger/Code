// LIS
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

int seq[100] , dp[100] , dir[100] , n , start ;

void reset();
void input();
int lis(int u);
void calculation();
void path();
int main()
{
    input();
    calculation();
    path();
    return 0;
}

void input()
{
    scanf("%d",&n);
    reset();

    for(int i=1 ; i<=n ; i++)
        scanf("%d",&seq[i]);
}

int lis(int u)
{

    if(dp[u] != -1)
        return dp[u];

    int maxim = 0 ;

    for(int v = u+1 ; v<=n ; v++)
    {
        if(seq[v]>seq[u])
        {
            if(lis(v)>maxim)
            {
                maxim = lis(v);
                dir[u] = v ;
            }
        }
    }

    return dp[u] = maxim+1;
}

void calculation()
{
    int LIS = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        if(lis(i)>LIS)
        {
            LIS = lis(i);
            start = i ;
        }
    }

    printf("case#\nLIS: %d\n",LIS);
}

void path()
{
    int st = start ;
    while(dir[st]!=-1)
    {
        printf("index %d value %d\n",start,seq[start]);
        st = start;
        start=dir[start];
    }
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        dir[i] = -1 ;
        dp[i] = -1 ;
    }
}
