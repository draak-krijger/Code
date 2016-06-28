#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZ 1000
vector<int> graph[SIZ];
char visit[SIZ];

void dfs(int v)
{
    if(visit[v]) return;
    visit[v] = 1;
    for(int i = 0; i<graph[v].size(); ++i)
    {
        dfs(graph[v][i]);
    }
}

int main()
{
    int u, v;
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    printf("Adjacency list - \n");
    for(int i = 1; i<=n; ++i)
    {
        printf("%d : ", i);
        for(int j = 0; j < graph[i].size(); ++j)
            printf(" %d", graph[i][j]);
        putchar('\n');
    }

    printf("query : \n");
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &v);

        memset(visit, 0, sizeof(visit));
        dfs(v);

        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(visit[i]) cnt++;
        }

        printf("vertices connected with %d is %d\n", v, cnt);
    }

    return 0;
}

/*
6
7
1 4
5 2
2 4
6 1
2 3
6 2
4 5
*/
