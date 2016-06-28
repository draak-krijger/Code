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

using namespace std;

vector<int>graph[3000] ;
int n , dist[3000] , bomb[3000] ;

void graph_reset();
void distance_reset();
void bfs(int s);
void output(int s);

int main()
{
    int t , v ;
    while(scanf("%d",&n) == 1)
    {
        graph_reset();

        for(int i = 0 ; i<n ; i++)
        {
            scanf("%d",&t);

            for(int j = 0 ; j<t ; j++)
            {
                scanf("%d",&v);

                graph[i].push_back(v);
            }
        }

        scanf("%d",&t);

        for(int i = 0 ; i<t ; i++)
        {
            scanf("%d",&v);
            bfs(v);
            output(v);
        }
    }
    return 0 ;
}

void graph_reset()
{
    for(int i = 0 ; i<n+10 ; i++)
        graph[i].clear();
}

void distance_reset()
{
    for(int i = 0 ; i<=n+10 ; i++)
    {
        dist[i] = INT_MAX ;
        bomb[i] = 0 ;
    }
}

void bfs(int s)
{
    distance_reset();
    int u , v ;
    queue<int>seq ;

    seq.push(s);
    dist[s] = 0 ;

    while(!seq.empty())
    {
        u = seq.front();
        seq.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(dist[v] == INT_MAX)
            {
                dist[v] = dist[u] + 1 ;
                seq.push(v);
                bomb[dist[v]]++;
            }
        }
    }
}

void output(int s)
{
    if(!graph[s].size())
    {
        printf("0\n");
        return;
    }

    int maxm = 0 , indx ;

    for(int i = 0 ; i<n ; i++)
    {
        if(maxm<bomb[i])
        {
            maxm = bomb[i];
            indx = i ;
        }
    }

    printf("%d %d\n",maxm,indx);
}


