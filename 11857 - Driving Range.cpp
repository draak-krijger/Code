#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p ) const
    {
        return w<p.w ;
    }
};

vector<node>graph ;
int parent[100119] , n ;
void reset();
int find_parent(int n);
int mst();

int main()
{
    int m , weight ;
    node get ;

    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(n==0 && m==0)
            return 0 ;

        reset();
        for(int i = 0 ; i<=n ; i++)
            parent[i] = i ;

        for(int i = 0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u , &get.v , &get.w);
            graph.push_back(get);
        }

        weight = mst();

        if(weight == 0)
            printf("IMPOSSIBLE\n");

        else
            printf("%d\n",weight);
    }
    return  0 ;
}

void reset()
{
    graph.clear();
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] = find_parent(parent[a]);
}

int mst()
{
    sort(graph.begin(),graph.end());

    int u , v , s = 0 , w , cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u != v)
        {
            parent[u] = v ;
            w = graph[i].w ;
            cont++;

            if(w>s)
                s = w ;
        }
    }

    if(cont < n-1)
        s = 0 ;

    return s ;
}
