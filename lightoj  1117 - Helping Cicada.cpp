/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Lightoj
    problem name: 1117 - Helping Cicada
*/

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
#define Max 500+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int n , result , m ;
bool ckprimes[46410] ;
double ans ;
vector<int>q , primes , arra;
map<int,int>mymap ;

void combination(int indx,int k)
{
    if(k == 0)
    {
        int a = q[0] , b , p ;
        long long sd = 1 ;
        mymap.clear();
        for(int i=0 ; i<q.size() ; i++)
        {
            ans /= q[i] ;
            a = __gcd(a,q[i]);
        }

        if(q.size()>1)
            ans = ans*a ;

        result += ans ;
        ans = n ;
        return;
    }

    for(int i=indx ; i<=m-k ; i++)
    {
        q.pb(arra[i]);
        combination(i+1,k-1);
        q.pp();
    }
}

int main()
{
    int tcase , fresult, ar ;
    bool ck ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,m);
        fresult = 0 ;
        arra.clear();
        for(int i=0 ; i<m ; i++)
        {
            ck = true;
            sf1(ar);

            for(int j=0 ; j<arra.size() ; j++)
            {
                if(ar%arra[j] == 0)
                    ck = false;
            }

            if(ck)
                arra.pb(ar);
        }

        m = arra.size();

        for(int i=1 ; i<=m ; i++)
        {
            ans = n ;
            result = 0 ;
            q.clear();

            if(i & 1)
            {
                combination(0,i) ;
                fresult += result ;
            }

            else
            {
                combination(0,i);
                //cout<<result<<endl ;
                fresult -= result ;
            }
        }

        printf("Case %d: %d\n",cas,n-fresult);
    }

    return 0;
}
