#include <bits/stdc++.h>
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
#include <bits/stdc++.h>

using namespace std ;

int w[50][50] , m , dp[50] ;

void inpcal();
int Set(int n , int pos);
bool Check(int n , int pos);
int Reset(int n , int pos);
int bitmask(int mask);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcal();
    return 0;
}

int Set(int n , int pos)
{
    n = n | (1<<pos);
    return n;
}
bool Check(int n , int pos)
{
    bool ck = n & (1<<pos);
    return ck ;
}
int Reset(int n , int pos)
{
    n = n & ~(1<<pos);
    return n;
}

int bitmask(int mask)
{
    if(mask == (1<<m)-1)
        return 0;

    if(dp[mask] != -1)
        return dp[mask];

    int mn =1000000 ;

    for(int i=0 ; i<m ; i++)
    {
        if(!Check(mask,i))
        {
            int price = w[i][i];

            for(int j = 0 ; j<m ; j++)
            {
                if(i != j && Check(mask,j))
                    price += w[i][j];
            }
            int ret = price+bitmask(Set(mask,i));
            mn = min(ret,mn);
        }
    }

    return dp[mask] = mn ;
}

void inpcal()
{
    scanf("%d",&m);
    memset(dp,-1,sizeof(dp));

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<m ; j++)
            scanf("%d",&w[i][j]);
    }

    int ret = bitmask(0);

    printf("%d\n",ret);
}
