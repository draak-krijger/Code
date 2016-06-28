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

char graph[150][150] ;
int fx[] = {0,0,1,-1,1,-1,1,-1} , fy[] = {1,-1,0,0,1,-1,-1,1} , n ;

void dfs(int x , int y);

int main()
{
    int tcase , cont ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d",&n);

        for(int i=0 ; i<n ; i++)
            scanf("%s",graph[i]);

        cont = 0 ;

        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(graph[i][j] == 'x')
                {
                    cont++;

                    dfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n",cas,cont);
    }
    return 0 ;
}

void dfs(int x , int y)
{
    if(x<0 || x==n || y<0 || y==n || graph[x][y] == '.')
        return;

    graph[x][y] = '.';

    for(int i = 0 ; i<8 ; i++)
        dfs(x+fx[i],y+fy[i]);
}
