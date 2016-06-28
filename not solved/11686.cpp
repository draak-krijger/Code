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
#define Max 1100000

using namespace std ;

vector<long long int>graph[Max] ;
long long int n , m , result[Max] , c ;
bool check[Max];

void visit(long long int p);
void Input();
void reset();
void publishresult();

int main()
{
    while(scanf("%lld %lld",&n,&m) != EOF)
    {
        if(!n && !m)
            return 0 ;

        reset();
        Input();

        for(int i=1 ; i<=n ; i++)
            visit(i);

        publishresult();
    }
    return 0 ;
}

void reset()
{
    c = 0 ;

    for(int i=0 ; i<=n+10 ; i++)
    {
        check[i] = false ;
        graph[i].clear();
    }
}

void Input()
{
    long long int x , y ;

    for(int i=0 ; i<m ; i++)
    {
        scanf("%lld %lld",&x,&y);
        graph[x].push_back(y);
    }
}

void visit(long long int p)
{
    if(!check[p])
    {
        for(long long int i=0 ; i<graph[p].size() ; i++)
            visit(graph[p][i]);

        check[p] = true;
        result[c++] = p ;
    }
}

void publishresult()
{
    if(c != n)
        printf("IMPOSSIBLE\n");

    else
    {
        for(int i=n-1 ; i>=0 ; i--)
            printf("%lld\n",result[i]);
    }
}
