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
#define pii pair<int,int>

using namespace std ;

struct point
{
    int x , y , k ;
};

int m , n , fx[] = {1,1,2,2,-1,-1,-2,-2} , fy[] = {2,-2,1,-1,2,-2,1,-1} , cont , l , level[12][12] ;
char matrix[15][15] ;
bool check[12][12] , cc ;
point sat[150];

void calculation(int cas);
void bfs(pii src);
void reset();
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

void bfs(pii src)
{
    queue<pii>q ;
    pii top ;
    int x , y ;

    q.push(src);
    level[src.first][src.second] = 0 ;
    check[src.first][src.second] = true;

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        for(int i=0 ; i<8 ; i++)
        {
            x = top.first + fx[i] ;
            y = top.second + fy[i] ;

            if(x<0 || x>=m || y<0 || y>=n || check[x][y])
                continue;

            q.push(pii(x,y)) ;
            check[x][y] = true ;
            level[x][y] = level[top.first][top.second] + 1 ;
        }
    }
}

void reset()
{
    cc = false;
    cont = 0 ;

    for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            check[i][j] = false;
            level[i][j] = 0 ;
        }
    }
}

void calculation(int cas)
{
    int k , mincnt = 0 , i , j , finalcont = 100000 ;

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            reset();
            mincnt = 0 ;

            bfs(pii(i,j));

            cc = true;

            for(int k=0 ; k<l ; k++)
            {
                if(check[sat[k].x][sat[k].y])
                {
                    if(level[sat[k].x][sat[k].y]>sat[k].k)
                        mincnt += ceil((double)level[sat[k].x][sat[k].y]/(double)sat[k].k);


                    else if(level[sat[k].x][sat[k].y]>0)
                        mincnt += 1 ;
                }

                else
                {
                    cc = false;
                    break;
                }
            }

            if(cc)
                finalcont = min(finalcont,mincnt);
        }
    }

    if(finalcont == 100000)
        printf("Case %d: -1\n",cas);

    else
        printf("Case %d: %d\n",cas,finalcont);
}

void input()
{
    l = 0 ;
    scanf("%d %d",&m,&n);
    getchar();

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%c",&matrix[i][j]);

            if(isdigit(matrix[i][j]))
            {
                sat[l].x = i ;
                sat[l].y = j ;
                sat[l++].k = matrix[i][j] - '0' ;
            }
        }
        getchar();
    }
}
