#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(angel) scanf("%d", &a)
#define takel(angel) scanf("%ld", &a)
#define takell(angel) scanf("%lld", &a)
#define takellu(angel) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(o)
using namespace std;

typedef long long ll;
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void deb(T1 x)
{
    cout << "Debugging: " << x << endl;
}
template <class T1, class T2> void deb(T1 x, T2 y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moves
#define SIZE 46400
bool prime[SIZE];
bool flag[100005];

void SEIEVE()
{
    int i, j, k=sqrt(SIZE);
    for(i=2; i<=k; i++)
        if(prime[i]==0)
            for(j=i*i; j<SIZE; j+=i)
                prime[j]=1;
    prime[1] = 1;
    return;
}

int SEGMENT(ll a, ll b)
{
    CLR(flag);
    int cow = 0;
    //if(a<=2) cow++;
    if(a<=2) a=2;
    ll i, j, k = sqrt(b)+2, l;
    for(i=2; i<k; i++)
        if(!prime[i])
        {
            if(i>=a) j = 2*i;
            else
            {
                j = (a/i)*i;
                if(j<a || j==i) j+=i;
            }
            for( ; j<=b; j+=i)
                flag[j-a] = 1;
        }
    for(i=a; i<=b; i++)
        if(!flag[i-a])
        {
            cow++;
            //deb(i);
        }
    return cow;
}

int main()
{
    // time_t t1=clock();
//#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    ///                                    MAIN
    SEIEVE();
    ll t, a, b, k=0;
    takell(call);
    while(t--)
    {
        takell(angel);
        takell(beer);
        int r = SEGMENT(a, b);
        pf("Case %lld: %d\n", ++k, r);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
