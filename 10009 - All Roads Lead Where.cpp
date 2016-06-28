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

using namespace std;

vector<int>graph[100] , ppath ;
int parent[100] ;
bool check[100] ;

void bfs(int src , int dest);
void bfs_reset();

int main()
{
    int tcase , n , m , u , v ;
    char s1[1000] , s2[1000] ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&m,&n);

        for(int i= 0 ; i<=50 ; i++)
            graph[i].clear();

        for(int i = 0 ; i<m ; i++)
        {
            scanf("%s %s",s1,s2);

            u = s1[0] - 'A' ;
            v = s2[0] - 'A' ;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0 ; i<n ; i++)
        {
            scanf("%s %s",s1,s2);

            u = s1[0] - 'A';
            v = s2[0] - 'A';

            bfs(u,v);
        }

        if(tcase)
            printf("\n");

    }
    return 0 ;
}

void bfs_reset()
{
    for(int i = 0 ; i<=50 ; i++)
    {
        parent[i] = 0 ;
        check[i] = true;
    }
}

void bfs(int src , int dest)
{
    int u , v ;
    queue<int>seq ;
    bfs_reset();

    seq.push(src);
    check[src] = false ;

    while(!seq.empty())
    {
        u = seq.front();
        seq.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(check[v])
            {
                parent[v] = u ;
                check[v] = false;
                seq.push(v);
            }
        }
    }

    ppath.clear();

    while(1)
    {
        ppath.push_back(dest);

        if(dest == src)
            break;

        dest = parent[dest];
    }

    reverse(ppath.begin(),ppath.end());

    for(int i = 0 ; i<ppath.size() ; i++)
        printf("%c",ppath[i]+'A');

    printf("\n");
}
