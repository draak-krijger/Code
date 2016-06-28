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
#define sz 11000

using namespace std ;

vector<int>graph[sz] ;
bool check[sz] ;
int n , m ;

void calculation(int cas);
void reset();
void _dfs(int u);
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
    for(int i=0 ; i<=n ; i++)
    {
        check[i] = false;
        graph[i].clear();
    }
}

void _dfs(int u)
{
    if(check[u])
        return;

    check[u] = true;

    for(int i=0 ; i<graph[u].size() ; i++)
        _dfs(graph[u][i]);
}

void input()
{
    scanf("%d %d",&n,&m);
    reset();

    int u , v ;

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
    }
}

void calculation(int cas)
{
    int cont = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        if(!check[i])
        {
            cont++;
            _dfs(i);
        }
    }
    printf("Case %d: %d\n",cas,cont);
}
