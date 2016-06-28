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
map<int,int>mymap;
int low[sz] , def[sz] , belong[sz] , n , tme , scc , visit[sz] ;
bool check[sz] , ck ;
stack<int>stk ;

void calculation(int cas);
void tarjan(int u);
void reset();
void dfs(int u);
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
    tme = scc = 0 ;
    ck = true;

    for(int i=0 ; i<=1010 ; i++)
    {
        graph[i].clear();
        low[i] = 0 ;
        def[i] = -1 ;
        belong[i] = -1 ;
        check[i] = false ;
        visit[i] = 0 ;
    }

    while(!stk.empty())
        stk.pop();
}

void tarjan(int u)
{
    low[u] = def[u] = tme++;
    stk.push(u);
    int v ;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(def[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }

        else if(belong[v] == -1)
        {
            low[u] = min(low[u],def[v]);
        }
    }

    if(low[u] == def[u])
    {
        do
        {
            v = stk.top();
            stk.pop();
            belong[v] = scc;
        }
        while(u != v);
        scc++;
    }
}

void dfs(int u)
{
    if(ck)
        return;

    int v ;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(belong[u] != belong[v])
        {
            if(!check[u])
            {
                check[u] = true;
                dfs(v);
            }

            else
            {
                ck = true;
                return;
            }
        }
    }
}

void input()
{
    mymap.clear();
    int chil , k , u , v ;
    n = 1;

    scanf("%d",&chil);
    reset();

    for(int i=0 ; i<chil ; i++)
    {
        scanf("%d",&k);

        for(int j=0 ; j<k ; j++)
        {
            scanf("%d %d",&u,&v);

            if(!mymap[u])
            {
                mymap[u] = n ;
                n++;
            }

            if(!mymap[v])
            {
                mymap[v] = n ;
                n++;
            }

            graph[u].pb(v);
        }
    }
}

void calculation(int cas)
{
    tarjan(0);

    if(tme == n-1)
    {
        ck = false;
        dfs(0);
    }

    if(ck)
        printf("Case %d: NO\n",cas);

    else
        printf("Case %d: YES\n",cas);
}
