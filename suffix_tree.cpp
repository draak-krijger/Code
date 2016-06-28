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
#define Max 15000000+9
#define sz 1050+7
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

const int max_cahr = 30 ;

struct SuffixTreeNode
{
    SuffixTreeNode *children[max_cahr] , *suffixlink;
    int start , suffixindx ;
    int *ed;
};

typedef SuffixTreeNode node ;

vector<int>startpos ;
node *root , *activenode , *lastnewnode ;
int active_edge , active_length , leafend , reamsfxcount ;
int *rootend , *splitend ;
int len = -1 ;
char str[sz] ;
int num[sz] ;

node *newnode(int start,int *ed)
{
    node *nd = (node*)malloc(sizeof(node));

    for(int i=0 ; i<max_cahr ; i++)
        nd->children[i] = NULL ;

    nd->start = start ;
    nd->ed = ed ;
    nd->suffixlink = root ;
    nd->suffixindx = -1 ;

    return nd ;
}

int edgelength(node *cur)
{
    if(cur == root)
        return 0;

    int ln = (*(cur->ed) - (cur->start))+1 ;
    return ln ;
}

bool walkdown(node *cur)
{
    if(active_length>=edgelength(cur))
    {
        active_length -= edgelength(cur) ;
        active_edge += edgelength(cur) ;
        activenode = cur ;
        return 1 ;
    }
    return 0 ;
}

void extend_node(int pos)
{
    leafend = pos ;
    reamsfxcount++;
    lastnewnode = NULL ;

    while(reamsfxcount>0)
    {
        if(active_length == 0)
            active_edge = pos ;

        if(activenode->children[num[active_edge]] == NULL)
        {
            activenode->children[num[active_edge]] = newnode(pos,&leafend);

            if(lastnewnode != NULL)
            {
                lastnewnode->suffixlink = activenode ;
                lastnewnode = NULL ;
            }
        }

        else
        {
            node *next = activenode->children[num[active_edge]] ;

            if(walkdown(next))
                continue;

            if(num[next->start + active_length] == num[pos])
            {
                if(lastnewnode != NULL and activenode != root)
                {
                    lastnewnode->suffixlink = activenode ;
                    lastnewnode = NULL ;
                }

                active_length++;
                break;
            }

            splitend = (int*)malloc(sizeof(int)) ;
            *splitend = next->start + active_length - 1 ;

            node *split = newnode(next->start,splitend) ;

            activenode->children[num[active_edge]] = split ;

            split->children[num[pos]] = newnode(pos,&leafend) ;

            next->start += active_length ;
            split->children[num[next->start]] = next ;

            if(lastnewnode != NULL)
                lastnewnode->suffixlink = split ;

            lastnewnode = split ;
        }

        reamsfxcount--;


        if(activenode == root and active_length>0)
        {
            active_length--;
            active_edge = pos - reamsfxcount + 1 ;
        }

        else if(activenode != root)
        {
            activenode = activenode->suffixlink ;
        }
    }
}

string print(int l,int r)
{
    string psf ;
    for(int i=l ; i<=r ; i++)
    {
        if(num[i] == 0)
        {
            psf += '$' ;
            continue;
        }

        psf += (num[i]-1+'a');
    }
    return psf ;
}

void set_suffxindx_dfs(node *cur,int level,string psa)
{
    if(cur == NULL)
        return ;
//pf("%d\n",level);
    if(cur->start != -1)
        psa += print(cur->start,*cur->ed);

    bool leaf = 1 ;

    for(int i=0 ; i<max_cahr ; i++)
    {
        if(cur->children[i] != NULL)
        {
            //deb(i);
//            if(cur->start != -1 and leaf)
//                pf(" [%d]\n",cur->suffixindx);

            leaf = 0 ;

            set_suffxindx_dfs(cur->children[i],level+edgelength(cur->children[i]),psa);
        }
    }

    if(leaf)
    {
        cur->suffixindx = len-level ;
        cout<<psa ;
        pf(" [%d]\n",cur->suffixindx);
    }
}

void freenodemam(node *cur)
{
    if(cur == NULL)
        return ;

    for(int i=0 ; i<max_cahr ; i++)
    {
        if(cur->children[i] != NULL)
            freenodemam(cur->children[i]);
    }

    if(cur->suffixindx == -1)
        free(cur->ed) ;

    free(cur);
}

void buildsuffixtree()
{
    len = strlen(str) ;
    active_length = 0 ;
    reamsfxcount = 0;
    rootend = (int*)malloc(sizeof(int));
    *rootend = -1 ;

    root = newnode(-1,rootend) ;
    activenode = root ;

    for(int i=0 ; i<len ; i++)
    {
        if(str[i] == '$')
            num[i] = 0 ;

        else
            num[i] = str[i] - 'a' + 1 ;
    }

    for(int i=0 ; i<len ; i++)
        extend_node(i);

    set_suffxindx_dfs(root,0,"");
}

int traversaledge(char *pat,int idx,int st,int ed)
{
    for(int i=st ; i<=ed and pat[idx] != '\0' ; i++,idx++)
    {
        if(str[i] != pat[idx])
            return -1 ;
    }

    if(pat[idx] == '\0')
        return 1 ;

    return 0;
}

void leaftraverse(node *cur)
{
    if(cur == root)
        return ;

    if(cur->suffixindx > -1)
    {
        startpos.pb(cur->suffixindx);
        return ;
    }

    for(int i=0 ; i<max_cahr ; i++)
    {
        if(cur->children[i])
            leaftraverse(cur->children[i]);
    }
}

int traverse(node *cur,char *pat,int idx)
{
    if(cur == NULL)
        return -1;

    int tp ;
//deb(idx,cur->start);wait;
    if(cur->start != -1)
    {
        tp = traversaledge(pat,idx,cur->start,*cur->ed);
//deb(tp);
        if(tp == -1)
            return -1 ;

        if(tp == 1)
        {
            if(cur->suffixindx > -1)
                startpos.pb(cur->suffixindx);

            else
                leaftraverse(cur);

            return 1 ;
        }
    }

    tp = edgelength(cur);

    idx += tp ;

    if(cur->children[pat[idx]-'a'+1] != NULL)
        return traverse(cur->children[pat[idx]-'a'+1],pat,idx);

    else
        return -1 ;
}

void check_substr(char *pat)
{
    startpos.clear();

    int tp = traverse(root,pat,0);

    if(tp == -1)
        printf("EMPTY\n");

    else
    {
        for(int i=0 ; i<startpos.size() ; i++)
        {
            if(i)
                pf(" ");

            pf("%d",startpos[i]);
        }
        pf("\n");
    }
}

int main()
{
    sf("%s",str);
    buildsuffixtree();
    check_substr("aa");

    freenodemam(root);
    return 0;
}

/*
geeksforgeeks$
aabaacaadaabaaabaa$
aabaacaadaabaaabaa$
*/
