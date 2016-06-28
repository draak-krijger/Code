/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: contest-02
    problem name: divisable
*/

#include <bits/stdc++.h>

using namespace std ;

#define NAZIM
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
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000000
#define sz 200000+20
#define Mod 200000+20
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

jora_ll exteucli(int a ,int b)
{
    if(b == 0)
        return jora_ll(1,0);

    jora_ll temp = exteucli(b,a%b);
    return jora_ll(temp.second,temp.first-temp.second*(a/b));
}

ll modular_inverse(ll a,ll n)
{
    jora_ll temp = exteucli(a,n);

    return (temp.first%n+n)%n ;
}

int main()
{
    ll a , b ;

    while(sf2ll(a,b) != EOF)
    {
        cout<<modular_inverse(a,b)<<endl;
        jora_ll tmp = exteucli(a,b);
        cout<<tmp.first<<" "<<tmp.second<<endl;
    }
    return 0;
}
