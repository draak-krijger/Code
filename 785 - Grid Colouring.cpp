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

char graph[100][100] , target ;
bool visit[100][100] ;
int fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} ;

void dfs(int x , int y);

int main()
{
    int l = 0 , length ;
//freopen("input.txt","r",stdin);
    while(gets(graph[0]))
    {
        l = 0 ;
        memset(visit[0],false,sizeof visit[0]);
        if(graph[0][0] != '_')
        {
            while(gets(graph[++l]))
            {
                memset(visit[l],false,sizeof visit[l]);
                if(graph[l][0] == '_')
                    break;
            }
        }

        for(int i=0 ; i<l ; i++)
        {
            length = strlen(graph[i]);

            for(int j=0 ; j<length ; j++)
            {
                if(graph[i][j] != 'X' && graph[i][j] != ' ' && graph[i][j] != '_')
                {
                    target = graph[i][j];
                    dfs(i,j);
                }
            }
        }

         for(int i=0 ; i<=l ; i++)
        {
            length = strlen(graph[i]);

            for(int j=0 ; j<length ; j++)
            {
                printf("%c",graph[i][j]);
            }
            printf("\n");
        }

    }
    return 0 ;
}

void dfs(int x , int y)
{
    if(graph[x][y] == 'X' || visit[x][y])
        return;

    visit[x][y] = true;
    graph[x][y] = target;

    for(int i=0 ; i<4 ; i++)
        dfs(x+fx[i],y+fy[i]);
}
