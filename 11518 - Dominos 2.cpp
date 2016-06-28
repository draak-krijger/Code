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

using namespace std ;

vector<int>graph[10010] ;
bool visit[10010]  ;
int cont ;

void dfs(int u);

int main()
{
    int l , m , n , x , y , tcase ;
    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d %d",&n,&m,&l);

        for(int i=0 ; i<=n ; i++)
        {
            visit[i] = false;
            graph[i].clear();
        }

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&x,&y);
            graph[x].push_back(y);
        }

        cont = 0 ;

        for(int i=0 ; i<l ; i++)
        {
            scanf("%d",&x);
            dfs(x);
        }
        printf("%d\n",cont);
    }
    return 0 ;
}

void dfs(int u)
{
    if(visit[u])
        return;

    cont++;
    visit[u] = true;

    for(int i=0 ; i<graph[u].size() ; i++)
        dfs(graph[u][i]);
}
