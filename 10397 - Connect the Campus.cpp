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

using namespace std;

struct node
{
    int u , v ;
    double w ;
};

struct co_ordinate
{
    long long int x , y ;
};

vector<node>graph ;
int n , parent[11100] ;
co_ordinate point[11100];

void mst();
double caldistance(co_ordinate p , co_ordinate q);
bool cmp(node p , node q);
int find_parent(int a);
void set_parent();

int main()
{
    int m , u , v ;
    node get ;

    while(scanf("%d",&n) == 1)
    {
        graph.clear();
        set_parent();

        for(int i=0 ; i<n ; i++)
            scanf("%lld %lld",&point[i].x ,&point[i].y);

        scanf("%d",&m);

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&u,&v);
            parent[find_parent(u)] = find_parent(v) ;
        }

        for(int i=0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                get.u = i+1 ;
                get.v = j+1 ;
                get.w = caldistance(point[i],point[j]);

                graph.push_back(get);
            }
        }

        mst();
    }
    return  0 ;
}

void set_parent()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i ;
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a;

    else
        return parent[a] = find_parent(parent[a]);
}

bool cmp(node p , node q)
{
    return p.w<q.w ;
}

double caldistance(co_ordinate p , co_ordinate q)
{
    double b ;
    b = sqrt(((p.x-q.x)*(p.x-q.x)) + ((p.y-q.y)*(p.y-q.y))) ;
    return b ;
}

void mst()
{
    sort(graph.begin(),graph.end(),cmp);

    int u , v , cont = 0 ;
    double w = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            cont++;
            w += graph[i].w ;

            if(cont==n-1)
                break;
        }
    }

    printf("%.2lf\n",w);
}
