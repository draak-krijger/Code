/**
  *                              ------------------------- ALLAH is Almighty -----------------------------
  *  @author: Mohammad Nazim Uddin
  *  University: SUST
  *  OJ: Lightoj
  *  problem name: 1038 - Race to 1 Again
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
#define ps pf("pass\n")

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

// --------------------------------------------- MNU --------------------------------------------- //

double dp[sz] ;
int ck[sz] ;
vector<int>divisor[sz] ;

ll caldiv()
{
    for(int i=2 ; i<=100000 ; i++)
    {
        int temp = i ;

        foren(j,2,sqrt(i))
        {
            if(temp%j == 0)
            {
                if(temp/j == j)
                {
                    divisor[i].pb(j);
                    continue;
                }
                divisor[i].pb(j);
                divisor[i].pb(temp/j);
            }
        }
    }
}

double rec(int n)
{
    if(n == 1)
        return 0 ;

    double& rat = dp[n] ;

    if(ck[n] != -1)
        return rat ;

    double ans = 2 ;
    int cont = divisor[n].size() + 2  ;

    for(int i=0 ; i<divisor[n].size() ; i++)
    {
        ans += rec(divisor[n][i]);
        ans++;
    }
    ans/=(double)cont ;
    rat = (ans/(1.0-(1.0/(double)cont))) ;
    ck[n] = 1 ;
    return rat ;
}

int main()
{
    int tcase , n;
    sf1(tcase);
    caldiv();

    foren(cas,1,tcase)
    {
        sf1(n);
        clr(ck,-1);
        double ans = rec(n);
        pf("Case %d: %.6lf\n",cas,ans);
    }

    return 0 ;
}
