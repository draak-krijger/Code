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
#define Max 50000+10
#define MOD 1000000007
#define ll long long

ll counting(ll num,ll prime);
ll POW(ll base,ll pw);
ll divisor(ll num,ll prime);

int main()
{
    int tcase , n , r , p , q ;
    ll five , two ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,r);
        sf2(p,q);

        five = counting(n,5) - (counting(r,5)+counting(n-r,5));
        two = counting(n,2) - (counting(r,2)+counting(n-r,2));

        five += (divisor(p,5)*q) ;
        two += (divisor(p,2)*q) ;

        printf("Case %d: %lld\n",cas,min(five,two));
    }
    return 0;
}

ll POW(ll base,ll pw)
{
    ll result = 1 ;

    forln(i,0,pw)
    {
        result *= base;
    }
    return result;
}

ll counting(ll num,ll prime)
{
    ll result = 0 , b = prime ;
    int i=2 ;

    while(num/b)
    {
        result += (num/b) ;
        b = POW(prime,i++);
    }

    return result ;
}

ll divisor(ll num,ll prime)
{
    ll result = 0 ;

    while(num%prime == 0)
    {
        result++;
        num /= prime;
    }

    return result;
}
