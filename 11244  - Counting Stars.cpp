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

int row , colmn , cont , fx[] = {0,0,1,1,1,-1,-1,-1} , fy[] = {1,-1,1,0,-1,1,0,-1} ;
char matrix[150][150] ;

void dfs(int x , int y);

int main()
{
    int fcount ;

    while(scanf("%d %d",&row,&colmn) == 2 && (row&&colmn))
    {
        for(int i=0 ; i<row ; i++)
            scanf("%s",matrix[i]);

        fcount = 0 ;

        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<colmn ; j++)
            {
                if(matrix[i][j] == '*')
                {
                    cont = 0 ;
                    dfs(i,j);

                    if(cont == 1)
                        fcount++;
                }
            }
        }
        printf("%d\n",fcount);
    }
    return 0 ;
}

void dfs(int x , int y)
{
    if(matrix[x][y]!='*' || x<0 || y<0 || x==row || y==colmn)
        return;

    matrix[x][y] = '.' ;
    cont++;

    for(int i = 0 ; i<8 ; i++)
    {
        int u = x + fx[i] ;
        int v = y + fy[i] ;

        dfs(u,v);
    }
}
