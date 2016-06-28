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

jora command[12][12] , r[3] , X[3] , parent[12][12] ;
int level[13][13] , fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} , n ;
bool check[13][13] ;
char matrix[13][13] ;
vector<jora>finalcommand ;

void bfs(jora src , jora dest);
void reset();
bool cmdaply(jora src);
void input();
void calculation(int cas);

int main()
{
    int tcase ;
    //freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0 ;
}

void bfs(jora src , jora dest)
{
    queue<jora>q ;
    jora top ;
    int x , y ;
    bool ck = false;

    q.push(src);
    command[src.first][src.second].first = 0 ;
    command[src.first][src.second].second = 0 ;
    level[src.first][src.second] = 0 ;
    check[src.first][src.second] = true;

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++)
        {
            x = top.first + fx[i] ;
            y = top.second + fy[i];

            if(x<0 || x>=n || y<0 || y>=n || check[x][y] || (matrix[x][y] != '.' && matrix[x][y] != 'X'))
                continue;

            check[x][y] = true;
            command[x][y].first = fx[i];
            command[x][y].second = fy[i];
            level[x][y] = level[top.first][top.second] + 1 ;
            parent[x][y].first = top.first ;
            parent[x][y].second = top.second ;

            if(x == dest.first && y == dest.second)
                break;

            q.push(jora(x,y));
        }

        if(x == dest.first && y == dest.second)
        {
            ck = true;
            break;
        }
    }

    finalcommand.clear();

    if(ck)
    {
        int p , q ;

        while(1)
        {
            if(x == src.first && y == src.second)
                break;

            p = x ;
            q = y ;

            finalcommand.push_back(command[x][y]);
            x = parent[p][q].first;
            y = parent[p][q].second;
        }
    }
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=n ; j++)
            check[i][j] = false;
    }
}

bool cmdaply(jora src)
{
    int x = src.first , y = src.second , r2 , c ;

    for(int i = finalcommand.size()-1 ; i>=0 ; i--)
    {
        r2 = x + finalcommand[i].first ;
        c = y + finalcommand[i].second ;

        if(r2<0 || r2>=n || c<0 || c>=n || (matrix[r2][c] != '.' && matrix[r2][c] != 'X'))
            continue;

        x = r2 ;
        y = c ;
    }

    if(matrix[x][y] == 'X')
    {
        matrix[x][y] = 'D';
        return true;
    }

    return false;
}

void input()
{
    int sr = 0 , ds = 0 ;
    scanf("%d",&n);
    getchar();

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%c",&matrix[i][j]);

            if(matrix[i][j] == 'A' || matrix[i][j] == 'B' || matrix[i][j] == 'C')
            {
                r[sr].first = i ;
                r[sr++].second = j ;
            }

            if(matrix[i][j] == 'X')
            {
                X[ds].first = i ;
                X[ds++].second = j ;
            }
        }
        getchar();
    }
}

void calculation(int cas)
{
    int minlevel = 100000 ;
    bool ck ;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            reset();
            bfs(r[i],X[j]);

            if(!finalcommand.empty())
            {
                matrix[r[i].first][r[i].second] = '.';
                matrix[X[j].first][X[j].second] = 'D';
                ck = true;

                for(int k=2 ; k>=0 ; k--)
                {
                    if(k == i)
                        continue;

                    if(cmdaply(r[k]))
                    {
                        matrix[r[k].first][r[k].second] = '.';
                        continue;
                    }

                    else
                    {
                        ck = false;
                        break;
                    }
                }

                for(int k=0 ; k<3 ; k++)
                {
                    matrix[r[k].first][r[k].second] = 'A';
                    matrix[X[k].first][X[k].second] = 'X';
                }

                matrix[r[i].first][r[i].second] = '.';
                matrix[X[j].first][X[j].second] = 'D';

                for(int k=0 ; k<3 ; k++)
                {
                    if(k == i)
                        continue;

                    if(cmdaply(r[k]))
                    {
                        matrix[r[k].first][r[k].second] = '.';
                        continue;
                    }

                    else
                    {
                        if(!ck)
                            ck = false;
                        break;
                    }
                }

                for(int k=0 ; k<3 ; k++)
                {
                    matrix[r[k].first][r[k].second] = 'A';
                    matrix[X[k].first][X[k].second] = 'X';
                }

                if(ck)
                {
                    minlevel = min(minlevel,level[X[j].first][X[j].second]);
                }
            }
        }
    }

    if(minlevel == 100000)
        printf("Case %d: trapped\n",cas);

    else
        printf("Case %d: %d\n",cas,minlevel);
}
