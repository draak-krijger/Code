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
#define Max 500000000+10
#define MOD 1000000007
#define ll long long

ll countint(ll n);

int main()
{
    int tcase ;
    ll q , b , e , mid , tmp ;
    bool ck ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld",&q);
        b = 1 ;
        e = Max ;
        ck = false;

        while(b<e)
        {
            mid = (b+e)/2 ;
            tmp = countint(mid);

            if(tmp<q)
                b = mid + 1 ;

            else if(tmp>=q)
                e = mid ;

        }

        if(countint(b)==q)
            printf("Case %d: %lld\n",cas,b);

        else
            printf("Case %d: impossible\n",cas);
    }
    return 0;
}

ll countint(ll n)
{
    ll result = 0 ;

    while(n)
    {
        n /= 5 ;
        result += n ;
    }
    return result ;
}
