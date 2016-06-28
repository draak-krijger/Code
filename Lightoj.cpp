/**
  *                              ------------------------- ALLAH is Almighty -----------------------------
  *  @author: M. NAZIM UDDIN
  *  University: SUST
  *  OJ:
  *  problem name:
  *  Category :
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

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;

//define function

#pragma comment(linker, "/STACK:667772160")
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
#define Max 1000000
#define sz 10000+7
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
#define Read freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\input.txt","r",stdin)
#define Write freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\output.txt","w",stdout)
#define LN 14
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

vector<int>graph[sz] ;
int par[sz] , disc[sz] , low[sz] , belong[sz] , level[sz] , tme , scc , ans , cont ;
stack<int>st ;

void reset()
{
    for(int i=0 ; i<sz ; i++)
    {
        graph[i].clear();
        disc[i] = -1 ;
        belong[i] = -1 ;
        level[i] = -1 ;
        low[i] = -1 ;
        par[i] = -1 ;
    }

    while(!st.empty())
        st.pop();

    tme = 0 ;
    scc = 0 ;
    ans = 0 ;
    cont = 0 ;
}

bool bfs(int u)
{
    queue<int>q ;
    int v ;

    q.push(u);
    level[u] = 0 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(belong[v] != scc)
                continue;

            if(level[v] != -1)
            {
                if((level[v] + level[u])%2 == 0)
                    return 1 ;

                continue;
            }

            level[v] = level[u] + 1 ;
            q.push(v);
        }
    }

    return 0;
}

void tarjan(int prnt,int u)
{
    st.push(u);
    low[u] = disc[u] = ++tme ;

    int v ;

    for(int i=0 ; i<graph[u].size() ; i++)
    {
        v = graph[u][i] ;

        if(disc[v] == -1)
        {
            par[v] = u ;
            tarjan(u,v);
            low[u] = min(low[u],low[v]);
        }

        else if(par[u] != v)
        {
            low[u] = min(low[u],disc[v]);
        }
    }

    if(low[u] == disc[u])
    {
        ++scc ;
        v = u ;
        cont = 0 ;

        do
        {
            v = st.top();
            belong[v] = scc ;
            st.pop();
            cont++;
        }
        while(u != v) ;

        if(bfs(u))
            ans += cont ;
    }
}

int main()
{
    int tcase ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        reset();

        int n , m , u , v ;

        sf2(n,m);

        for(int i=0 ; i<m ; i++)
        {
            sf2(u,v);

            graph[u].pb(v) ;
            graph[v].pb(u) ;
        }

        for(int i=0 ; i<n ; i++)
            if(disc[i] == -1)
            tarjan(-1,i);

        pf("Case %d: %d\n",cas,ans);
    }

    return 0;
}
