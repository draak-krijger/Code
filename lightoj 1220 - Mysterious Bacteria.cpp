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
#define Max 50000
#define MOD 1000000007
#define ll long long
#define ull unsigned long long

int main()
{
    int tcase ;
    ll n , result , tmp , b ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld",&n);
        result = 1 ;
        bool flag = false;

        if(n<0)
            n = -n, flag = true ;

        for(ll i=2 ; i*i<=n ; i++)
        {
            if(n%i)
                continue;

            tmp = 0 ;
            b = n ;

            while(b%i == 0)
                b /=i , tmp++ ;

            if(b>1)
                continue;

            if(!flag)
                result = max(tmp,result);

            else if(tmp&1)
            {
                result = max(result,tmp);
            }
        }

        printf("Case %d: %lld\n",cas,result);

    }
    return 0;
}
