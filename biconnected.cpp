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
#define sz 10000

using namespace std ;

vector<int>graph[sz];
int low[sz] , def[sz] , tme , n , parent[sz] ;
bool ck;

 void input();
 void reset();
 void articulation(int u);
 void point();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        point();

        if(ck || tme != n)
        {
            printf("NO\n");
        }

        else
            printf("YES\n");
    }
    return 0;
}

void reset()
{
    tme = 0 ;
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        def[i] = -1;
        ck = false;
        parent[i] = -1;
    }
}

void articulation(int u)
{
    def[u] = low[u] = tme++;
    int v , childrean = 0 ;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(def[v] == -1)
        {
            childrean++;
            parent[v] = u;
            articulation(v);
            low[u] = min(low[u],low[v]);

            if(parent[u] == -1 && childrean>1)
                ck = true;

            if(parent[u] != -1 && low[v]>=def[u])
                ck = true;
        }

        else if(v != parent[u])
            low[u] = min(low[u],def[v]);
    }
}

void point()
{
    for(int i=0 ; i<n ; i++)
        if(def[i] == -1)
        articulation(i);
}

void input()
{
    scanf("%d",&n);
    reset();
    int m ;
    scanf("%d",&m);

    for(int i=0 ; i<m ; i++)
    {
        int u , v ;

        scanf("%d %d",&u,&v);

        graph[u].pb(v);
        graph[v].pb(u);
    }
}
