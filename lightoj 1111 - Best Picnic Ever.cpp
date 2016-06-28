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
#define MAX 1500


using namespace std ;

vector<int>graph[MAX];
bool check[120][MAX] ;
int k , n , m , city[120] ;

void calculation(int cas);
void reset();
void dfs(int vk , int v);
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=(k+2) ; i++)
    {
        for(int j=0 ; j<=(n+2) ; j++)
        {
            if(i == 0)
                graph[j].clear();

            check[i][j] = false;
        }
    }
}

void dfs(int vk , int v)
{
    if(check[vk][v])
        return;

    check[vk][v] = true;

    for(int i=0 ; i<graph[v].size() ; i++)
        dfs(vk,graph[v][i]);
}

void input()
{
    scanf("%d %d %d",&k,&n,&m);

    reset();

    for(int i=0 ; i<k ; i++)
        scanf("%d",&city[i]);

    for(int i=0 ; i<m ; i++)
    {
        int u , v ;

        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
    }
}

void calculation(int cas)
{
    int cnt = 0 ;

    for(int i=0 ; i<k ; i++)
        dfs(i,city[i]);

    for(int i=1 ; i<=n ; i++)
    {
        bool ck = true;

        for(int j=0 ; j<k ; j++)
        {
            if(check[j][i])
                continue;

            ck = false;
            break;
        }

        if(ck)
            cnt++;
    }

    printf("Case %d: %d\n",cas,cnt);
}
