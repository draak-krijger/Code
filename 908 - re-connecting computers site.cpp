#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>

using namespace std ;

struct edge
{
    int u , v , w ;

    bool operator < (const edge&p ) const
    {
        return w < p.w;
    }
};

vector < edge > graph ;
int cost , fr[10000000];
int find_parent (int r);
int mst(int p);

int main()
{
    int n , k , m ;
    bool check = false ;

    while(scanf("%d",&n) != EOF)
    {
        edge get ;

        graph.clear();

        for(int i =0 ; i<n-1 ; i++)
        {
            scanf("%d %d %d",&get.u ,&get.v ,& get.w);
            graph.push_back(get);
        }

        for(int i=1 ; i<=n ; i++)
            fr[i] = i ;

        cost = 0 ;
        mst(n);

        if(check)
            printf("\n");

        check = true ;

        printf("%d\n",cost);

        graph.clear();
        for(int i=1 ; i<=n ; i++)
            fr[i] = i ;

        scanf("%d",&k);

        for(int i=0 ; i<k ; i++)
        {
           scanf("%d %d %d",&get.u ,&get.v ,& get.w);
           graph.push_back(get);
        }

        scanf("%d",&m);
        for(int i=0 ; i<m ; i++)
        {
           scanf("%d %d %d",&get.u ,&get.v ,& get.w);
           graph.push_back(get);
        }

        cost = 0 ;
        mst(n);
        printf("%d\n",cost);
    }
    return 0 ;
}

int find_parent (int r)
{
    if(fr[r] == r)
        return r ;

    else
        return fr[r] = find_parent(fr[r]);
}

int mst(int p)
{
    int u , v , cnt = 0 ;

    sort(graph.begin() , graph.end());

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u) ;
        v = find_parent(graph[i].v) ;

        if(u != v)
        {
            fr[u] = v ;
            cost += graph[i].w;
            cnt++;
            if(cnt == p)
                break;
        }
    }
}
