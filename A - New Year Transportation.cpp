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
#define sz 31000

using namespace std ;

vector<int>graph[2*sz];
bool check[2*sz] , ck ;
int n , t ;

void calculation();
void reset();
void dfs(int u);

int main()
{
    while(scanf("%d %d",&n,&t) != EOF)
    {
        reset();
        int a;

        for(int i=1 ; i<n ; i++)
        {
            scanf("%d",&a);
            a = a+i;
            graph[i].pb(a);
        }
        calculation();
    }
    return 0;
}

void reset()
{
    ck = false;
    for(int i=1 ; i<=(2*n+1) ; i++)
    {
        check[i] = false;
        graph[i].clear();
    }
}

void dfs(int u)
{
    if(check[u] || ck)
        return;

    check[u] = true;

    if(u == t)
    {
        ck = true;
        return;
    }

    for(int i=0 ; i<graph[u].size() ; i++)
        dfs(graph[u][i]);
}

void calculation()
{
    dfs(1);

    if(ck)
        printf("YES\n");

    else
        printf("NO\n");
}
