#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p ) const
    {
        return w<p.w;
    }
};

vector < node > graph ;
int parent[200009] , n ;
int mst();
int find_parent(int n);

int main()
{
    int ver , cost , allcost ;
    node get ;

    while(scanf("%d %d",&n,&ver) == 2)
    {

        if(n==0 && ver==0)
            return 0 ;

        graph.clear();
        allcost = 0 ;

        for(int i=0 ; i<=n ; i++)
            parent[i] = i ;

        for(int i = 0 ; i<ver ; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            allcost += get.w;
            graph.push_back(get);
        }

        cost = mst();
        printf("%d\n",allcost-cost);
    }
    return 0 ;
}

int find_parent(int n)
{
    if(parent[n] == n)
        return n ;

    return parent[n] = find_parent(parent[n]);
}

int mst()
{
    sort(graph.begin() , graph.end());

    int u , v , cont = 0 , weight = 0;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u) ;
        v = find_parent(graph[i].v) ;

        if(u!=v)
        {
            parent[u] = v ;

            cont++;
            weight += graph[i].w ;
            if(cont == n-1)
                break;
        }
    }

    return weight ;
}
