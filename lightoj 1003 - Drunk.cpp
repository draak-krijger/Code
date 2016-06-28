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

map<string,int>mymap ;
vector<int>graph[2*sz] ;
int l , m , visit[2*sz] , cycle ;

void calculation(int cas);
void reset();
void checkcycle(int u);
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0 ;
}

void reset()
{
    mymap.clear();
    for(int i=0 ; i<=2*m+2 ; i++)
    {
        graph[i].clear();
        visit[i] = 0 ;
    }
}

void checkcycle(int u)
{
    if(cycle || visit[u] == 2)
        return;

    if(visit[u] == 1)
    {
        cycle = 1 ;
        return;
    }

    visit[u] = 1 ;

    for(int i=0 ; i<graph[u].size() ; i++)
        checkcycle(graph[u][i]);

    visit[u] = 2 ;
}

void input()
{
    char s1[20] , s2[20] ;
    l = 1 ;

    scanf("%d",&m);
    reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%s %s",s1,s2);

        if(!mymap[s1])
            mymap[s1] = l++;

        if(!mymap[s2])
            mymap[s2] = l++;

        graph[mymap[s1]].pb(mymap[s2]);
    }
}

void calculation(int cas)
{
    bool ck = true;
    cycle = 0 ;

    for(int i=1 ; i<l ; i++)
    {
        if(!visit[i])
        {
            checkcycle(i);

            if(cycle)
            {
                ck = false;
                break;
            }
        }
    }

    if(ck)
        printf("Case %d: Yes\n",cas);

    else
        printf("Case %d: No\n",cas);
}
