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
#define sz 51000

using namespace std ;

vector<int>graph[sz] ;
stack<int>order;
int n , cont ;
bool check[sz] , ck , finalcheck[sz] ;

void calculation(int cas);
void reset();
void dfs(int u);
void input();

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }

    return 0;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
    }

    while(!order.empty())
        order.pop();
}

void dfs(int u)
{
    check[u] = true;
    finalcheck[u] = true;
    cont++;

    for(int i=0 ; i<graph[u].size() ; i++)
        if(!check[graph[u][i]])
            dfs(graph[u][i]);

    if(ck)
        order.push(u);
}

void input()
{
    scanf("%d",&n);
    reset();

    int u , v ;

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].pb(v);
    }
}

void calculation(int cas)
{
    ck = true;

    for(int i=1 ; i<=n ; i++)
    {
        if(!check[i])
            dfs(i);
    }

    ck = false;
    fill(finalcheck,finalcheck+(n+1),false);
    int u , ans = 0 , indx = 0 ;

    while(!order.empty())
    {
        u = order.top();
        order.pop();

        if(!finalcheck[u])
        {
            fill(check,check+(n+1),false);
            cont = 0 ;
            dfs(u);

            if(cont>ans)
            {
                ans = cont;
                indx = u ;
            }

            else if(cont == ans)
            {
                if(u<indx)
                {
                    indx = u ;
                }
            }
        }
    }
    printf("Case %d: %d\n",cas,indx);
}
