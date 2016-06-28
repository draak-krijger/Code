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

vector<int>graph[1000000];

int n , dist[1000000] ;
bool check[1000000] ;

void reset_graph();
void bfs();

int main()
{
    int tcase , m , u , v ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&n,&m);

        reset_graph();

        for(int i = 0 ; i<m ; i++)
        {
            scanf("%d %d",&u,&v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bfs();

        if(tcase)
            printf("\n");
    }
    return 0 ;
}

void reset_graph()
{
    for(int i = 0 ; i<=n+10 ; i++)
    {
        graph[i].clear();
        dist[i] = 0 ;
        check[i] = true;
    }
}

void bfs()
{
    int u , v , cont = 0 ;
    queue<int>ser ;

    ser.push(0);
    dist[0] = 0 ;
    check[0] = false;

    while(!ser.empty())
    {
        u = ser.front();
        ser.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(check[v])
            {
                dist[v] = dist[u] + 1 ;
                check[v] = false;

                cont++;

                if(cont == n-1)
                    break;

                ser.push(v);
            }
        }
        if(cont == n-1)
            break;
    }

    for(int a = 1 ; a<n ; a++)
        printf("%d\n",dist[a]);
}
