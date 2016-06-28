#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAX 1000000

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p) const
    {
        return w<p.w ;
    }
};

vector<node>graph ;
vector<int>nodeweight ;

int mst(int skip_indx);
void reset();
int find_parent(int a);
void parent_reset();

int n , parent[150] ;

int main()
{
    int tcase , m , scndmst , b , mst1 ;
    node get ;
//    freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&n,&m);
        reset();

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);

            graph.push_back(get);
        }

        sort(graph.begin(),graph.end());

        mst1 = mst(-1);

        printf("%d ",mst1);

        scndmst = MAX ;

        for(int i=0 ; i<nodeweight.size() ; i++)
        {
            b = mst(nodeweight[i]);

            if(b<scndmst && b>=mst1)
                scndmst = b ;
        }

        printf("%d\n",scndmst);
    }
    return 0 ;
}

void reset()
{
    graph.clear();
    nodeweight.clear();
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
       return parent[a] = find_parent(parent[a]);
}

void parent_reset()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i ;
}

int mst(int skip_indx)
{
    parent_reset();

    int u , v , w = 0 ,cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {

        if(i == skip_indx)
            continue;

        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            w += graph[i].w ;

            if(skip_indx == -1)
                nodeweight.push_back(i);

            cont++;

            if(cont == n-1)
                break;
        }
    }
    return w ;
}

