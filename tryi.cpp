// ==========================================================================
//
//                   Bismillah ir-Rahman ir-Rahim
//
// ==========================================================================

/*************************************************************************
  ████      ▀███▀    ▄▄▄▀▀▀▀▄▄▄   █▀▄▀▄▀▄▀▄▀▄█  ▀███▀   ████       ████
  ███ █      ███     ███    ███              █   ███    ███ █     █ ███
  ███  █     ███     ███    ███            █     ███    ███  █   █  ███
  ███   █    ███     ███    ███          █       ███    ███   █▄█   ███
  ███    █   ███     ███▀▀▀▀███        █         ███    ███         ███
  ███     █  ███     ███    ███      █           ███    ███         ███
  ███      █ ███     ███    ███    █             ███    ███         ███
 ▄███▄      ████     ███    ███   █▄▀▄▀▄▀▄▀▄▀█  ▄███▄  ▄███▄       ▄███▄
**************************************************************************/

//#include <bits/stdc++.h>

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
#define Max 15000000+9
#define sz 250+7
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

/// --------------------------------------------- EOP --------------------------------------------- ///

vector<int>graph[sz] , cost[sz] ;
double dp[sz][115] , expected[sz][115] , probability[sz] ;
int visit[sz][115] , now , t , par[sz] , level[sz] ;

void reset()
{
    for(int i=0 ; i<sz ; i++)
    {
        graph[i].clear();
        cost[i].clear();
        par[i] = -1 ;
        level[i] = -1 ;
    }
}

void dijkastra()
{
    set<jora_int>st ;
    jora_int temp ;
    int u , v ;

    level[0] = 0 ;
    st.insert(mp(0,0));

    while(!st.empty())
    {
        temp = *st.begin();
        st.erase(st.begin());

        u = temp.sc ;

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(level[v] == -1 or level[u]+cost[u][i] < level[v])
            {
                level[v] = level[u] + cost[u][i] ;
                st.insert(mp(level[v],v));
            }
        }
    }
}

void rec(int node,int tme)
{
    if(tme>=t)
    {
        dp[node][tme] = probability[node] ;
        expected[node][tme] = (double)level[node];
        return ;
    }

    double& ret = dp[node][tme] ;
    double& ept = expected[node][tme] ;

    if(visit[node][tme] == now)
        return ;

    ret = 0.0 ;
    ept = 0.0 ;

    int siz = graph[node].size() , v ;

    for(int i=0 ; i<siz ; i++)
    {
        v = graph[node][i] ;

        if(v == 0)
            continue;

        rec(v,tme+cost[node][i]);

        ret += dp[v][tme+cost[node][i]] ;
        ept += (cost[node][i] + expected[v][tme+cost[node][i]]);
    }

    ret = ret*(1.0-probability[node]);
    ept = ept*(1.0-probability[node]);

    if(graph[node].size() == 1 and graph[node][0] == 0)
        rec(0,tme+level[node]) , ret = (1.0 - probability[node])*dp[0][tme+level[node]] , ept = (1.0 - probability[node])*(cost[node][0] + expected[0][tme+level[node]]) ;

    else if(siz>0)
    {
        if(par[node] == 0)
            siz--;

        ret = ret/(double)siz ;
        ept = ept/(double)siz ;
    }

    ret += probability[node] ;
    ept += probability[node]*(double)level[node];

    visit[node][tme] = now ;
}

int main()
{
//    Write;
    int tcase , n , m , u , v, w ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,m);
        sf1(t);

        reset();

        probability[0] = 0.0 ;

        for(int i=1 ; i<=n ; i++)
            sf("%lf",&probability[i]);

        for(int i=0 ; i<m ; i++)
        {
            sf2(u,v);
            sf1(w);

            if(u == 0)
                par[v] = 0 ;

            else if(v == 0)
                par[u] = 0 ;

            graph[u].pb(v);
            graph[v].pb(u);

            cost[u].pb(w);
            cost[v].pb(w);
        }

        dijkastra();

        now++;

        rec(0,0);

        double ans = dp[0][0] ;

        pf("Case %d: %.5f %.5f\n",cas,ans,expected[0][0]);
    }

    return 0 ;
}

/*

8
6 8 15
.2 .4 .3 .5 .7 .8
0 1 3
1 2 4
2 3 7
2 4 6
1 5 4
0 6 2
5 4 6
3 1 3

7 9 15
.2 .4 1 .5 .7 .8 .68
0 1 3
1 2 4
2 3 7
2 4 6
1 5 4
0 6 2
5 4 6
3 1 3
0 7 2

1 1 15
.6
0 1 2

2 0 15
.5 .6

3 3 15
0 0 0
0 1 2
0 2 4
0 3 5

3 3 15
0 0 1
0 1 2
0 2 4
0 3 5

3 3 1
1 1 1
0 1 2
0 2 4
0 3 5

2 3 20
.5 .3
0 1 1
0 2 15
1 2 2

*/
