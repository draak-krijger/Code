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
#define ull unsigned long long

int main()
{
    int tcase ;
    ull q , a , b ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%llu",&q);

        a = ((ull)10*q)/(ull)9 ;

        if(a%10 == 0)
            printf("Case %d: %llu %llu\n",cas,a-1,a);

        else
            printf("Case %d: %llu\n",cas,a);
    }
    return 0 ;
}

