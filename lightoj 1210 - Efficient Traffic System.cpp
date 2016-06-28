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
#define sz 21000

using namespace std ;

vector<int>graph[sz] ;
stack<int>stk;
bool check[sz] ;
int low[sz] , def[sz] , belong[sz] , indeg[sz] , outdeg[sz] , n , sc , tme ;

void reset();
void tarjan(int u);
void dfs(int v);
void SSC();
void input();
void calculation(int cas);

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
    sc = tme = 0 ;

    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
        indeg[i] = outdeg[i] = 0;
        low[i] = def[i] = -1;
        belong[i] = -1 ;
    }

    while(!stk.empty())
        stk.pop();
}

void tarjan(int u)
{
    low[u] = def[u] = tme++;
    int v ;
    stk.push(u);

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(def[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }

        else if(belong[v] == -1)
            low[u] = min(low[u],def[v]);
    }

    if(low[u] == def[u])
    {
        do
        {
            v = stk.top();
            stk.pop();
            belong[v] = sc;
        }
        while(u != v);

        sc++;
    }
}

void dfs(int v)
{
    check[v] = true;
    int u;

    for(int i=0 ; i<graph[v].size() ; i++)
    {
        u = graph[v][i];

        if((belong[u] != belong[v]) && (belong[u] != -1 && belong[v] != -1))
        {
            indeg[belong[u]]++;
            outdeg[belong[v]]++;
        }

        if(!check[u])
            dfs(u);
    }
}

void SSC()
{
    for(int i=1 ; i<=n ; i++)
    {
        if(def[i] == -1)
        {
            tarjan(i);
        }
    }
}

void input()
{
    int m ,u , v ;
    scanf("%d %d",&n,&m);
    reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
    }
}

void calculation(int cas)
{
    SSC();
    int ans = 0 ;
    for(int i=1 ; i<=n ; i++)
        if(!check[i])
            dfs(i);

    if(sc>1)
    {
        int in = 0, out = 0 ;

        for(int i=0 ; i<sc ; i++)
        {
            if(!indeg[i])
                in++;

            if(!outdeg[i])
                out++;
        }

        if(in>out)
            ans = in;

        else
            ans=out;

        printf("Case %d: %d\n",cas,ans);
    }

    else
        printf("Case %d: 0\n",cas);
}
