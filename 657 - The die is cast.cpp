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

char graph[100][100] ;
bool visit[100][100] , xck[100][100] ;
int r , c , fx[] = {0,0,1,-1} , fy[] = {1,-1,0,0} , cont ;

void dfs1(int x , int y);
void dfs2(int x , int y);

int main()
{
    int cas=0 , u ;
    int ans[1000] ;

    while(scanf("%d %d",&c,&r) && (c||r))
    {
        getchar();

        for(int i = 0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                scanf("%c",&graph[i][j]);
                visit[i][j] = false;
                xck[i][j] = false;
            }
            getchar();
        }

        u = 0;

        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                if((graph[i][j] == '*' || graph[i][j] == 'X') && !visit[i][j])
                {
                    cont=0;
                    dfs1(i,j);
                    ans[u++] = cont ;
                }
            }
        }

        sort(ans,ans+u);

        printf("Throw %d\n%d",++cas,ans[0]);

        for(int i=1 ; i<u ; i++)
            printf(" %d",ans[i]);

        printf("\n\n");
    }
    return 0 ;
}

void dfs1(int x , int y)
{
    if(graph[x][y] == '.' || visit[x][y] || x<0 || y<0 || x==r || y==c)
        return;

    if(graph[x][y] == 'X' && !xck[x][y])
    {
        cont++;
        dfs2(x,y);
    }

    visit[x][y] = true;

    for(int i=0 ; i<4 ; i++)
    {
        dfs1(x+fx[i],y+fy[i]);
    }
}

void dfs2(int x , int y)
{
    if(graph[x][y] != 'X' || xck[x][y] || x<0 || y<0 || x==r || y==c)
        return;

    xck[x][y] = true;

    for(int i=0 ; i<4 ; i++)
    {
        dfs2(x+fx[i],y+fy[i]);
    }
}

