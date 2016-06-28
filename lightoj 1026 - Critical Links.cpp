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
#define jora pair<int,int>
#define pb push_back
#define sz 11000

using namespace std ;

vector<int>graph[sz] ;
vector<jora>result ;
jora get ;
int def[sz] , low[sz] , n , tme , parent[sz] ;

bool cmp(jora p,jora q);
void reset();
void input();
void bridge(int u);
void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void reset()
{
    result.clear();
    tme = 0 ;
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        def[i] = -1;
        parent[i] = -1;
    }
}

void input()
{
    int k , u , v ;
    char ch ;

    scanf("%d",&n);
    reset();

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d%c%c%d%c",&u,&ch,&ch,&k,&ch);

        for(int j=0 ; j<k ; j++)
        {
            scanf("%d",&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
    }
}

void bridge(int u)
{
    def[u] = low[u] = tme++;
    int v ;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(def[v] == -1)
        {
            parent[v] = u ;
            bridge(v);
            low[u] = min(low[u],low[v]);

            if(low[v]>def[u])
            {
                get.first = min(u,v);
                get.second = max(u,v);
                result.push_back(get);
            }
        }

        else if(v != parent[u])
            low[u] = min(low[u],def[v]);
    }
}

void calculation(int cas)
{
    for(int i=0 ; i<n ; i++)
        if(def[i] == -1)
            bridge(i);

    sort(result.begin(),result.end(),cmp);

    printf("Case %d:\n",cas);
    printf("%d critical links\n",result.size());

    for(int i=0 ; i<result.size() ; i++)
    {
        printf("%d - %d\n",result[i].first,result[i].second);
    }
}

bool cmp(jora p,jora q)
{
    if(p.first<q.first)
        return true;

    else if(p.first == q.first)
    {
        if(p.second<q.second)
            return true;
    }

    return false;
}
