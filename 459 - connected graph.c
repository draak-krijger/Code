#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std ;

vector<char>graph[200];
char visit[200] , check[200] ;

void dfs(int v)
{
    int i ;

    if(visit[v] == '1')
        return ;

    visit[v] = '1';
    check[v] = '1';

    for(i=0 ; i<graph[v].size() ; i++)
        dfs(graph[v][i]);
}

int main()
{
    int i , j , cnt , tcase , k=0;
    char c , a[3] , b , vertex ;

    scanf("%d",&tcase);
    getchar();
    getchar();

    while(tcase--)
    {

        scanf("%c",&vertex);
        getchar();

        for(i='A' ; i<=vertex ; i++)
            graph[i].clear();

        while(gets(a) && a[0])
        {
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }

        cnt = 0 ;
        memset(visit , '0' , sizeof(visit));

        for(i='A' ; i<=vertex ; i++)
        {

            if(visit[i] == '0')
            {
                dfs(i) ;
                cnt++;
            }
        }

        if(k==1)
            printf("\n");

        k=1 ;

        printf("%d\n",cnt);
    }

    return 0 ;
}
