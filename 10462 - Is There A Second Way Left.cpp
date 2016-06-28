#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#define maxm 1000000
#define PB push_back

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
vector<int>nodename , nodeconnect ;
bool check[150] ;
int n , parent[150] ;

int mst(int sk_indx);
void reset();
void parent_set();
int find_parent(int a);

int main()
{
    int m , mst1 , mst2 , tcase , ms ;
    node get ;
    //freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&n,&m);

        reset();

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            graph.PB(get);
        }

        if(m==0 && n == 1)
        {
            printf("Case #%d : No second way\n",cas);
            continue;
        }
        sort(graph.begin(),graph.end());

        mst1 = mst(-1);

        if(nodeconnect.size() < n-1)
        {
            printf("Case #%d : No way\n",cas);
            continue;
        }

        mst2 = maxm ;

        for(int i=0 ; i<nodename.size() ; i++)
        {
            nodeconnect.clear();
            ms = mst(nodename[i]);

            if(ms>=mst1 && ms<mst2)
                mst2 = ms ;
        }

        if(mst2 == maxm)
            printf("Case #%d : No second way\n",cas);

        else
            printf("Case #%d : %d\n",cas,mst2);
    }
    return 0 ;
}

void reset()
{
    graph.clear();
    nodename.clear();
    nodeconnect.clear();
}

void parent_set()
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

int mst(int sk_indx)
{
    parent_set();

    int u , v , w=0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {

        if(sk_indx == i)
            continue;

        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            w += graph[i].w ;

            if(sk_indx == -1)
                nodename.push_back(i);

            nodeconnect.push_back(i);
        }
    }
    return w ;
}
