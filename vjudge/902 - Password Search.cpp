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

map<string,int>mp ;

int main()
{
    string s ;
    int n ;

    while(sf1(n) != EOF)
    {
        getchar();
        cin>>s ;
        mp.clear();
        int l = s.size() , maxm = 0 ;

        for(int i=0 ; i<=l-n ; i++)
        {
            int sum = 0 ;
            string ts ;
            ts.clear();
            for(int j=i ; j<i+n ; j++)
                ts += s[j] ;

            sum = ++mp[ts];

            maxm = max(maxm,sum) ;
        }

        map<string,int>::iterator it ;
        s.clear();

        for(it = mp.begin() ; it!=mp.end() ; it++)
        {
            if(it->second == maxm)
            {
                s = it->first ;
                break;
            }
        }

        cout<<s<<endl;
    }
    return 0;
}
