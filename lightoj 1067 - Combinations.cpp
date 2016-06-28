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
#define Max 1000000+10
#define MOD 1000003
#define ll long long

ll arra[Max] ;

void pre_cal();
ll big_mod(ll base , ll mod , ll pw);

int main()
{
    int tcase ;
    long long n , r , x , y ;
    sf1(tcase);
    pre_cal();

    foren(cas,1,tcase)
    {
        scanf("%lld %lld",&n,&r);

        x = (arra[r]*arra[n-r])%MOD;
        y = big_mod(x,MOD,MOD-2) ;

        printf("Case %d: %d\n",cas,(arra[n]*y)%MOD);
    }
    return 0;
}

void pre_cal()
{
    arra[0] = 1 ;
    arra[1] = 1 ;

    for(int i=2 ; i<Max-2 ; i++)
        arra[i] = (arra[i-1]*i)%MOD ;
}

ll int big_mod(ll base , ll mod , ll pw)
{
    int result = 1 ;

//    if(base<1 || pw<0 || mod<1)
//        return -1 ;

    while(pw)
    {
        if(pw&1)
            result = (result*base)%mod ;

        base = base*base%mod ;
        pw = floor(pw/2) ;
//        cout<<result<<endl;
    }

    return result ;
}

