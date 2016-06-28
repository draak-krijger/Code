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
#define Max 100000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int main()
{
    int tcase , len , n ;
    bool ck ;
    char str[500+10] ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(n);
        getchar();

        if(cas>1)
            printf("\n");

        printf("Case %d:\n",cas);

        forln(i,0,n)
        {
            gets(str);

            len = strlen(str);
            ck = true;

            for(int i=0 ; i<len ; i++)
            {
                if(str[i]==' ')
                {
                    if(ck)
                    {
                        printf(" ");
                        ck = false;
                    }
                }
                else
                {
                    printf("%c",str[i]);
                    ck = true;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
