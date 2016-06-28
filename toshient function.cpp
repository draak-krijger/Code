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
#define Max 5000000+10

unsigned long long int toshient[Max] ;

void phi();

int main()
{
    phi();
    int tcase , a , b ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(a,b);
        printf("Case %d: %llu\n",cas,toshient[b]-toshient[a-1]);
    }
    return 0;
}

void phi()
{
    forln(i,2,Max-2)
    {
        toshient[i] = i ;
    }

    for(int i=2 ; i<Max-2 ; i+=2)
        toshient[i] -= toshient[i]/2 ;

    for(int i=3 ; i<Max-2 ; i+=2)
    {
        if(toshient[i] == i)
        {
            for(int j=i ; j<Max-2 ; j+=i)
            {
                toshient[j] -= toshient[j]/i ;
            }
        }
    }

    toshient[1] = 0 ;

    for(int i=2 ; i<Max-2 ; i++)
        toshient[i] = toshient[i-1] + (toshient[i]*toshient[i]) ;
}
