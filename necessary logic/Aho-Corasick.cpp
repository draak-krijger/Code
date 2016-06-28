/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: codeforces
    problem name: contest
*/

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
#define sz 500+7
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

const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // horizontal->vertical->diagonal
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};     //knight moves


//close

// --------------------------------------------- MNU --------------------------------------------- //

int m, n, res;
typedef pair<int, int> Point;

struct NODE {
    int cnt;
    bool vis;
    NODE *next[27];
    vector <NODE *> out;
    NODE() {
        for(int i = 0; i < 27; i++) {
            next[i] = NULL;
        }
        out.clear();
        vis = false;
        cnt=0;
    }

    ~NODE() {
        for(int i = 1; i < 27; i++)
            if(next[i] != NULL && next[i] != this)
                delete next[i];
    }
}*root;

void buildtrie(char dictionary[][sz],int n) {    // processing the dictionarytionary

    root = new NODE();

    /*usual trie part*/
    for(int i = 0; i < n; i++) {
        NODE *p = root;
        for(int j = 0; dictionary[i][j] ; j++) {
            char c = dictionary[i][j]- 'a' + 1;
            if(!p->next[c])
                p->next[c] = new NODE();
            p = p->next[c];
        }
    }

    /* Pushing the nodes adjacent to root into queue */
    queue <NODE *> q;
    for(int i = 0; i < 27; i++) {
        if(!root->next[i])
            root->next[i] = root;
        else {
            q.push(root->next[i]);
            root->next[i]->next[0] = root;  // ->next[0] = back Pointer

        }
    }

    /* Building Aho-Corasick tree */
    while(!q.empty()) {
        NODE *u = q.front();    // parent node
        q.pop();

        for(int i = 1; i < 27; i++) {
            if(u->next[i]) {//deb(i);
                NODE *v = u->next[i];   // child node
                NODE *w = u->next[0];   // back pointer of parent node
                while(!w->next[i])    // Until the char(i+'a'-1) child is found (please see its not(!))
                    w = w->next[0];     // go up and up to back pointer.

                v->next[0] = w = w->next[i];  // back pointer of v will be found child above.
                w->out.push_back(v);    // out will be used in dfs step.
                                        // here w is the new found match node.
                q.push(v);              // Push v into queue.
            }
        }
    }
}

void aho_corasick(NODE *p, char *word) {    // Third step, processing the text.
    for(int i = 0; word[i]; i++) {
        char c = word[i]-'a'+1 ;
        while(!p->next[c])
            p = p->next[0];
        p = p->next[c];
        p->cnt++;
    }
}

int dfs( NODE *p ) {    // DFS for counting.
    if(p->vis) return p->cnt;
    for(int i = 0; i < p->out.size(); i++)
        p->cnt += dfs(p->out[i]);
    p->vis = true;
    return p->cnt;
}

char query[1000100];
char dictionary[sz][sz];

int main() {
    int t, tc, y, z;
    int i, j, k, l, h;
    char ch;
    scanf ("%d", &tc);
    for (t = 1; t <= tc; t++) {
        int n;
        scanf("%d",&n);

        scanf("%s",query);

        for (int i=0; i<n; ++i) {
            scanf("%s",dictionary[i]);
        }

        buildtrie(dictionary, n);

        aho_corasick(root, query);

        printf("Case %d:\n",t);

        for(int i = 0; i < n; i++) {
            NODE *p = root;
            for(int j = 0; dictionary[i][j]; j++) {
                char c = dictionary[i][j] -'a' +1;
                p = p->next[c];
            }
            printf("%d\n", dfs(p));
        }
        delete root;
    }

    return 0;
}
