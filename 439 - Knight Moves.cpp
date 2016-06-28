#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define jora pair<int, int>

using namespace std ;
int level[10][10] ;
int finalx , finaly ;
int a[] = {-2,-2,-1,-1,1,1,2,2} , b[] = {1,-1,2,-2,2,-2,1,-1} ;

void bfs(int u , int v)
{
    jora top ;
    int i , j , k , x , y , visit[10][10] = {0};
    bool check = false ;
    queue<jora>q;

    q.push(jora(u,v));
    visit[u][v] = 1 ;
    level[u][v] = 0 ;

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        for(i=0 ; i<8 ; i++)
        {
            x = top.first + a[i] ;
            y = top.second + b[i] ;

            if(x>0 && x<=8 && y>0 && y<=8 && visit[x][y] == 0)
            {
                q.push(jora(x,y));
                visit[x][y] = 1 ;
                level[x][y] = level[top.first][top.second] + 1 ;

                if(x == finalx && y == finaly)
                {
                    check = true ;
                    break;
                }
            }
        }
        if(check)
            break;
    }
}

int main()
{
    int a , b , i , j ;
    char s[50] ;

    while(gets(s))
    {
        for(i=0 ; i<=10 ; i++)
            memset(level[i] , 0 , sizeof level);

        b = s[0] - 'a' + 1;
        a = s[1] - '0' ;

        finaly = s[3] - 'a' + 1;
        finalx = s[4] - '0' ;

        bfs(a,b);
        printf("To get from %c%c to %c%C takes %d knight moves.\n",s[0],s[1],s[3],s[4],level[finalx][finaly]);
    }
    return  0;
}
