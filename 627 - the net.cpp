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

vector<int>graph[500] , par ;
int parent[500] ;
bool check[800] ;

void bfs(int source , int destina);

int main()
{
    int n , so , d , a , b , p ;
    char s[500] ;
    bool ck ;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n) == 1)
    {

        for(int i = 0 ; i<=350 ; i++)
            graph[i].clear();

        for(int i = 0 ; i<n ; i++)
        {
            scanf("%s",s);

            b = strlen(s);
            ck = true ;
            a = 0 ;

            for(int j = 0 ; j<b ; j++)
            {
                if(isdigit(s[j]))
                {
                    a = a*10 + (s[j] - '0');

                    if(j == b-1)
                    {
                        if(!ck)
                        {
                            graph[p].push_back(a);
                            a = 0 ;
                        }
                    }
                }

                else
                {
                    if(ck)
                    {
                        p = a ;
                        a = 0 ;
                        ck = false;
                    }

                    else
                    {
                        graph[p].push_back(a);
                        a = 0 ;
                    }
                }
            }
        }

        scanf("%d",&a);
        printf("-----\n");

        for(int i = 0 ; i<a ; i++)
        {
            scanf("%d %d",&so,&d);
            bfs(so,d);

            par.clear();

            if(!check[d])
            {
                while(1)
                {
                    par.push_back(d);

                    if(d == so)
                        break;
                    d = parent[d];
                }

                reverse(par.begin(),par.end());

                printf("%d",par[0]);

                for(int i = 1 ; i<par.size() ; i++)
                {
                    printf(" %d",par[i]);
                }

                printf("\n");
            }

            else
                printf("connection impossible\n");
        }
    }
    return 0 ;
}

void bfs(int source , int destina)
{
    int u , v ;
    queue<int>seq ;
    fill(check , check+350 , true);

    seq.push(source);
    check[source] = false ;

    while(!seq.empty())
    {
        u = seq.front();
        seq.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(check[v])
            {
                check[v] = false;

                parent[v] = u ;

                if(v == destina)
                    break;

                seq.push(v) ;
            }
        }

        if(v == destina)
            break;
    }
}
