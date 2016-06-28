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
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000

double dp[110] ;
int n ,  arra[110] ;

double rec(int pos);

int main()
{
    int tcase ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf1(n);

        foren(i,1,n)
        {
            dp[i] = -1 ;
            sf1(arra[i]);
        }

        printf("Case %d: %.6lf\n",cas,rec(1));
    }
    return 0;
}

double rec(int pos)
{
    if(pos>n)
        return 0 ;

    if(pos == n)
        return arra[n] ;

    if(dp[pos] != -1)
        return dp[pos] ;

    double hor , tmp = arra[pos] ;

    if(n-pos>6)
        hor = 6 ;

    else
        hor = n-pos ;

    for(int i=1 ; i<=6 ; i++)
    {
        tmp +=  rec(pos+i)/hor ;
    }

    return dp[pos] = tmp ;
}
