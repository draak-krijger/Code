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
#define PB push_back

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

int n , parent[1010] , cas , dis ;
co_ordinate point[1010] ;

void set_parent();
int find_parent(int a);
double caldistance(co_ordinate p , co_ordinate q);
bool cmp(node p , node q);
void mst();

int main()
{
    int tcase ;
    node get ;

    scanf("%d",&tcase);

    for(cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&n,&dis);

        for(int i=0 ; i<n ; i++)
        {
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        graph.clear();

        for(int i=0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                get.u = i ;
                get.v = j ;
                get.w = caldistance(point[i],point[j]);

                graph.PB(get);
            }
        }

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

double caldistance(co_ordinate p , co_ordinate q)
{
    double b ;
    b = sqrt(((p.x - q.x)*(p.x - q.x))+((p.y-q.y)*(p.y-q.y)));
    return b ;
}

bool cmp(node p , node q)
{
    return p.w<q.w ;
}

void mst()
{
    int u , v , state = 1 , cont = 0 , c , tr ;
    double rw = 0 , row = 0 ;

    set_parent();
    sort(graph.begin(),graph.end(),cmp);

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            cont++;

            if(graph[i].w <= (double)dis )
            {
                row += graph[i].w ;
            }

            else
            {
                rw += graph[i].w ;
                state++;
            }

            if(cont == n-1)
                break;
        }
    }

    c = round(row);
    tr = round(rw);

    printf("Case #%d: %d %d %d\n",cas,state,c,tr);
}

