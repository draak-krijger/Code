#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int visit[40] , n ;
int graph[50][50] ;

void dfs(int node)
{
    int i ;
    if(visit[node])
        return;

    visit[node] = 1 ;

    for(i=1 ; i<=n ; i++)
    {
        if(graph[node][i] != 0)
            dfs(i) ;
    }
}

int main()
{
    int v , i , j , cont;

    cin >> n ;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            cin >> graph[i][j] ;
    }

    while(cin >> v)
    {
        memset(visit , 0 , sizeof(visit));

        cont = 0 ;

        dfs(v) ;

        for(i=1 ; i<=n ; i++)
        {
            if(visit[i])
                cont++ ;
        }

        cout << cont << endl << endl ;
    }

    return 0 ;
}

