#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

char graph[150][150] , check[150][150] , f ;
int m , n , i1 , i2 ;
bool w ;

void dfs(int i , int j)
{
    if(j==n)
        j=0 ;

    else if(j==-1)
        j=n-1;

    if(i<0 || i>=m || j<0 || j>=n || graph[i][j] != f || check[i][j] == '1')
        return ;

    check[i][j] = '1' ;

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int region()
{
    int cnt = 0 , i , j ;

    for(i=0 ; i<m ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(check[i][j] == '1')
            {
                cnt++;

                if( i == i1 && j == i2)
                {
                    w = true ;
                    cnt=0;
                    break;
                }
            }
        }

        if(w)
            break;
    }
    return cnt ;
}

int main()
{
    int i , j , k , cnt , ind1 , ind2 , b ;

    while(scanf("%d %d",&m,&n) != EOF)
    {
        cnt = 0 ;
        for(i=0 ; i<m ; i++)
            scanf("%s",graph[i]);

        scanf("%d %d",&i1,&i2);

        f = graph[i1][i2];


        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
            {
                if(graph[i][j] == f)
                {
                    dfs(i,j);
                    w = false ;
                    b = region() ;

                    if(b>cnt)
                    {
                        cnt = b ;
                    }

                    for(k=0 ; k<m ; k++)
                        memset(check[k] , '0' , sizeof(check[k]));
                }
            }
        }

        printf("%d\n",cnt);

    }
    return 0 ;
}
