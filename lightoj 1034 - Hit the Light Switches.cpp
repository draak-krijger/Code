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
int n , m ;
stack<int>order;
bool check[sz] ;

void calculation(int cas);
void reset();
void dfs(int u);
void input();
void dfs2(int u);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
    }

    while(!order.empty())
        order.pop();
}

void dfs(int u)
{
    int v ;
    check[u] = true;

    for(int i=0 ; i<graph[u].size() ; i++){
            v = graph[u][i];
        if(!check[v])
            dfs(v);
    }

        order.push(u);
        return;
}

void dfs2(int u)
{
    if(check[u])
        return;

    check[u] = true;

    for(int i=0 ; i<graph[u].size() ; i++)
        if(!check[graph[u][i]])
            dfs2(graph[u][i]);
}

void input()
{
    scanf("%d %d",&n,&m);
    int u , v ;
    reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
    }
}

void calculation(int cas)
{
    int cont = 0 , v ;

    for(int i=1 ; i<=n ; i++)
    {
        if(!check[i])
            dfs(i);
    }

    fill(check,check+(n+1),false);

    while(!order.empty())
    {
        v = order.top();
        order.pop();

        if(!check[v])
        {
            cont++;
            dfs2(v);
        }
    }

    printf("Case %d: %d\n",cas,cont);
}
