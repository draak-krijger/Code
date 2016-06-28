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

vector<int>graph[200];
bool visit[200];
int n , cont ;
void reset();
void inputdata();
void dfs(int u);

int main()
{
    int fcount , indx ;
    while(scanf("%d",&n) != EOF && n)
    {
        reset();
        inputdata();

        fcount = 0;
        indx = 0 ;

        for(int i=1 ; i<=n ; i++)
        {
            cont=0;
            dfs(i);

            if(cont>fcount)
            {
                fcount = cont;
                indx = i ;
            }

            if(i != n)
                fill(visit,visit+(n+10),true);
        }

        printf("%d\n",indx);
    }
    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=n+10 ; i++)
    {
        graph[i].clear();
        visit[i] = true;
    }
}

void inputdata()
{
    int m , p ;

    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&m);

        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&p);
            graph[i].push_back(p);
        }
    }
}

void dfs(int u)
{
    if(!visit[u])
        return;

    visit[u] = false;
    cont++;

    for(int i=0 ; i<graph[u].size(); i++)
        dfs(graph[u][i]);
}
