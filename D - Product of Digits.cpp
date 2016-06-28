/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Contest-01
    problem name: D
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
#define sz 4200000
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    ll a ;
    int arra[100] , l ;


    while(scanf("%lld",&a) != EOF)
    {
        if(a<10)
        {
            if(a==0)
                a=10 ;

            printf("%lld\n",a);
            continue;
        }

        l = 0 ;
        for(int i=9 ; i>1 ; i--)
        {
            if(a%i == 0)
            {
                while(a%i == 0)
                {
                    arra[l++] = i ;
                    a = a/i ;
                }
            }
        }

        if(a == 1)
        {
            for(int i=l-1 ; i>=0 ; i--)
                printf("%d",arra[i]);

            printf("\n");
        }

        else
            printf("-1\n");
    }
    return 0;
}
