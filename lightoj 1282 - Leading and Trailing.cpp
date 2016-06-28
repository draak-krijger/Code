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
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 10000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int big_mod(ll base, ll pw);
int first_digit(ll base,ll pw);

int main()
{
    int tcase ;
    ll a , b ;
    int frst , scnd ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld %lld",&a,&b);
        frst = first_digit(a,b);
        scnd = big_mod(a,b);
        printf("Case %d: %03d %03d\n",cas,frst,scnd);
    }
    return 0;
}

int big_mod(ll base, ll pw)
{
    ll result = 1 ;

    while(pw)
    {
        if(pw&1)
            result = (result*base)%1000 ;

        base = (base*base)%1000 ;
        pw = pw/2 ;
    }

    return (int)result ;
}

int first_digit(ll base,ll pw)
{
    double x , y ;
    ll result ;
    x = (double)pw*log10((double)base);
    y = x -floor(x) + 3 - 1 ;
    result = floor(pow(10.0,y));

    return (int)result;
}
