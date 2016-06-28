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
#define jora pair<int,int>
#define pb push_back
#define sz 110

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator <(const node &p) const
    {
        return w<p.w ;
    }
};

vector<node>graph ;
map<string,int>mymap ;
int parent[sz] , n ;
long long int cost ;

void calculation(int cas);
void set_par();
int find_par(int p);
void reset();
void mst();
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void set_par()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i;
}

int find_par(int p)
{
    if(parent[p] == p)
        return p;

    else
        return parent[p] = find_par(parent[p]);
}

void reset()
{
    graph.clear();
    mymap.clear();
}

void mst()
{
    int u , v , cont = 0 ;
    cost = 0 ;
    set_par();

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_par(graph[i].u);
        v = find_par(graph[i].v);

        if(u != v)
        {
            parent[u] = v ;
            cont++;
            cost += graph[i].w ;
        }
    }

    if(cont != n-1)
        cost = -1 ;
}

void input()
{
    char city1[100] , city2[100] ;
    int w , m ;
    node get ;

    n = 0 ;
    reset();
    scanf("%d",&m);


    for(int i=0 ; i<m ; i++)
    {
        scanf("%s %s %d",&city1,&city2,&w);

        if(!mymap[city1])
            mymap[city1] = ++n;

        if(!mymap[city2])
            mymap[city2] = ++n;

        get.u = mymap[city1];
        get.v = mymap[city2];
        get.w = w ;

        graph.pb(get);
    }
}

void calculation(int cas)
{
    sort(graph.begin(),graph.end());

    mst();

    if(cost>=0)
        printf("Case %d: %lld\n",cas,cost);

    else
        printf("Case %d: Impossible\n",cas);
}
