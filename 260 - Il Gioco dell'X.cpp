#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

char graph[300][300] , visit[300][300];
int m ;
bool check ;

void dfs(int i , int j)
{
    if(i<0 || i>=m || j<0 || j>=m || graph[i][j] == 'b')
        return ;

    graph[i][j] = 'b' ;
    visit[i][j] = '1';

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i+1,j+1);
    dfs(i-1,j);
    dfs(i-1,j-1);
}

int main()
{
    int i , j , k=0;

    while(scanf("%d",&m) != EOF)
    {
        if(!m)
            return 0 ;

        for(i=0 ; i<m ; i++)
        {
            scanf("%s",graph[i]);
            memset(visit[i] , '0' , sizeof visit[i]);
        }

        check = true ;

        for(i=0 ; i<m ; i++)
        {
            if(graph[i][0] == 'w')
            {
                dfs(i,1);

                for(j=0 ; j<m ; j++)
                {
                    if(visit[j][m-1] == '1')
                    {
                        printf("%d W\n",++k);
                        check = false ;
                        break ;
                    }
                    memset(visit[j] , '0' , sizeof visit[j]);
                }
            }

            if(check == false)
                break ;
        }

        if(check)
            printf("%d B\n",++k);
    }
    return 0 ;
}
