#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std ;

struct nude
{
    int u , v , w ;
};

vector<nude>graph ;
int n , parent[10009] ;

bool cmp(nude p , nude q);
int find_parent(int a);
long long int mst();

int main()
{
    int tcase , m ;
    long long mst1 ;
    nude get ;

    while(scanf("%d",&tcase) == 1)
    {

        if(tcase == 0)
            return 0 ;

        while(tcase--)
        {
            scanf("%d %d",&n,&m);

            graph.clear();

            for(int i=0 ; i<=n ; i++)
                parent[i] = i ;

            for(int i=0 ; i<m ; i++)
            {
                scanf("%d %d %d",&get.u,&get.v,&get.w);
                graph.push_back(get);
            }

            sort(graph.begin(),graph.end(),cmp);
            mst1 = mst();

            printf("%lld\n",mst1);
        }
    }
    return 0 ;
}

bool cmp(nude p , nude q)
{
    return p.w>q.w;
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] =find_parent(parent[a]);
}

long long int mst()
{
    int u , v ;
    long long w = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
        }

        else
            w += graph[i].w ;
    }
    return w ;
}
