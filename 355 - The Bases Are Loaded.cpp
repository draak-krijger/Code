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
    ll a , b ;
    int len , tmp , m ;
    unsigned long long sum ;
    char str[100] , res[100];
    bool tag ;

    while(scanf("%lld %lld %s",&a,&b,str) != EOF)
    {
        len = strlen(str);
        sum = 0 ;
        m = 0 ;
        tag = false;

        for(int i=len-1 ; i>=0 ; i--)
        {
            if(isdigit(str[i]))
                tmp = str[i] - '0' ;

            else
                tmp = str[i] - '7' ;

            if(tmp >= a || tmp<0)
                tag = true;
            //cout<<tmp<<endl;
            sum += (tmp*POW(a,m++));
        }
//cout<<sum<<endl ;
        if(tag)
        {
            printf("%s is an illegal base %lld number\n", str, a);
            continue;
        }

        if(sum == 0)
        {
            printf("%s base %lld = 0 base %lld\n", str, a, b);
            continue;
        }

        m = 0;

        while(sum)
        {
            tmp = sum%b ;
            sum /= b ;

            if(tmp<10)
                tmp = tmp + '0' ;

            else
                tmp = tmp + '7' ;

            res[m++] = tmp ;
        }
        printf("%s base %lld = ", str, a);

        for(int i=m-1 ; i>=0 ; i--)
            printf("%c",res[i]);
        printf(" base %lld\n", b);
    }
    return 0;
}
