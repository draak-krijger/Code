#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p ) const
    {
        return w < p.w ;
    }
};

vector<node>graph ;
priority_queue<int , vector<int> , greater<int> >result ;

void reset();
int find_parent(int a) ;
void mst() ;

int n , parent[11000] ;

int main()
{
    int m ;
    node get ;

    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0)
            return 0 ;

        reset();

        for(int j=0 ; j<=n ; j++)
            parent[j] = j ;

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u ,&get.v , &get.w);
            graph.push_back(get);
        }

        mst();

        if(result.empty())
            printf("forest");

        else
        {
            printf("%d",result.top());
            result.pop();

            while(!result.empty())
            {
                printf(" %d",result.top());
                result.pop();
            }
        }
        printf("\n");
    }
    return 0 ;
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
    int u , v ;
    sort(graph.begin(),graph.end());

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
            parent[u] = v ;

        else
            result.push(graph[i].w);
    }
}

void reset()
{
    graph.clear();
    memset(parent , 0 , sizeof parent);

    while(!result.empty())
        result.pop();
}
