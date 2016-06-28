/**
  *                              ------------------------- ALLAH is Almighty -----------------------------
  *  @author: M. NAZIM UDDIN
  *  University: SUST
  *  OJ: CF
  *  problem name:
  * Category :
  */

// Pre_code

#include <bits/stdc++.h>

// header file

#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <numeric>
#include <cstring>

using namespace std ;

//define function

#pragma comment(linker, "/STACK:65536000")
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>n ; i--)
#define fore0(i,a,n) for(int i=a ; i>=n ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 10000000000000
#define sz 1000+7
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second
#define wait system("pause")
#define sf scanf
#define pf printf
#define mp make_pair
#define ps pf("PASS\n")
#define read freopen("input.txt","r",stdin)

//debug

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

// moves

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//close

int graph[sz][sz] , n , parent[sz] ,  inigraph[sz][sz] ;
bool visited[sz] ;

bool bfs(int s,int t)
{
    queue<int>q ;
    int u , v ;

    clr(visited,0);
    parent[s] = -1 ;

    q.push(s);
    visited[s] = 1 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=1 ; i<=n ; i++)
        {
            if(graph[u][i] and !visited[i])
            {
                visited[i] =  1 ;
                parent[i] = u ;
                q.push(i);
//deb(i,visited[i]);wait;
                if(i == t)
                    return 1;
            }
        }
    }
    return 0;
}

void dfs(int u)
{
    visited[u] = 1 ;

    for(int i=1 ; i<=n ; i++)
    {
        if(u != i and !visited[i] and graph[u][i])
            dfs(i);
    }
}

int max_flow(int s,int t)
{
    int u , v , maxm_flow = 0;

    while(bfs(s,t))
    {
        int mn = 1000000000 ; // set infinity

        for(int i=t ; i!=s ; i = parent[i])
        {
            int v = parent[i] ;

            mn = min(mn,graph[v][i]);
        }

        for(int i=t ; i!=s ; i = parent[i])
        {
            int v = parent[i] ;

            graph[v][i] -= mn ;
            graph[i][v] += mn ;
        }
        maxm_flow += mn ;
    }

    clr(visited,0);

    dfs(s);

    pf("cut for minimum cost\n");

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(i == j)
                continue;

            if(visited[i] and !visited[j] and inigraph[i][j])
                pf("%d %d\n",i,j);
        }
    }

    return maxm_flow ;
}

int main()
{
    sf1(n);
    int m ;

    sf1(m);

    while(m--)
    {
        int u , v , cap ;
        sf2(u,v);
        sf1(cap);
        graph[u][v] = cap ;
        inigraph[u][v] = cap ;
    }

    int s, t ;

    sf2(s,t);

    int maxim_flow = max_flow(s,t);

    pf("%d\n",maxim_flow);

    return 0;
}
