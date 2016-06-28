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

using namespace std ;

int prime[1010] , level[1010] , s , t ;
vector<int>result ;
bool check[1010] ;

void inpcal(int cas);
void reset();
void seave();
int bfs(int src, int dest);

int main()
{
    int tcase ;

    scanf("%d",&tcase);
    seave();

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }

    return 0;
}

void reset()
{
    for(int i=0 ; i<=(t+2) ; i++)
        check[i] = false;
}

void seave()
{
    int x = sqrt(1000);

    prime[1] = 1 ;

    for(int i=4 ; i<=1005 ; i+=2)
        prime[i] = 1;

    for(int i=3 ; i<=x ; i+=2)
    {
        if(!prime[i])
        {
            for(int j=i+i ; j<=1005 ; j+=i)
                prime[j] = 1;
        }
    }

    result.clear();
    result.push_back(2);

    for(int i=3 ; i<=1005 ; i+=2)
        if(!prime[i])
            result.pb(i);
}

int bfs(int src, int dest)
{
    queue<int>q ;
    int u , v , x , m , i ;

    q.push(src);
    level[src] = 0 ;

    if(src == dest)
        return level[dest];

    check[src] = true;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i=0 ; i<result.size() ; i++)
        {
            if(result[i]>=u)
            {
                i--;
                break;
            }
        }

        for(i ; i>=0 ; i--)
        {
            if(u%result[i] == 0)
            {
                v = u+result[i] ;

                if(check[v] || v>dest)
                    continue;

                level[v] = level[u] + 1 ;
                check[v] = true;
                q.push(v);

                if(v == dest)
                    return level[v];
            }
        }
    }
    return -1 ;
}

void inpcal(int cas)
{
    scanf("%d %d",&s,&t);
    reset();

    int ans = bfs(s,t);
    printf("Case %d: %d\n",cas,ans);
}
