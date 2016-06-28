#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std ;

int m , n , s , par[1000] ;
struct edge
{
    int u , v , w ;

    bool operator < (const edge&p ) const
    {
        return w<p.w ;
    }
};

vector <edge> graph ;

int find_par(int v)
{
    if(par[v] == v)
        return v ;

    else
        return par[v] = find_par(par[v]) ;
}

int mst()
{
    int p , q ;

    sort(graph.begin(),graph.end());

    for(int i = 1 ; i<=n ; i++)
        par[i] = i ;

    s = 0 ;
    int cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        p = find_par(graph[i].u);
        q = find_par(graph[i].v);

        if(p!=q)
        {
            par[q] = p ;
            cont++;
            s += graph[i].w;

            if(cont == n-1)
                break;
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=0 ; i<m ; i++)
    {
        int u , v , w ;
        scanf("%d %d %d",&u,&v,&w);

        edge get ;

        get.u = u ;
        get.v = v ;
        get.w = w ;

        graph.push_back(get);
    }
    mst();
    cout << s << endl;
    return 0 ;
}
