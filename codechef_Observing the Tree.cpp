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
#define Max 1000000
#define sz 100000+7
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

const int LN = 19 ;

vector<int>graph[sz] ;
int par[sz][20] , chain_head[sz] , chain_no , chain_number[sz] , pos_in_base[sz] , subsize[sz] , depth[sz] , n , m , siz ;

struct node
{
    ll sum , c , d ;
    node *lft , *rgt ;

    node(ll sum,node *lft,node *rgt,ll c,ll d)
    {
        this->sum = sum ;
        this->lft = lft ;
        this->rgt = rgt ;
        this->c = c ;
        this->d = d ;
    }

    node *insert(int l,int r,int a,int b,ll c,ll d);
};

node *null = new node(0,NULL,NULL,0,0);
node *root[sz] ;

void reset()
{
    chain_no = 1 ;
    siz = 0 ;

    for(int i=0 ; i<sz ; i++)
    {
        clr(par[i],-1);
        chain_head[i] = -1 ;
        chain_number[i] = -1 ;
        pos_in_base[i] = -1 ;
    }
}

void dfs(int cur = 1,int pre = -1,int dep = 0 )
{
    par[cur][0] = pre ;
    depth[cur] = dep ;
    subsize[cur] = 1 ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        if(graph[cur][i] == pre)
            continue;

        dfs(graph[cur][i],cur,dep+1);
        subsize[cur] += subsize[graph[cur][i]] ;
    }
}

void hld(int cur = 1,int pre = -1)
{
    if(chain_head[chain_no] == -1)
        chain_head[chain_no] = cur ;

    pos_in_base[cur] = ++siz ;
    chain_number[cur] = chain_no ;

    int snode = -1 , s_size = -1 , v ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        if(graph[cur][i] == pre)
            continue ;

        v = graph[cur][i] ;

        if(snode == -1 or subsize[v]>s_size)
        {
            s_size = subsize[v] ;
            snode = v ;
        }
    }

    if(snode != -1)
        hld(snode,cur);

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        v = graph[cur][i] ;

        if(v == pre or v == snode)
            continue;

        chain_no++;
        hld(v,cur);
    }
}

void s_table()
{
    for(int i=1 ; i<LN ; i++)
    {
        for(int j=0 ; j<=n ; j++)
        {
            if(par[j][i-1] != -1)
                par[j][i] = par[par[j][i-1]][i-1] ;
        }
    }
}

node *node::insert(int l,int r,int a,int b,ll c,ll d)
{
    if(r<a or b<l)
        return this ;
//deb(l,r,a,b,c,d);
    if(l>=a and r<=b)
        return new node(this->sum,this->lft,this->rgt,this->c+c,this->d+d) ;

    int mid = (l+r)/2 ;

    ll tp = b-a+1 , tp1 ;
    tp1 = tp*1LL*c + ((tp*(tp-1))/2LL)*d ;

    tp = c ;

    if(a<=mid)
        tp += ((mid-a+1)*d) ;
//deb(this->sum,tp1);
    return new node(this->sum + tp1 , this->lft->insert(l,mid,max(a,l),min(b,mid),c,d),this->rgt->insert(mid+1,r,max(a,mid+1),min(b,r),tp,d),this->c,this->d);
}

ll query(node *nd,int l,int r,int a,int b,ll c,ll d)
{
    if(r<a or l>b or a>b)
        return 0 ;
//deb(l,r,a,b,c,d);
//deb(nd->sum);
    if(l>=a and r<=b)
    {
        c += nd->c ;
        d += nd->d ;//deb("qr",c,d);
        ll tp = r-l+1 , tp1 ;
        tp1 = tp*c + ((tp*(tp-1))/2LL)*d ;
        tp1 += nd->sum ;//deb(tp1);
        return tp1 ;
    }

    int mid = (l+r)/2 ;
    int tp = mid - l + 1 ;
    ll sum ;

    c += nd->c ;
    d += nd->d ;

    sum = query(nd->lft,l,mid,a,b,c,d);
    sum += query(nd->rgt,mid+1,r,a,b,c+tp*d,d);

    return sum ;
}

int lca(int u,int v)
{
    if(depth[u]>depth[v])
        swap(u,v);

    for(int i=LN ; i>=0 ; i--)
    {
        if((depth[v] - (1<<i)) >= depth[u])
            v = par[v][i] ;
    }

    if(u == v)
        return u ;

    for(int i=LN ; i>=0 ; i--)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i] ;
            v = par[v][i] ;
        }
    }
    return par[u][0] ;
}

ll update(int cng,int u,int v,ll c,ll d,bool flg)
{
//    if(u == v)
//        return c ;
//deb("upd",u,v,c);
    int uchain , vachain = chain_number[v] ;
    vector<jora_int>portion ;

    while(1)
    {
        uchain = chain_number[u] ;

        if(uchain == vachain)
        {
            portion.pb(mp(v,u));
            break;
        }

        int tp = chain_head[uchain] ;
        portion.pb(mp(tp,u));
        u = par[tp][0] ;
    }

    if(flg)
        reverse(portion.begin(),portion.end());

    for(int i=0 ; i<portion.size() ; i++)
    {
        u = portion[i].fs ;
        v = portion[i].sc ;

        u = pos_in_base[u] ;
        v = pos_in_base[v] ;

        if(u>v)
            swap(u,v);

        if(flg and i==0)
            u++;

        if(u>v)
            continue;

        if(flg == 0)
            c = c + (v-u)*1LL*abs(d) ;

        root[cng] = root[cng]->insert(1,siz,u,v,c,d);

        if(flg)
        {
            uchain = (abs(u-v)+1) ;
            c = c + uchain*d ;
        }

        else
            c += abs(d);
    }
    return c ;
}

void change(int cng,int u,int v,ll c,ll d)
{
    int la = lca(u,v);//deb(u,v,la);
    c = update(cng,u,la,c,-d,0);

    update(cng,v,la,c,d,1);
}

ll query_up(int cur,int u,int v,int flg)
{
//    if(u == v)
//        return 0 ;

    int uchain , vchain = chain_number[v] ;
    ll sum = 0 ;

    while(1)
    {
        uchain = chain_number[u] ;

        if(uchain == vchain)
        {
            sum += query(root[cur],1,siz,pos_in_base[v]+flg,pos_in_base[u],0,0);
            return sum ;
        }

        int tp = chain_head[uchain] ;
        sum += query(root[cur],1,siz,pos_in_base[tp],pos_in_base[u],0,0);
        u = par[tp][0] ;
    }
}

ll qry(int cur,int u , int v)
{
    int lc = lca(u,v);

    ll sum = query_up(cur,u,lc,0);
    sum += query_up(cur,v,lc,1);

    return sum ;
}

int main()
{
    //Read;
    int u , v , a , b , c , d ;

    sf2(n,m);

    reset();

    for(int i=1 ; i<n ; i++)
    {
        sf2(u,v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs();
    s_table();
    hld();
    null->lft = null->rgt = null ;
    root[0] = null ;
    char cmd[10] ;
    int cng = 0 , cur_node = 0 ;
    ll ans = 0 ;

//    for(int i=1 ; i<=8 ; i++)
//        deb(pos_in_base[i]);
//wait;
    while(m--)
    {
        sf("%s",cmd);

        if(cmd[0] == 'c')
        {
            sf2(u,v);
            sf2(c,d);

            u = (u+ans)%n + 1 ;
            v = (v+ans)%n + 1 ;
//deb(u,v);
            root[++cng] = root[cur_node] ;
            change(cng,u,v,c,d);

            cur_node = cng ;
        }

        else if(cmd[0] == 'q')
        {
            sf2(u,v);

            u = (u+ans)%n + 1 ;
            v = (v+ans)%n + 1 ;
//deb(u,v);
            ans = qry(cur_node,u,v);
            pf("%lld\n",ans);
        }

        else
        {
            sf1(u);

            u = (u+ans)%(cng+1) ;
//deb(u);
            cur_node = u ;
        }
        //wait;
    }

    return 0;
}

/*
5 7
3 2
2 1
1 4
4 5
c 1 5 2 3
c 2 3 5 10
q 1 3
l 1
q 1 3
l 1
q 1 3

output:
82
65
0

8 8
1 2
1 3
3 4
1 5
4 6
2 7
3 8
c 5 1 3 3
q 1 7
l 0
c 0 2 3 2
q 4 5
c 1 5 6 8
c 0 6 5 7
q 1 4

output:
36
12
108

*/
