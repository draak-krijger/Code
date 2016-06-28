#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define pb push_back
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

using namespace std ;

vector<int>graph[1000];
map<string,int>matrix;
int parent[1000] , level[1000] ;
void bfs(int v , int t);
void reset();
void ppath(int a) ;

int main()
{
    string s1 , s2 ;
    int tcase , cd ;
    bool check = false;
//    freopen("input.txt","r",stdin);
    while(scanf("%d",&tcase) != EOF)
    {
        cd = 1 ;
        reset();

        while(tcase--)
        {
            cin >> s1 >> s2 ;

            if(!matrix[s1])
                matrix[s1] = cd++;

            if(!matrix[s2])
                matrix[s2] = cd++;

            graph[matrix[s1]].pb(matrix[s2]);
            graph[matrix[s2]].pb(matrix[s1]);
        }

        cin >> s1 >> s2 ;

        bfs(matrix[s1],matrix[s2]);

        if(check)
            printf("\n");

        check = true;

        if(!matrix[s1] || !matrix[s2] || level[matrix[s2]] == 0)
            printf("No route\n");

        int rs = matrix[s2];
        ppath(rs);
    }
    return 0 ;
}

void bfs(int v , int t)
{
    int u ;
    char visit[1000] ;

    memset(visit, '0' , sizeof visit);
    queue<int>q ;

    q.push(v);
    visit[v] = '1' ;
    level[v] = 0 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        //if(u==t)
        //return;

        for(int i = 0  ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];

            if(visit[v] == '0')
            {
                visit[v] = '1' ;
                parent[v] = u ;
                level[v] = level[u] + 1 ;
                q.push(v);
            }
        }
    }
}

void reset()
{
    matrix.clear();

    for(int i=0 ; i<1000 ; i++)
    {
        graph[i].clear();
        parent[i] = 0 ;
        level[i] = 0 ;
    }
}

void ppath(int a)
{
    vector<int>path;

    while ( parent [a] != a)
    {
        path.push_back (a);
        a = parent [a];
    }

    reverse (path.begin (), path.end ());

    string city[1000];

    for(typeof(matrix.begin()) it = matrix.begin() ; it != matrix.end() ; it++)
    {
        city[(*it).second] = (*it).first;
    }


    for(int i = 1 ; i<path.size() ; i++)
    {
        cout << city[path[i-1]] <<' '<< city[path[i]] << endl ;
    }
}
