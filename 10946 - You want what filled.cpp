#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std ;

struct result
{
    char ch ;
    int coun ;
};

int r , c , cont , fx[] = {0,0,1,-1,} , fy[] = {1,-1,0,0} ;
char matrix[70][70] , cha ;
bool check[70][70] ;
result fresult[7000] ;

void reset();
void dfs(int x , int y);
bool cmp(result p , result q);

int main()
{
    int cas = 0 ;

    while(scanf("%d %d",&r,&c) != EOF)
    {

        if(r==0 && c==0)
            break;

        reset();

        for(int i=0 ; i<r ; i++)
        {
            scanf("%s",matrix[i]);
        }

        int k = 0 ;

        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<c ; j++)
            {
                cont = 0 ;

                if(isalpha(matrix[i][j]) && !check[i][j])
                {
                    cha = matrix[i][j] ;
                    dfs(i,j);

                    fresult[k].ch = matrix[i][j];
                    fresult[k++].coun = cont ;
                }
            }
        }

        sort(fresult , fresult+k , cmp);
        printf("Problem %d:\n",++cas);

        for(int i = 0 ; i<k ; i++)
        {
            if(fresult[i].coun == 0)
                break;

            printf("%c %d\n",fresult[i].ch,fresult[i].coun);
        }
    }
    return 0 ;
}

void dfs(int x , int y)
{
    if(check[x][y] || x<0 || x>=r || y<0 || y>=c)
        return ;

    check[x][y] = true;
    cont++;

    int u , v ;

    for(int i=0 ; i<4 ; i++)
    {
        u = x+fx[i];
        v = y+fy[i];

        if(cha == matrix[u][v])
            dfs(u,v);
    }
}

void reset()
{
    for(int i=0 ; i<=60 ; i++)
    {
        for(int j=0 ; j<=60 ; j++)
        {
            matrix[i][j] = '0';
            check[i][j] = false ;
        }
    }
}

bool cmp(result p , result q)
{
    if(p.coun<q.coun)
        return false;

    if(p.coun>q.coun)
        return true;

    return p.ch<q.ch;
}
