#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

struct node
{
    int u , v ;
    double w ;

    bool operator < (const node&p) const
    {
        return w<p.w ;
    }
};

struct coordinate
{
    double x , y ;
};

vector <node>graph ;
int n , parent[102] ;
coordinate allordinate[110];

double calwaight(coordinate p , coordinate q);
double mst();
int find_parent(int a);
void set_parent();

int main()
{
    int tcase , m ;
    node get ;
    double b ;
    bool check = false ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);

        graph.clear();

        for(int i=0 ; i<n ; i++)
            scanf("%lf %lf",&allordinate[i].x ,&allordinate[i].y);

        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                get.u = i ;
                get.v = j ;
                get.w = calwaight(allordinate[i],allordinate[j]);

                graph.push_back(get);
            }
        }

        b = mst();

        if(check)
            printf("\n");

        printf("%.2lf\n",b);

        check = true ;
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

double mst()
{
    int u , v , cont = 0;
    double w = 0 ;

    set_parent();
    sort(graph.begin(),graph.end());

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;
            w += graph[i].w ;
            cont++;

            if(cont == n-1)
                break;
        }
    }
    return w ;
}

double calwaight(coordinate p , coordinate q)
{
    double b ;

    b = sqrt(((p.x - q.x)*(p.x-q.x))+((p.y-q.y)*(p.y-q.y)));

    return b ;
}
