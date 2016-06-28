#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <queue>
#define PB push_back

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p ) const
    {
        return w<p.w ;
    }
};

void reset();
void dfs(int u);
int find_parent(int a);
int mst();

vector <node >graph ;
vector<int>checkingroute[500] ;
map<string , int >matrix ;

int parent[500] , n ;
bool check[500] , checkrt ;

int main()
{
    int m , cont , cost ;
    node get ;
    char s1[1000] , s2[1000] ;

    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n==0 && m==0)
            return 0 ;

        reset();
        cont = 0 ;

        for(int i=0 ; i<n ; i++)
        {
            parent[i] = i ;

            scanf("%s",s1);

            if(!matrix[s1])
                matrix[s1] = cont++;
        }

        for(int i=0 ; i<m ; i++)
        {
            scanf("%s %s %d",s1,s2,&get.w);
            get.u = matrix[s1] ;
            get.v = matrix[s2] ;

            graph.PB(get);
            checkingroute[get.u].PB(get.v);
            checkingroute[get.v].PB(get.u);
        }

        scanf("%s",s1);
        dfs(matrix[s1]);

        for(int i=0 ; i<n ; i++)
        {
            if(!check[i])
                checkrt = false ;
        }

        if(checkrt)
        {
            cost = mst();
            printf("%d\n",cost);
        }

        else
            printf("Impossible\n");
    }
    return 0 ;
}

void reset()
{
    graph.clear();

    for(int i = 0 ; i<=420 ; i++)
        checkingroute[i].clear();

    matrix.clear();
    fill(check , check+420 , false);
    checkrt = true ;
}

void dfs(int u)
{
    if(check[u])
        return;

    check[u] = true ;

    for(int i=0 ; i<checkingroute[u].size() ; i++)
        dfs(checkingroute[u][i]);
}

int mst()
{
    sort(graph.begin() , graph.end());

    int u , v , w=0 , cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;

            cont++;

            w += graph[i].w ;

            if(cont == n-1)
                break;
        }
    }

    return w ;
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] = find_parent(parent[a]);
}
