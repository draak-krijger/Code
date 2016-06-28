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

vector<node>graph ;
int n , parent[150] , cas ;

bool cmp(node p , node q);
void mst();
int find_parent(int a);
void set_parent();

int main()
{
    int tcase , m ;
    node get ;

    scanf("%d",&tcase);

    for(cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&n,&m);

        graph.clear();

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            graph.PB(get);
        }

        mst();
    }
    return 0 ;
}

void set_parent()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i ;
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
    set_parent();

    int u , v , w = INT_MAX , cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;

            if(graph[i].w<w)
                w = graph[i].w ;
            cont++;
            if(cont == n-1)
                break;
        }
    }
    printf("Case #%d: %d\n",cas,w);
}

bool cmp(node p , node q)
{
    return p.w>q.w ;
}
