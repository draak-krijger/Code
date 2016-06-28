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
    int u , v , w ;

    bool operator < (const node&p) const
    {
        return w>p.w ;
    }
};

map<string,int>matrix ;
vector<node>graph ;
int n , parent[300] , source , destination , cas ;

void mst();
void reset();
int find_parent(int a);
void set_parent();

int main()
{
    int m , l ;
    char s1[100] , s2[100] ;
    node get ;
    cas = 0 ;

    while(scanf("%d %d",&n,&m) != EOF && (n&&m))
    {
        reset();
        set_parent();
        l = 1 ;
        cas++;

        for(int i=0 ; i<m ; i++)
        {
            scanf("%s %s %d",s1,s2,&get.w);

            if(!matrix[s1])
                matrix[s1] = l++;

            if(!matrix[s2])
                matrix[s2] = l++;

            get.u = matrix[s1];
            get.v = matrix[s2];

            graph.push_back(get);
        }

        scanf("%s %s",s1,s2);

        source = matrix[s1];
        destination = matrix[s2];
        sort(graph.begin(),graph.end());

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
        return a;

    else
        return parent[a] = find_parent(parent[a]);
}

void reset()
{
    matrix.clear();
    graph.clear();
}

void mst()
{
    int u , v , w = INT_MAX ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;

            if(find_parent(source) == find_parent(destination))
            {
                w = graph[i].w ;
                break;
            }
        }
    }
    printf("Scenario #%d\n%d tons\n\n",cas,w);
}
