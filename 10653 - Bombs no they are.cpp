#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define ds pair<int ,int >

using namespace std ;

char graph[1500][1500] , visit[1500][1500];
int row , clm , level[1500][1500] , x1[] = {0,0,1,-1} , y1[] = {1 , -1 , 0 , 0} ;

void bfs(int a , int b)
{
    int i , j , tx , ty ;
    ds top ;
     queue<ds>q ;
     memset(visit , '0' , sizeof(visit));
     q.push(ds(a,b));
     visit[a][b] = '1';
     level[a][b] = 0 ;

     while(!q.empty())
     {
         top = q.front();
         q.pop();

         for(i=0 ; i<4 ; i++)
         {
             tx = top.first + x1[i];
             ty = top.second + y1[i];

             if(tx>=0 && tx<row && ty>=0 && ty<clm && graph[tx][ty] != '1' && visit[tx][ty] == '0')
             {
                 visit[tx][ty] = '1';
                 level[tx][ty] = level[top.first][top.second] +1 ;
                 q.push(ds(tx,ty));
             }
         }
     }
}

int main()
{
    int rb , rbc , cbc , nc , i , j , sx , sy , fx , fy ;

    while(scanf("%d %d",&row,&clm) == 2)
    {
        if( !row && !clm)
            return 0;

        for(i=0 ; i<=row ; i++)
            memset(graph[i] ,'0' , sizeof(graph[i]));

        scanf("%d",&rb);

        for(i=0 ; i<rb ; i++)
        {
            scanf("%d",&rbc);
            scanf("%d",&nc);

            for(j=0 ; j<nc ; j++)
            {
                scanf("%d",&cbc);
                graph[rbc][cbc] = '1';
            }
        }

        scanf("%d %d",&sx,&sy);
        scanf("%d %d",&fx,&fy);

        bfs(sx,sy);

        printf("%d\n",level[fx][fy]);
    }
    return 0 ;
}
