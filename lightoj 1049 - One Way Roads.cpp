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

using namespace std ;

vector<int>graph[105] ;
bool check[105] , ck ;
int n , cst , cost[105][150] ;

void calculation(int cas);
void reset();
void input();
void bfs();

int main()
{
    int tcase;

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
    ck = false;
    for(int i=1 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
    }
}

void input()
{
    scanf("%d",&n);
    reset();
    int u , v , w ;

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        graph[u].pb(v);
        graph[v].pb(u);
        cost[v][u] = w;
        cost[u][v] = 0;
    }
}

void bfs()
{
    queue<int>q ;
    int u , v , s = 1 ;
    cst = 0 ;

    q.push(1);
    check[1] = true;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(u == 1)
            {
                if(ck)
                {
                    ck = false;
                    continue;
                }

                else
                    ck = true;
            }

            if(check[v])
                continue;

            check[v] = true;
            q.push(v);
            s = v ;
            cst += cost[u][v];
        }
    }
    cst += cost[s][1];
}

void calculation(int cas)
{
    bfs();
    int cost1 = cst;

    ck = true;
    fill(check,check+(n+2),false);
    bfs();

    cost1 = min(cost1,cst);

    printf("Case %d: %d\n",cas,cost1);
}
