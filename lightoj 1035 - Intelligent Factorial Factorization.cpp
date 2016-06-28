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
#define Max 100+10

bool arra[Max] ;
vector<int>primes;

void seave();
int ppow(int num,int prim) ;
int POW(int n , int p);

int main()
{
    int tcase , a ;
    seave();
//printf("%d\n",primes[primes.size()-1]);
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(a);
        printf("Case %d: %d = ",cas,a);

        for(int i=0 ; primes[i]<=a ; i++)
        {
            if(i>0)
                printf(" * ");

            printf("%d (%d)",primes[i],ppow(a,primes[i]));
        }
        printf("\n");
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

    for(a=11;a<Max-2 ; a+=2)
        if(!arra[a])
            primes.pb(a);
}

int ppow(int num,int prim)
{
    int a = prim , ans = 0 , i = 2;

    while(a<=num)
    {
        ans += (num/a) ;
        a = POW(prim,i);
        i++;
    }
    return ans ;
}

int POW(int n , int p)
{
    int res = 1 ;

    forln(i,0,p)
    {
        res *= n ;
    }

    return res ;
}
