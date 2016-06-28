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

// Pre_code

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
#define Max 100500000000+9
#define sz 7000+7
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

vector<int>worker_edge , task_edge , normal_edge ;
ll edges , head[sz] , last[sz] , pre[sz] , cap[sz] , flw[sz] , tme[sz] , vip[sz] , regular[sz] , k , level[300] , next_edge[sz] ;

void reset()
{
    worker_edge.clear();
    task_edge.clear();
    normal_edge.clear();
    edges = 0 ;

    for(int i=0 ; i<sz ; i++)
    {
        pre[i] = -1 ;
        last[i] = -1 ;
        flw[i] = 0 ;
        cap[i] = 0 ;
    }
}

int add_edge(int u,int v)
{
    head[edges] = v ;
    pre[edges] = last[u] ;
    cap[edges] = 0 ;
    flw[edges] = 0 ;
    last[u] = edges++ ;

    head[edges] = u ;
    pre[edges] = last[v] ;
    cap[edges] = 0 ;
    flw[edges] = 0 ;
    last[v] = edges++ ;
}

void ini_graph(ll mid)
{
    ll u ;

    for(int i=0 ; i<normal_edge.size() ; i++)
    {
        u = normal_edge[i] ;

        cap[u] = Max ;
        flw[u] = 0 ;

        cap[u^1] = 0 ;
        flw[u^1] = 0 ;
    }

    for(int i=0 ; i<worker_edge.size() ; i++)
    {
        u = worker_edge[i] ;

        cap[u] = mid ;
        cap[u^1] = 0 ;

        flw[u] = 0 ;
        flw[u^1] = 0 ;
    }

    for(int i=0 ; i<task_edge.size() ; i++)
    {
        u = task_edge[i] ;

        cap[u] = vip[i+1] ;
        cap[u^1] = 0 ;

        flw[u] = 0 ;
        flw[u^1] = 0 ;
    }
}

bool bfs()
{
    queue<int>q ;
    ll u , v  , tp ;

    clr(level,-1) ;

    q.push(0);
    level[0] = 0 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int ed=last[u] ; ed != -1 ; ed = pre[ed])
        {
            v = head[ed] ;

            if(cap[ed] <= flw[ed] or level[v] != -1)
                continue ;

            if((u>100 and u<=150 and v>150 and v<=200) or (u>150 and u<=200 and v>100 and v<=150))
            {
                tp = cap[ed] - flw[ed] ;

                if(tme[min(u,v) - 100] > tp)
                    continue;
            }

            level[v] = level[u] + 1 ;
            q.push(v);
        }
    }

    return (level[201] != -1) ;
}

ll dfs(ll u,ll mn)
{//deb(u,mn);wait;
    if(mn == 0)
        return 0 ;

    if(u == 201)
        return mn ;

    ll v , ret = 0 , tp ;

    for(int ed = next_edge[u] ; ed != -1 ; ed = pre[ed] , next_edge[u] = ed)
    {
        v = head[ed] ;

        if(level[v] != level[u] + 1)
            continue;

        if((u>100 and u<=150 and v>150 and v<=200) or (u>150 and u<=200 and v>100 and v<=150))
        {
            tp = cap[ed] - flw[ed] ;
//deb("ok",cap[ed],flw[ed]);
            tp = tp/tme[min(u,v) - 100] ;

            if(tp == 0)
                continue;

            ret = dfs(v,min(mn,tp));

            if(ret)
            {
                flw[ed] += (ret*tme[min(u,v)-100]) ;
                flw[ed^1] -= (ret*tme[min(u,v)-100]) ;
                return ret ;
            }
        }

        else
        {
            ret = dfs(v,min(mn,cap[ed]-flw[ed]));
//deb(u,v,cap[ed],flw[ed]);
            if(ret)
            {
                flw[ed] += ret ;
                flw[ed^1] -= ret ;
                return ret ;
            }
        }
    }

    return 0 ;
}

ll update()
{
    ll ans = 0 , tp ;

    while(tp = dfs(0,Max))
    {
        if(tp == 0)
            break;

        ans += tp ;
    }

    return ans ;
}

bool max_flow(ll mid)
{
    ini_graph(mid);

    ll all = 0 ;

    while(bfs())
    {
        for(int i=0 ; i<202 ; i++)
            next_edge[i] = last[i] ;

        all = update() ;
    }
//deb(mid);
    for(int i=0 ; i<task_edge.size() ; i++)
    {
        all = task_edge[i] ;
//deb(cap[all]-flw[all]);
        if(cap[all]-flw[all])
            return 0 ;

        else
            cap[all] += regular[i+1] ;

        //deb(all,head[all],cap[all]);
    }

    all = 0 ;

    while(bfs())
    {
        for(int i=0 ; i<202 ; i++)
            next_edge[i] = last[i] ;

        all += update() ;
//deb(mid,all);wait;
        if(all>=k)
            return 1 ;
    }

    return 0 ;
}

ll b_search(ll sg)
{
    ll l = 0 , r = sg , mid ;

    while(l<=r)
    {
        mid = (l+r)/2 ;
//deb(mid,l,r);wait;
        if(max_flow(mid))
            r = mid-1 ;

        else
            l = mid+1 ;
    }
    return l ;
}

int main()
{
//    Read;
//    Write;
    int tcase , u , v , tp , tp1 , n , m , nj ;

    sf1(tcase) ;

    foren(cas,1,tcase)
    {
        sf2(m,n);
        sf1ll(k);

        ll vp = 0 , mx = 0 ;

        reset();

        for(int i=1 ; i<=n ; i++)
        {
            sf1ll(tme[i]);

            mx = max(mx,tme[i]);

            worker_edge.pb(edges);
            add_edge(100+i,150+i);

            normal_edge.pb(edges);
            add_edge(150+i,201);
        }

        for(int i=1 ; i<=m ; i++)
        {
            sf1ll(vip[i]);

            vp += vip[i] ;

            sf1ll(regular[i]);

            sf1(nj) ;

            task_edge.pb(edges);
            add_edge(i,i+50);

            normal_edge.pb(edges);
            add_edge(0,i);

            for(int j=1 ; j<=nj ; j++)
            {
                sf1(tp);

                normal_edge.pb(edges);
                add_edge(i+50,tp+100);
            }
        }

        vp += k ;

        vp = vp*mx ;

        ll ans ;

        if(vp)
            ans = b_search(vp);
        else
            ans = 0 ;

        pf("Case %d: %lld\n",cas,ans);
    }

    return 0;
}

/*

3
3 3 10
2 4 8
2 3 1 1
2 3 1 2
2 4 1 3

3 3 10
2 4 8
2 4 1 1
2 3 1 2
2 4 1 3

3 3 11
5 6 7
2 5 2 1 2
2 6 2  2 3
2 8 2 1 3

1
1 2 0
2 3
0 0 1 2

*/
