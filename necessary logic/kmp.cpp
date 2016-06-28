// KMP
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
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1500000+9
#define sz 25+7
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

vector<int> prefix_cal(char str[])
{
    int l = strlen(str+1) ;
    vector<int>prefix(l+1) ;

    prefix[1] = 0 ;
    int k = 0 ;

    for(int i=2 ; i<=l ; i++)
    {
        while(k>0 and str[i] != str[k+1])
            k = prefix[k];

        if(str[k+1] == str[i])
            k++;

        prefix[i] = k ;
    }

    return prefix;
}

vector<int> match_prefix(char par[],char str[])
{
    int l1 = strlen(str+1) , l2 = strlen(par+1) , k = 0 ;

    vector<int>prefix , match ;
    prefix = prefix_cal(par) ;

    for(int i = 1 ; i<=l1 ; i++)
    {
        while(k>0 and str[i] != par[k+1])
            k = prefix[k];

        if(str[i] == par[k+1])
            k++;

        if(k == l2)
        {
            match.pb(i-k);
            k = prefix[k] ;
        }
    }

    return match ;
}

int main()
{
    char txt[sz] , pat[sz] ;

    scanf("%s %s",txt+1,pat+1);

    vector<int>match ;
    match = match_prefix(pat,txt);

    for(int i=0 ; i <match.size() ; i++)
        printf("%d\n",match[i]);

    return 0;
}
