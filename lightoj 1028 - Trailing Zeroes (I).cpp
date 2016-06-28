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

bool arra[Max] ;
vector<int>primes;

void seave();
long long zero(long long a);

int main()
{
    int tcase ;
    long long a ;
    seave();
//printf("%d\n",primes[primes.size()-1]);
    sf1(tcase);

    foren(cas,1,tcase)
    {
        scanf("%lld",&a);
        printf("Case %d: %lld\n",cas,zero(a));
    }
    return 0 ;
}

void seave()
{
    int a ;
    arra[1] = true;

    for(int i=4 ; i<Max-2 ; i+=2)
        arra[i] = true;

    primes.pb(2);

    for(int i=3 ; i*i<=Max-2 ; i+=2)
    {
        if(!arra[i])
        {
            primes.pb(i);

            for(int j=i+i ; j<Max-2 ; j+=i)
                arra[j] = true;
        }
    }

    for(a=1001;a<Max-2 ; a+=2)
        if(!arra[a])
            primes.pb(a);
}

long long zero(long long a)
{
    long long divisor = 1 , cont , n = a ;

    for(int i=0 ; primes[i]<=sqrt(a) ; i++)
    {
        if(n%primes[i] == 0)
        {
            cont = 1 ;
            while(n%primes[i] == 0)
            {
                n /= primes[i] ;
                cont++;
            }
            divisor *= cont;
        }

        if(n==1)
            break;
    }

    if(n != 1)
        divisor *= 2 ;

    return divisor - 1 ;
}
