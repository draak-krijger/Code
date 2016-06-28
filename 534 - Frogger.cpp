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

struct co_ordinate
{
    int x , y ;
};

co_ordinate points[300];

int n ;
double  graph[300][300] ;

double cal_distance(co_ordinate p , co_ordinate q);
void floyed_warshal();

int main()
{
    int cas = 0 ;
    double dist ;
//freopen("input.txt","r",stdin);
    while(scanf("%d",&n) != EOF && n)
    {
        for(int i = 0 ; i<n ; i++)
            scanf("%d %d",&points[i].x,&points[i].y);

        for(int i=0 ; i<n ; i++)
        {
            for(int j=i+1 ; j<n ; j++)
            {
                dist = cal_distance(points[i],points[j]);
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }

        floyed_warshal();

        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++cas,graph[0][1]);
    }
    return 0 ;
}

double cal_distance(co_ordinate p , co_ordinate q)
{
    double b ;
    b = sqrt((double)((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y)));
    return b ;
}

void floyed_warshal()
{
    for(int k=0 ; k<n ; k++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                graph[i][j] = min(graph[i][j],max(graph[i][k],graph[k][j]));
            }
        }
    }
}
