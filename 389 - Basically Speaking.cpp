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
#define Max 1000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

ll POW(ll a,int b)
{
    ll res = 1 ;

    for(int i=0 ; i<b ; i++)
        res *= a ;

    return res ;
}

int main()
{
    ll a , b , sum ;
    int len , m , temp ;
    bool ck ;
    char str[50] ;
    string res ;

    while(scanf("%s %lld %lld",str,&a,&b) != EOF)
    {
        len = strlen(str);
        sum = 0 ;
        ck = false;
        m = 0 ;

        for(int i=len-1 ; i>=0 ; i--)
        {
            if(isdigit(str[i]))
                temp = str[i] - '0' ;

            else
                temp = str[i] - '7' ;

            sum += (ll)temp*POW(a,m++);
        }

        res.clear();

        while(sum)
        {
            temp = sum%b ;
            sum /= b ;

            if(temp<10)
                temp = temp + '0' ;
            else
                temp = temp + '7' ;

            res += temp;
        }

        if(res.empty())
            res+='0';

        if(res.size()>7){
            printf("  ERROR\n");
            continue;
        }

        for(int i=0 ; i<7-(int)res.size() ; i++)
            printf(" ");

        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
    return 0;
}
