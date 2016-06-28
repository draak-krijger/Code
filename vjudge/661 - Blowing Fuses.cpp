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
#define Max 2000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    int tcase = 0, n , m , c , x , sum , sm ;
    bool flag ;
    int arra[30] , nf[30] ;

    while(scanf("%d %d %d",&n,&m,&c) != EOF)
    {
        if(n==0 && m==0 && c==0)
            return 0;

        for(int i=1 ; i<=n ; i++)
            sf1(arra[i]);

        clr(nf,0);
        flag = true;
        sm = 0 ;

        printf("Sequence %d\n",tcase+1);
        tcase++;

        for(int i=0 ; i<m ; i++)
        {
            sf1(x) ;

            if(nf[x] == 1)
                nf[x] = 0 ;

            else
                nf[x] = 1 ;

            sum = 0 ;

            if(flag)
            {
                for(int i=1 ; i<=n ; i++)
                {
                    if(nf[i])
                    {
                        sum += arra[i];
                    }
                }

                if(sum>sm)
                    sm = sum ;

                if(sum>c)
                    flag = false;
            }
        }

        if(flag)
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n",sm);
        }

        else
        {
            printf("Fuse was blown.\n");
        }

        printf("\n");
    }
    return 0;
}
