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
#define Max 1000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    int n , sum , m , res ;
    char str[50] ;

    while(scanf("%d",&n) && n)
    {
        getchar();
        sum = 0 ;
        m = 0 ;
        res = -1 ;

        for(int i=0 ; i<n ; i++)
        {
            gets(str);
            m = 0 ;

            for(int j=0 ; j<25 ; j++)
            {
                if(str[j] == 'X')
                {
                    sum++;
                    m++;
                }
            }

            res = max(res,m);
        }

        res = (res*n) - sum ;
        printf("%d\n",res);
    }
    return 0 ;
}
