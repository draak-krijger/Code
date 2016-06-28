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

jora alphabet[40] ;
char graph[15][15] ;
bool check[15][15] , ck ;
int level[15][15] , n , fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} , k , dis ;

void input();
void bfs(jora src , jora dest);
void reset();
void calculation(int cas);

int main()
{
    int tcase ;
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);
    //getchar();

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0 ;
}

void reset()
{
    ck = false;
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            check[i][j] = false;
            level[i][j] = 0 ;
        }
    }
}

void bfs(jora src , jora dest)
{
    queue<jora>q ;
    jora top ;
    int x , y ;

    q.push(src);
    level[src.first][src.second] = 0 ;
    check[src.first][src.second] = true ;

    if(src.first == dest.first && src.second == dest.second)
    {
        ck = true;
        return;
    }

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++)
        {
            x = top.first + fx[i] ;
            y = top.second + fy[i] ;

            if(x<0 || x>=n || y<0 || y>=n || check[x][y] ||graph[x][y] == '#' || (isupper(graph[x][y]) && graph[x][y] != graph[dest.first][dest.second]))
                continue;

            check[x][y] = true;
            level[x][y] = level[top.first][top.second] + 1 ;

            if(dest.first == x && dest.second == y)
            {
                ck = true;
                break;
            }

            q.push(jora(x,y));
        }

        if(ck)
            break;
    }
}

void input()
{
    int m ;
    k = 0 ;
    char ns[10] ;

    scanf("%d",&n);
    getchar();

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%c",&graph[i][j]);

            if(isupper(graph[i][j]))
            {
                m = graph[i][j] - 'A' ;

                k++;

                alphabet[m].first = i ;
                alphabet[m].second = j ;
            }
        }
        getchar();
    }
}

void calculation(int cas)
{
    dis = 0 ;
    if(k>1)
    {
        for(int i=0 ; i<k-1 ; i++)
        {
            reset();
            bfs(alphabet[i],alphabet[i+1]);

            if(ck)
            {
                graph[alphabet[i].first][alphabet[i].second] = '.' ;
                dis += level[alphabet[i+1].first][alphabet[i+1].second] ;
            }

            else
                break;
        }
    }

    else
        ck  = true;

    if(ck)
        printf("Case %d: %d\n",cas,dis);

    else
        printf("Case %d: Impossible\n",cas);
}
