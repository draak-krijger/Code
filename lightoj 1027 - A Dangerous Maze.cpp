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

int main()
{
    int x , sum , num , tcase , n ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sum = num = 0 ;
        sf1(n);

        forln(i,0,n)
        {
            sf1(x);

            if(x>=0)
                num++;

            sum += abs(x);
        }

        if(num == 0)
            printf("Case %d: inf\n",cas);

        else
        {
            x = __gcd(sum,num);

            printf("Case %d: %d/%d\n",cas,sum/x,num/x);
        }
    }
    return 0;
}
