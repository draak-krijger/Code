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
#define Max 100000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

double arra[Max] ;

double solution(ll a);
void seave();

int main()
{
    int tcase ;
    ll a ;
    double result ;
    seave();

    sf1(tcase);

    for(ll cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lld",&a);
        result = solution(a);
        printf("Case %lld: %.11lf\n",cas,result+EPS);
    }
    return 0;
}

void seave()
{
    arra[0] = 0;

    for(ll i=1 ; i<=100000000 ; i++)
        arra[i/1000] = arra[(i-1)/1000] + 1.0/(double)i ;

}

double solution(ll a)
{
    ll kk = a/1000 ;
    double sum = arra[kk] ;

    if(a == 100000000)
        return sum;

    for(ll i=a+1 ; i<(kk*1000)+1000 ; i++)
        sum -= 1.0/(double)i ;

    return sum;
}
