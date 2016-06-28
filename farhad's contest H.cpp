/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Codeforces
    problem name: H
*/

#include <bits/stdc++.h>

using namespace std ;

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 100000+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    ll a , b , s , p ;
    bool ck ;

    while(scanf("%lld %lld %lld",&a,&b,&s) != EOF)
    {
        p = abs(a) + abs(b) ;
        ck = false ;

        if(s>=p)
        {
            s -= p ;

            if(s%2 == 0)
                ck = true ;
        }

        if(ck)
            printf("YES\n");

        else
            printf("NO\n");
    }
    return 0;
}
