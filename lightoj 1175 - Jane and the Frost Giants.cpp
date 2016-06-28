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

using namespace std ;

char graph[250][250] ;
int m , n , level[3][250][250] , fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} , frc ;
bool check[250][250] ;
jora jp , fr[100000] ;

void calculation(int cas);
void reset();
void bfs(jora src , int indx);
void input();
void ireset();

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

void ireset()
{
    frc = 0 ;

    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            check[i][j] = false;
            level[0][i][j] = 1000000 ;
            level[1][i][j] = 1000000 ;
        }
    }
}

void reset()
{
    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            check[i][j] = false;
        }
    }
}

void bfs(jora src , int indx)
{
    jora top ;
    int u , v , valu ;
    queue<jora>q ;

    q.push(src) ;
    level[indx][src.first][src.second] = 0 ;
    check[src.first][src.second] = true;

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++)
        {
            u = top.first + fx[i] ;
            v = top.second + fy[i] ;

            if(u<0 || u>=m || v<0 || v>=n || check[u][v] || graph[u][v] == '#')
                continue;

            check[u][v] = true;

            if(indx)
            {
                valu =  level[indx][top.first][top.second] + 1 ;

                if(valu < level[indx][u][v])
                {
                    level[indx][u][v]  = valu;
                    q.push(jora(u,v));
                }
            }

            else
            {
                level[indx][u][v] = level[indx][top.first][top.second] + 1 ;
                q.push(jora(u,v));
            }
        }
    }
}

void input()
{
    scanf("%d %d",&m,&n);
    getchar();
    ireset();

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%c",&graph[i][j]);

            if(graph[i][j] == 'J')
            {
                jp.first = i ;
                jp.second = j ;
            }

            else if(graph[i][j] == 'F')
            {
                fr[frc].first = i ;
                fr[frc++].second = j ;
            }
        }
        getchar();
    }
}

void calculation(int cas)
{
    int time = 1000000 ;

    bfs(jp,0);

    for(int i=0 ; i<frc ; i++)
    {
        reset();
        bfs(fr[i],1);
    }

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(i>0 && i<m-1)
            {
                if(j > 0)
                    j = n-1;
            }

            if(graph[i][j] == '#')
                continue;

            if(level[0][i][j]<level[1][i][j])
                time = min(level[0][i][j],time);
        }
    }

    if(time == 1000000)
        printf("Case %d: IMPOSSIBLE\n",cas);

    else
        printf("Case %d: %d\n",cas,time+1);
}
