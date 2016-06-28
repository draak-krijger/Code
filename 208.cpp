#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std ;

vector<int>graph[50];
vector<int> parent[50]  ;
int a[50] , m ;
bool visit[40];

void bfs(int v)
{
    int u ;
    queue<int>Q;

    memset(visit , '0' , sizeof(visit));
    fill(visit,visit+39,true);

    Q.push(v);


    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if(visit[u])
        {
            visit[u] = false ;
            for(int i =0 ; i<graph[u].size() ; i++)
            {
                v = graph[u][i] ;
                parent[v].push_back(u) ;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int u , a , b , n  ;

    while(scanf("%d",&n) == 1)
    {
        for(int i = 0 ; i<30 ; i++)
            graph[i].clear();

        while(scanf("%d %d",&a,&b) == 2)
        {
            if(a==0 && b==0)
                break;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 0 ; i<30 ; i++)
            parent[i].clear();

        bfs(1);
        u = n ;

//        for(int i=1 ; i<10 ; i++)
//        {
//            cout << i << " ";
//            for(int j = 0 ; j<parent[i].size() ; j++)
//                printf("%d ",parent[i][j]);
//
//            cout << endl;
//        }
    }
    return 0 ;
}
