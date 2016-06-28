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
#define sz 202

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node &p) const
    {
        return w<p.w ;
    }
};

vector<node>graph1,graph2;
int parent[sz] , n ;
long long int cost ;
bool ck , check[sz] ;

void inpcal(int cas);
void set_par();
int find_par(int p);
void mst();

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }
    return 0;
}

void set_par()
{
    for(int i=1 ; i<=n ; i++)
    {
        parent[i] = i;

        if(ck)
            check[i] = false;
    }
}

int find_par(int p)
{
    if(parent[p] == p)
        return p;

    else
        return parent[p] = find_par(parent[p]);
}

void mst()
{
    sort(graph1.begin(),graph1.end());
    int u , v , cont = 0 , delt = -1 ;
    cost = 0 ;

    for(int i=0 ; i<graph1.size() ; i++)
    {
        u = find_par(graph1[i].u);
        v = find_par(graph1[i].v);

        if(u != v)
        {
            cont++;
            parent[u] = v ;
            cost += graph1[i].w;
        }

        else
            delt = i ;
    }

    if(delt != -1)
        graph1.erase(graph1.begin()+delt);

    if(cont != n-1)
        cost = -1;
}

void inpcal(int cas)
{
    int w , cont = 0 ;

    scanf("%d %d",&n,&w);
    node get ;
    graph1.clear();
    ck = true;
    printf("Case %d:\n",cas);

    for(int i=0 ; i<w ; i++)
    {
        set_par();
        ck = false;

        scanf("%d %d %d",&get.u,&get.v,&get.w);
        graph1.pb(get);

        if(!check[get.u])
            cont++;

        if(!check[get.v])
            cont++;

        if(cont>=n)
        {
            mst();
            printf("%lld\n",cost);
        }

        else
            printf("-1\n");
    }
}
