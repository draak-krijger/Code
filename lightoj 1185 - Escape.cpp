#include <bits/stdc++.h>

using namespace std ;

struct node
{
    int v;
    bool check;
};

vector<int>graph[105] ;
bool check[105] , ck[105] , fck[105] , par[105] ;
int n , cont ;

void bfs();
void Reset();
void input();
void calculation(int cas);

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void Reset()
{
    cont = 0 ;
    for(int i=1 ; i<=n ; i++)
    {
        graph[i].clear();
        check[i] = false;
        ck[i] = true;
        fck[i] = true;
        par[i] = false;
    }
}

void input()
{
    int m , u , v ;

    scanf("%d %d",&n,&m);
    Reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs()
{
    int u , v ;
    node  _u , _v ;
    queue<node>q ;

    _u.v = 1 ;
    _u.check = false;
    check[1] = false;
    q.push(_u);

    while(!q.empty())
    {
        _u = q.front();
        q.pop();

        for(int i=0 ; i<graph[_u.v].size() ; i++)
        {
            v = graph[_u.v][i];
            _v.v = v ;

            if(_u.check)
            {
                if(fck[v])
                {
                    if(check[v] && par[v])
                    {
                        check[v] = false;
                        fck[v] = false;
                        _v.check = false;
                    }

                    else
                        _v.check = false;
                }

                if(ck[v])
                {
                    cont++;
                    ck[v] = false;
                }
            }

            else
            {
                if(fck[v])
                {
                    if(check[v] && !par[v])
                    {
                        check[v] = false;
                        fck[v] = false;
                        _v.check = false;
                    }

                    else
                    {
                        _v.check = true;
                        par[v] = true;
                    }
                }
                _v.check = true;
            }

            if(check[v])
                continue;

            check[v] = true;
            q.push(_v);
        }
    }
}

void calculation(int cas)
{
    bfs();
    printf("Case %d: %d\n",cas,cont);
}
