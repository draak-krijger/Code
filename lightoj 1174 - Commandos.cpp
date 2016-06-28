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

using namespace std ;

vector<int>graph[150] ;
bool check[150] ;
int n , r , src , dest , level[3][150] , ttime ;

void calculation(int cas);
void bfs(int rt , int indx);
void ireset();
void reset();
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

void bfs(int rt , int indx)
{
    queue<int>q ;
    int u , v ;

    q.push(rt);
    check[rt] = true;
    level[indx][rt] = 0 ;

    if(indx)
        ttime = max(ttime,(level[0][rt]+level[indx][rt]));

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(check[v])
                continue;

            check[v] = true;
            level[indx][v] = level[indx][u] + 1 ;
            q.push(v);

            if(indx)
                ttime = max(ttime,(level[0][v]+level[indx][v]));
        }
    }
}

void ireset()
{
    for(int i=0 ; i<=n ; i++)
    {
        check[i] = false;
        graph[i].clear();
    }
}

void reset()
{
    ttime = 0 ;
    for(int i=0 ; i<=n ; i++)
        check[i] = false;
}

void input()
{
    scanf("%d %d",&n,&r);
    ireset();

    int u , v ;

    for(int i=0 ; i<r ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    scanf("%d %d",&src,&dest);
}

void calculation(int cas)
{
    bfs(src,0);

    reset();

    bfs(dest,1);

    printf("Case %d: %d\n",cas,ttime);
}


