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

map<char,int>mp ;
bool prime[2100] ;

void seave()
{
    prime[1] = true;
    for(int i=4 ; i<2010 ; i+=2)
        prime[i] = true;

    for(int i=3 ; i<2010 ; i+=2)
    {
        if(!prime[i])
        {
            for(int j=i+i ; j<2010 ; j+=i)
                prime[j] = true;
        }
    }
}

int main()
{
    seave();
    int tcase , n ;
    string s , ans ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        cin>>s ;
        mp.clear();

        for(int i=0 ; i<s.size() ; i++)
            mp[s[i]]++;


        map<char,int>::iterator it ;
        ans.clear();
        for(it = mp.begin() ; it!=mp.end() ; it++)
        {
            n = it->second ;
            if(!prime[n])
                ans+=it->first ;
        }

        sort(ans.begin(),ans.end());
        printf("Case %d: ",cas);

        if(ans.empty())
            printf("empty\n");

        else
            cout<<ans<<endl;
    }
    return 0;
}
