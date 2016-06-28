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

vector<int>graph[sz],cost[sz] ;
bool check[sz] , ck ;
int n , level1[sz] , level2[sz] , fn ;

void calculation(int cas);
void reset();
void bfs(int src);
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

    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        check[i] = false;
        graph[i].clear();
        cost[i].clear();
    }
}

void bfs(int src)
{
    queue<int>q ;
    int u , v , cst = 0 ;

    check[src] = true;

    if(ck)
        level2[src] = 0 ;

    else
        level1[src] = 0 ;

    q.push(src);

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];
            if(!check[v])
            {
                check[v] = true;

                if(ck)
                    level2[v] = level2[u] + cost[u][i];

                else
                {
                    level1[v] = level1[u] + cost[u][i];

                    if(level1[v]>cst)
                    {
                        cst = level1[v];
                        fn = v ;
                    }
                }

                q.push(v);
            }
        }
    }
}

void input()
{
    scanf("%d",&n);
    reset();

    int u , v , w ;

    for(int i=1 ; i<n ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
}

void calculation(int cas)
{
    ck = false;
    bfs(0);

    fill(check,check+(n+1),false);

    bfs(fn);

    ck = true;
    fill(check,check+(n+1),false);

    bfs(fn);

    printf("Case %d:\n",cas);

    for(int i=0 ; i<n ; i++)
    {
        printf("%d\n",max(level1[i],level2[i]));
    }

}
