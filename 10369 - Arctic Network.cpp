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
    int x , y ;
};

vector<node>graph ;
int n , s , parent[1000] ;
co_ordinate point[1000];

double caldis(co_ordinate p , co_ordinate q);
void mst();
void set_parent();
int find_parent(int a);
bool cmp(node p , node q);

int main()
{
    int m , tcase ;
    node get ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&s,&n);

        for(int i=0 ; i<n ; i++)
            scanf("%d %d",&point[i].x,&point[i].y);

        set_parent();
        graph.clear();

        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                get.u = i ;
                get.v = j ;
                get.w = caldis(point[i],point[j]);

                graph.push_back(get);
            }
        }

        sort(graph.begin(),graph.end(),cmp);
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
    int u , v , cont = 0 ;
    double w = 0 ;

    for(int i=0 ; i<graph.size()&& cont<(n-s) ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            cont++;

            if(graph[i].w>w)
                w = graph[i].w ;
        }
    }
    printf("%.2lf\n",w);
}

double caldis(co_ordinate p , co_ordinate q)
{
    double b ;
    b = sqrt(((p.x-q.x)*(p.x-q.x))+((p.y-q.y)*(p.y-q.y)));
    return b ;
}

bool cmp(node p , node q)
{
    return p.w<q.w;
}
