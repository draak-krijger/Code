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

map<string,int>matrix ;
vector<int>graph[50] ;

int parent[100];
bool check[100];

void bfs(int source , int destination);
void set_parent();
void reset();

int main()
{
    int m , n , p , shipment , tcase , u , v ;
    long long cost ;
    char s1[100] , s2[100] ;
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    for(int cas = 1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d",&m,&n,&p);
        reset();

        for(int i = 1 ; i<=m ; i++)
        {
            scanf("%s",s1);
            matrix[s1] = i ;
        }

        for(int i = 0 ; i<n ; i++)
        {
            scanf("%s %s",s1,s2);
            u = matrix[s1];
            v = matrix[s2];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(cas == 1)
            printf("SHIPPING ROUTES OUTPUT\n\n");

        printf("DATA SET  %d\n\n",cas);

        for(int i = 0 ; i<p ; i++)
        {
            scanf("%d %s %s",&shipment,s1,s2);

            u = matrix[s1] ;
            v = matrix[s2] ;

            bfs(u,v);
            cost = shipment*parent[v]*100;

            if(cost>0)
                printf("$%lld\n",cost);

            else
                printf("NO SHIPMENT POSSIBLE\n");
        }

        printf("\n");

        if(cas == tcase)
            printf("END OF OUTPUT\n");
    }
    return 0 ;
}

void reset()
{
    for(int i = 0 ; i<=45 ; i++)
        graph[i].clear();

    matrix.clear();
}

void set_parent()
{
    for(int i = 0 ; i<=45 ; i++)
        parent[i] = 0 ;

    fill(check , check+45 , true);
}

void bfs(int source , int destination)
{
    int u , v ;
    set_parent();
    bool fbreak = false;
    queue<int>seq ;

    seq.push(source);
    parent[source] = 0 ;

    check[source] = false;

    while(!seq.empty())
    {
        u = seq.front();
        seq.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];

            if(check[v])
            {
                check[v] = false;
                parent[v] = parent[u] + 1 ;

                if(v == destination)
                {
                    fbreak = true ;
                    break;
                }
                seq.push(v);
            }
        }

        if(fbreak)
            break;
    }
}
