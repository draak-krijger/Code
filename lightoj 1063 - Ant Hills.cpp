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
int low[sz] , def[sz] , tme , parent[sz] , cont , n ;
bool ap[sz] ;

void calculation(int cas);
void reset();
void articulation(int u);
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
    tme = cont  = 0 ;

    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        def[i] = -1 ;
        parent[i] = -1 ;
        ap[i] = false;
    }
}

void articulation(int u)
{
    low[u] = def[u] = tme++;
    int v , children = 0;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(def[v] == -1)
        {
            parent[v] = u ;
            children++;
            articulation(v);
            low[u] = min(low[u],low[v]);

            if(parent[u] == -1 && children>1)
                ap[u] = true;

            if(parent[u] != -1 && low[v]>=def[u])
                ap[u] = true;
        }

        else if(v != parent[u])
            low[u] = min(low[u],def[v]);
    }
}

void input()
{
    int m , u , v ;

    scanf("%d %d",&n,&m);
    reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
}

void calculation(int cas)
{
    for(int i=1 ; i<=n ; i++)
    {
        if(def[i] == -1)
            articulation(i);

        if(ap[i])
            cont++;
    }

    printf("Case %d: %d\n",cas,cont);
}
