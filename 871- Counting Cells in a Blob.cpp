#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

char matrix[50][50];
int cont=0 , fx[]={-1, 0, 1,1,1,0,-1,-1} , fy[] ={-1,-1,-1,0,1,1, 1, 0} , r ;
bool check[50][50];

void reset();
void dfs(int x, int y);

int main()
{
    int tcase , finall ;
    char c[50] ;
    bool blank = false;
 //   freopen("input.txt","r",stdin);
    scanf("%d",&tcase);
    getchar();
    getchar();

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        reset();
        finall = 0 ;

        int i=0 ;

        while(gets(c) && strlen(c)>0)
        {
            strcpy(matrix[i++],c);
        }

        r = strlen(matrix[0]);

        for(int i=0 ; i<r ; i++)
        {
            for(int j=0 ; j<r ; j++)
            {
                if(matrix[i][j] == '1' && !check[i][j])
                {
                    cont = 0 ;
                    dfs(i,j);

                    if(cont>finall)
                        finall = cont ;
                }
            }
        }

        if(blank)
            printf("\n");

        blank = true ;

        printf("%d\n",finall);
    }
    return 0 ;
}

void dfs(int x, int y)
{
    if(check[x][y] || x<0 || x>=r || y<0 || y>=r)
        return;

    cont++;
    check[x][y] = true;

    int u , v ;

    for(int i=0 ; i<8 ; i++)
    {
        u = x+fx[i];
        v = y+fy[i];

        if(matrix[u][v] == '1')
            dfs(u,v);
    }
}

void reset()
{
    for(int i=0 ; i<=26 ; i++)
    {
        for(int j=0 ; j<=26 ; j++)
        {
            check[i][j] = false;
            matrix[i][j] = '0' ;
        }
    }
}
