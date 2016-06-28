/*
ID: mohamma107
LANG: C++
TASK: namenum
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
#define MOD 100000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

map<char,int>charvalu ;
map<string,long long>mymap ;

void pre_cal()
{
    int b = 0 , value = 2 ;
    char a ;

    for(int i=0 ; i<25 ; i++)
    {
        a = 'A'+i ;

        if(a == 'Q')
            continue;

        charvalu[a] = value ;

        b++;

        if(b>=3)
        {
            b = 0 ;
            value++;
        }
    }
}

long long strvalu(string str)
{
    int len ;
    long long ans = 0 ;
    len = str.size() ;

    for(int i=0 ; i<len ; i++)
        ans = ans*10 + charvalu[str[i]] ;

    return ans ;
}

int main()
{
    pre_cal();
    char a ;
    string str ;
    freopen("dict.txt","r",stdin);

    for(int i=0 ; i<5000 ; i++)
    {
        cin>>str ;
        mymap[str] = strvalu(str) ;
    }

    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    ll inp , test1 ;

    while(fin>>inp)
    {
        map<string,long long>::iterator it ;
        bool ck = true ;

        for(it = mymap.begin() ; it != mymap.end() ; it++)
        {
            test1 = it->second ;

            if(test1 == inp)
            {
                ck = false ;
                fout<<it->first<<endl;
            }
        }

        if(ck)
            fout<<"NONE"<<endl ;
    }
    return 0 ;
}
