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
#define sz 100

using namespace std ;

void calculation(int cas);
void reset();
void bfs(jora home);
void input();

char graph[sz][sz] ;
bool check[sz][sz] ;
int m , n , fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} , level[sz][sz] ;
jora pos[5] , h ;

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
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            check[i][j] = false;
        }
    }
}

void bfs(jora home)
{
    queue<jora>q ;
    jora u , v ;

    q.push(home);
    level[home.first][home.second] = 0 ;
    check[home.first][home.second] = true;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++)
        {
            v.first = u.first + fx[i] ;
            v.second = u.second + fy[i] ;

            if(check[v.first][v.second] || v.first<0 || v.first>=m || v.second<0 || v.second>=n || graph[v.first][v.second] == '#' || graph[v.first][v.second] == 'm')
                continue;

            check[v.first][v.second] = true;
            level[v.first][v.second] = level[u.first][u.second] + 1 ;
            q.push(v);
        }
    }
}

void input()
{
    scanf("%d %d",&m,&n);
    getchar();
    int l=0 ;

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%c",&graph[i][j]);

            if(graph[i][j] == 'a' || graph[i][j] == 'b' || graph[i][j] == 'c')
            {
                pos[l].first = i ;
                pos[l++].second = j ;
            }

            if(graph[i][j] == 'h')
            {
                h.first = i ;
                h.second = j ;
            }
        }
        getchar();
    }
}

void calculation(int cas)
{
    reset();
    bfs(h);
    int maxm = 0 ;

    for(int i=0 ; i<3 ; i++)
        maxm = max(maxm,level[pos[i].first][pos[i].second]);

    printf("Case %d: %d\n",cas,maxm);
}
