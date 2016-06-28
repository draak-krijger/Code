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
#define Max 1000000000
#define sz 100000+7
#define Mod 10007
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

int num[sz] , match , node , n_d , graph[30*sz][30] , link[30*sz] , slen ;
jora_int edge[30*sz] ;

int add_edge(int st,int ln)
{
    edge[n_d].fs = st ;
    edge[n_d].sc = ln ;

    for(int i=0 ; i<30 ; i++)
        graph[n_d][i] = 0 ;

    return n_d++;
}

void _jump(int pos)
{
    while(match > edge[graph[node][num[pos+1-match]]].sc)
    {
        node = graph[node][num[pos+1-match]] ;
        match -= edge[node].sc ;
    }
}

void add_char(int pos)
{
    int last = 0 , a = num[pos] , cur_ed , m_ed , u ;
    match++;

    while(match>0)
    {
        _jump(pos);
        cur_ed = num[pos - match + 1] ;
        int& v = graph[node][cur_ed] ;
        m_ed = num[edge[v].fs + match - 1] ;

        if(v == 0)
        {
            v = add_edge(pos-match+1,slen-pos+match-1);//deb(pos,v);
            link[last] = node ;
            last = 0 ;
        }

        else if(a == m_ed)
        {
            link[last] = node ;
            return ;
        }

        else
        {
            u = add_edge(edge[v].fs,match-1);
            graph[u][a] = add_edge(pos,slen-pos);
            graph[u][m_ed] = v ;
//if(edge[v].sc<match-1) deb(v,edge[v].sc,pos,match),wait;
            edge[v].fs += match - 1;
            edge[v].sc -= match - 1;

            v = u ;

            link[last] = u ;
            last = u ;
        }

        if(node == 0)
            match--;

        else
            node = link[node] ;
    }
}

void reset()
{
    node = 0 ;
    n_d = 0 ;
    match = 0 ;

    add_edge(0,Max);
}

void rec(int nd)
{
    if(nd)
        pf("%d %d %d\n",nd,edge[nd].fs,edge[nd].sc);

    for(int i=0 ; i<29 ; i++)
    {
        if(graph[nd][i] > 0)
        {
            deb(nd,i);
            rec(graph[nd][i]);
        }
    }
}

int main()
{
    string str ;

    cin>>str ;
    str += '#' ;
    slen = str.length();

    reset();

    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i] == '#')
        {
            num[i] = 26 ;
            add_char(i);
            continue;
        }

        num[i] = str[i] - 'a' ;
        add_char(i);
    }
deb(str.length(),n_d);
    //rec(0);

    return 0 ;
}
