#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std ;

vector<int>graph[250];
bool visit[250] , yes , check ;
char colour[250] ;

void biocolourable()
{
    int u , i , v ;
    queue<int>str;

    str.push(0) ;
    check = true ;
    colour[0] = 'b';
    visit[0] = false;

    while(!str.empty())
    {
        u = str.front();
        str.pop();

        for(i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(visit[v])
            {
                str.push(v);
                visit[v] = false;

                if(colour[u] == 'b')
                    colour[v] = 'r';

                else
                    colour[v] = 'b';
            }

            else if(colour[u] == colour[v] && (colour[u] == 'r' || colour[u] =='b'))
            {
                yes = false;
                break;
            }
        }

        if(!yes)
            break;

        if(check)
            check = false;

        else
            check = true ;
    }
}

int main()
{
    int n , e , i , j , x , y ;

    while(scanf("%d",&n) != EOF)
    {
        if(n==0)
            break;

        scanf("%d",&e);

        for(i=0 ; i<=220 ; i++)
            graph[i].clear();

        for(i=0 ; i<e ; i++)
        {
            scanf("%d %d",&x,&y);

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        fill(visit,visit+220,true);
        memset(colour,'0', sizeof colour);

        yes = true ;
        biocolourable();

        if(yes)
            printf("BICOLORABLE.\n");

        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0 ;
}
