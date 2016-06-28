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

vector<int>graph[100100] ;
int n , dist[100100] , src , dest ;

void bfs();
void graph_reset();

int main()
{
    int tcase , c , a , m , t ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);
        graph_reset();

        for(int i = 0 ; i<n ; i++)
        {
            scanf("%d %d",&m,&t);

            for(int j = 0 ; j<t ; j++)
            {
                scanf("%d",&a);
                graph[m].push_back(a);
            }
        }

        scanf("%d %d",&src,&dest);
        bfs();

        if(tcase)
            printf("\n");
    }
    return 0 ;
}

void graph_reset()
{
    for(int i = 0 ; i<=n+10 ; i++)
    {
        graph[i].clear();
        dist[i] = INT_MAX ;
    }
}

void bfs()
{
    int u , v ;
    queue<int>seq ;

    seq.push(src);
    dist[src] = 0 ;

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

                if(v == dest)
                    break;

                seq.push(v);
            }
        }
        if(v == dest)
            break;
    }

    printf("%d %d",src,dest);

    if(dist[v] == INT_MAX)
        printf(" 0\n");

    else
        printf(" %d\n",dist[v]-1);
}



