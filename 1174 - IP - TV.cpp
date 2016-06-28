#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define PB push_back

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p) const
    {
        return w < p.w ;
    }
};

vector<node>graph;
map<string , int >matrix ;
int n , parent[2020] ;
bool check ;

void reset();
int find_parent(int a);
int mst();

int main()
{
    int m , just_cont , tcase , weight ;
    char s1[1000] , s2[1000] ;

    scanf("%d",&tcase);
    check = false ;

    while(tcase--)
    {
        scanf("%d %d",&n,&m);

        reset();
        just_cont = 1 ;

        for(int i=0 ; i<m ; i++)
        {
            scanf("%s %s %d",s1,s2,&weight);

            if( !matrix[s1] )
                matrix[s1] = just_cont++;

            if( !matrix[s2] )
                matrix[s2] = just_cont++;

            node get ;

            get.u = matrix[s1] ;
            get.v = matrix[s2] ;
            get.w = weight ;
            graph.PB(get);
        }

        for(int i=0 ; i<=n ; i++)
            parent[i] = i ;

        weight = mst();

        if(check)
            printf("\n");

        check = true ;

        printf("%d\n",weight);
    }

    return 0 ;
}

void reset()
{
    matrix.clear();
    graph.clear();
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] = find_parent(parent[a]);
}

int mst()
{
    sort(graph.begin(),graph.end());

    int u , v , w = 0 , cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] =v ;
            cont++;

            w += graph[i].w ;

            if(cont == n)
                break;
        }
    }
    return w ;
}
