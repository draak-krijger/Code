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

int main()
{
    long double a , b ;
    char str[500] , str1[500] ;
    char c , ch ;

    while(scanf("%s%c%c%c%s",str,&ch,&c,&ch,str1) != EOF)
    {
        a = atof(str);
        b = atof(str1);
        printf("%s %c %s\n",str,c,str1);

        if(a>2147483647)
            printf("first number too big\n");

        if(b>2147483647)
            printf("second number too big\n");

        if(c=='+' && (a+b)>2147483647)
            printf("result too big\n");

        if(c=='*' && (a*b)>2147483647)
            printf("result too big\n");
    }


    return 0;
}
