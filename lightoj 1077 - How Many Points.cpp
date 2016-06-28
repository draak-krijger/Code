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

ll gcd(ll a,ll b);

int main()
{
    int tcase , x1 , y1 , x2 , y2 ;
    long long x , y ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(x1,y1);
        sf2(x2,y2);
        x = abs((long long)x1-(long long)x2);
        y = abs((long long)y1-(long long)y2);
//        cout<<x<<" "<<y<<endl;
        x = gcd(x,y) + 1 ;
        printf("Case %d: %lld\n",cas,x);
    }
    return 0;
}

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}
