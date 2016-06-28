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

vector<node>graph;
map<int,int>road;
int n , parent[1000] ;
co_ordinate point[1000];
bool blank ;

void reset();
void mst();
double caldis(co_ordinate p , co_ordinate q);
bool cmp(node p , node q);
int find_parent(int a);
void set_parent();

int main()
{
    int tcase , m , a , b ;
    node get ;
    blank = false ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);

        reset();
        set_parent();

        for(int i=1 ; i<=n ; i++)
            scanf("%d %d",&point[i].x,&point[i].y);

        for(int i=1 ; i<=n ; i++)
        {
            for(int j=i+1 ; j<=n ; j++)
            {
                get.u = i ;
                get.v = j ;
                get.w = caldis(point[i],point[j]);

                graph.PB(get);
            }
        }

        scanf("%d",&m);

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&a,&b);
            parent[find_parent(a)] = find_parent(b);
        }

        if(blank)
            printf("\n");

        blank = true;

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

bool cmp(node p , node q)
{
    return p.w<q.w ;
}

double caldis(co_ordinate p , co_ordinate q)
{
    double b ;

    b = sqrt(((p.x-q.x)*(p.x-q.x))+((p.y-q.y)*(p.y-q.y)));
    return b ;
}

void mst()
{
    sort(graph.begin(),graph.end(),cmp);

    int u , v , cont = 0 ;
    bool check = true ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            cont++;

            printf("%d %d\n",graph[i].u,graph[i].v);
            check = false;
        }
    }

    if(check)
        printf("No new highways need\n");
}

void reset()
{
    graph.clear();
    road.clear();
}
