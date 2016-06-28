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
#define MOD 131071
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll big_mod(ll base,ll pw)
{
    ll res = 1 ;

    while(pw)
    {
        if(pw&1)
            res = (res*base)%MOD ;

        base = (base*base)%MOD ;
        pw /= 2 ;
    }

    return res ;
}

int main()
{
    string s , inp ;
    char c ;
    int result , len , m ;
    s.clear();
    while(cin>>inp)
    {
        s+=inp ;
        if(inp[inp.size()-1] != '#')
            continue;


        result = 0 ;
        m = 0 ;
        len = s.size();

        for(int i=len-2 ; i>=0 ; i--)
        {
            if(s[i] == '1')
                result = (result+big_mod(2,m))%MOD ;

            m++;
        }

        if(!result)
            printf("YES\n");
        else
            printf("NO\n");
        s.clear();
    }
    return 0;
}
