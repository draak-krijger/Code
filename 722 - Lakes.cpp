#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;
char graph[150][150] ;
char visit[150][150] ;
int m , n , cnt ;

void dfs(int u , int v)
{
    if(u<0 || u>=m || v<0 || v>=n || graph[u][v] == '1' || visit[u][v] == '1')
        return ;

    visit[u][v] = '1' ;
    cnt++ ;

    dfs(u,v+1);
    dfs(u,v-1);
    dfs(u+1,v);
    dfs(u-1,v);

}
int main()
{
    int tcase , i , j , u , v ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&u,&v);
        getchar();

        m=n=0 ;

        while(gets(graph[m]) && strlen(graph[m])>0)
        {
            memset(visit[m] , '0' , sizeof visit[m]);
            m++ ;
        }

        n = strlen(graph[0]);
        cnt = 0 ;
        dfs(u-1,v-1);

        printf("%d\n",cnt);

        if(tcase)
            printf("\n");

    }

    return 0 ;
}
