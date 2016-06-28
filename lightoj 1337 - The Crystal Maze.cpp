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

using namespace std ;

vector<jora>vak ;

struct point
{
    int row , col ;
};

point position[1100] ;
bool check[510][510] ;
char graph[510][510] ;
int n , m , q , cont , fx[] = {1,-1,0,0} , fy[] = {0,0,1,-1} , level[510][510] ;

void reset();
void dfs(int x , int y);
void input();
void calculation(int cas);
void levset();

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
    cont = 0 ;
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=m ; j++)
        {
            check[i][j] = false;
            level[i][j] = 0 ;
        }
    }
}

void dfs(int x , int y)
{
    if(x<1 || x>n || y<1 || y>m || check[x][y] || graph[x][y] == '#')
        return;

    check[x][y] = true;
    vak.pb(jora(x,y));

    if(graph[x][y] == 'C')
        cont++;

    for(int i=0 ; i<4 ; i++)
        dfs(x+fx[i],y+fy[i]);
}

void input()
{
    scanf("%d %d %d",&n,&m,&q);
    getchar();

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            scanf("%c",&graph[i][j]);
        }
        getchar();
    }

    for(int i=0 ; i<q ; i++)
        scanf("%d %d",&position[i].row,&position[i].col);
}

void levset()
{
    for(int i=0 ; i<vak.size() ; i++)
        level[vak[i].first][vak[i].second] = cont;
}

void calculation(int cas)
{
    printf("Case %d:\n",cas);

    reset();

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=m ; j++)
        {
            if(!check[i][j])
            {
                vak.clear();
                cont = 0;
                dfs(i,j);
                levset();
            }
        }
    }

    for(int i=0 ; i<q ; i++)
        printf("%d\n",level[position[i].row][position[i].col]);

}
