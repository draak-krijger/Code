/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Codeforces
    problem name: A
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
#define Max 500+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int small[30] ;

int main()
{
    int n , cont , a ;
    char c ;

    while(sf1(n) != EOF)
    {
        getchar();

        clr(small,0);
        cont = 0 ;

        foren(i,1,2*n-2)
        {
            scanf("%c",&c);

            if(i&1)
            {
                a = c - 'a' ;
                small[a]++;
            }

            else
            {
                a = c - 'A' ;

                if(small[a]>0)
                    small[a]--;

                else
                    cont++;
            }
        }

        printf("%d\n",cont);
    }
    return 0;
}
