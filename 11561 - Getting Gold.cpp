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

int cont , m , fx[] = {0,0,1,-1} , fy[] = {1,-1,0,0} ;
char grid[100][100] ;
bool visit[100][100] ;

void dfs(int x , int y)
{
    if(grid[x][y] == '#' || visit[x][y])
        return;

    if(grid[x][y] == 'G')
        cont++;

    visit[x][y] = true;

    for(int i=0 ; i<4 ; i++)
        if(grid[x+fx[i]][y+fy[i]] == 'T')
            return;

    for(int i=0 ; i<4 ; i++)
        dfs(x+fx[i],y+fy[i]);
}

int main()
{
    int r , c , u , v ;

    while(scanf("%d %d",&c,&r) != EOF)
    {
        getchar();
        for(int i = 0 ; i<r ; i++)
        {
            for(int j = 0 ; j<c ; j++)
            {
                visit[i][j] = false;
                scanf("%c",&grid[i][j]);

                if(grid[i][j] == 'P')
                {
                    u = i ;
                    v = j ;
                }
            }
            getchar();
        }

        cont = 0 ;
        dfs(u,v);

        printf("%d\n",cont);
    }
    return 0 ;
}
