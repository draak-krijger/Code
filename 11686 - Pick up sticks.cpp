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
#define Max 1000100
#define PB push_back

using namespace std ;

vector<long long int>graph[Max] ;
bool check[Max];
long long int n , m , visited[Max] , cycle , result[Max] , l ;

void publishresult();
void reset();
void INPUT();
void checkcycle(int a);
void topsort(int a);
void calculation();

int main()
{
    while(scanf("%lld %lld",&n,&m) != EOF && (n||m))
    {
        reset();
        INPUT();
        calculation();
        publishresult();
    }
    return 0 ;
}

void reset()
{
    l = 0 ;
    cycle = 0;
    for(long long int i=0 ; i<=(n+2) ; i++)
    {
        graph[i].clear();
        check[i] = false;
        visited[i] = 0 ;
    }
}

void INPUT()
{
    long long x , y ;
    for(long long int i=0 ; i<m ; i++)
    {
        scanf("%lld %lld",&x,&y);
        graph[x].PB(y);
    }
}

void checkcycle(int a)
{
    if(visited[a] == 2 || cycle )
        return;

    if(visited[a] == 1)
    {
        cycle = 1 ;
        return;
    }

    visited[a] = 1 ;

    for(long long int i=0 ; i<graph[a].size() ; i++)
        checkcycle(graph[a][i]);

    visited[a] = 2 ;
}

void topsort(int a)
{
    if(!check[a])
    {
        for(long long int i=0 ; i<graph[a].size() ; i++)
            topsort(graph[a][i]);

        check[a] = true;
        result[l++] = a ;
    }
}

void publishresult()
{
    if(l==n)
    {
        for(long long int i=l-1 ; i>=0 ; i--)
        {
            printf("%lld\n",result[i]);
        }
    }

    else
        printf("IMPOSSIBLE\n");
}

void calculation()
{
    for(long long int i=1 ; i<=n ; i++)
    {
        if(!visited[i])
            checkcycle(i);

        if(cycle)
        {
            l = 0 ;
            break;
        }

        else
            topsort(i);
    }
}
