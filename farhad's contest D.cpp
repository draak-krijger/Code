/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Codeforces
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
#define Max 500+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

map<int,int>mymap ;

void pre_cal()
{
    mymap.clear();

    mymap['Q'-'A'] = 9 ;
    mymap['R'-'A'] = 5 ;
    mymap['B'-'A'] = 3 ;
    mymap['N'-'A'] = 3 ;
    mymap['P'-'A'] = 1 ;
    mymap['K'-'A'] = 0 ;
}

int main()
{
    pre_cal();

    char c ;
    int w , b ;
    w = b = 0 ;

    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        {
            scanf("%c",&c);

            if(isupper(c))
                w+=mymap[c-'A'];

            if(islower(c))
                b+= mymap[c-'a'];
        }

        getchar();
    }

    if(w>b)
        printf("White\n");

    else if(b>w)
        printf("Black\n");

    else
        printf("Draw\n");

    return 0;
}
