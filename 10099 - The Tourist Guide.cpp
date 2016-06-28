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
#define PB push_back

using namespace std;

struct node
{
    int u , v , w ;
};

vector<node>graph;
int n , source , destination , parent[100] , cas , cost ;

void mst();
int find_parent(int a);
void reset();
bool cmp(node p , node q);

int main()
{
    int r ;
    node get ;
    cas=0;

    while(scanf("%d %d",&n,&r) != EOF && (n&&r))
    {
        reset();

        for(int i=0 ; i<r ; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            graph.PB(get);
        }

        scanf("%d %d %d",&source,&destination,&cost);
        cas++;

        mst();
    }
    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i ;

    graph.clear();
}

bool cmp(node p , node q)
{
    return p.w>q.w;
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] = find_parent(parent[a]);
}

void mst()
{
    sort(graph.begin(),graph.end(),cmp);

    int u , v , w = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
        }

        if(find_parent(source) == find_parent(destination))
        {
            graph[i].w--;
            w = ceil((double)cost/(double)graph[i].w);
            break;
        }
    }
    printf("Scenario #%d\n",cas);
    printf("Minimum Number of Trips = %d\n\n",w);
}

