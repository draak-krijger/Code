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
#define sz 1100

using namespace std ;

vector<int>graph[sz] ;
bool check[sz] ;
int n , money[sz] , cont ;
long long cost , cost2 ;

void calculation(int cas);
void reset();
void dfs(int v);
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void reset()
{
    cost2 = 0 ;
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
    }
}

void dfs(int v)
{
    if(check[v])
        return;

    check[v] = true;
    cost += money[v];
    cont++;

    for(int i=0 ; i<graph[v].size() ; i++)
        dfs(graph[v][i]);
}

void input()
{
    int m ;
    scanf("%d %d",&n,&m);

    reset();

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&money[i]);
        cost2 += money[i];
    }

    int u , v ;

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
}

void calculation(int cas)
{
    int avg ;
    bool ck = true;

    if(cost2%n == 0)
    {
        avg = cost2/n;

        for(int i=1 ; i<=n ; i++)
        {
            if(!check[i])
            {
                cost = 0 ;
                cont = 0 ;
                dfs(i);

                if(cost != (cont*avg))
                {
                    ck = false;
                    break;
                }
            }
        }
    }

    else
        ck = false;

    if(ck)
        printf("Case %d: Yes\n",cas);

    else
        printf("Case %d: No\n",cas);
}
