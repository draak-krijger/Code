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

bool check[40000+10] ;

void pre_cal()
{
    ll a , b , c , d , j ;

    for(int i=4 ; i<=40000 ; i++)
    {
        a = round(pow(i,2));
//        if(i==45 || i==55)
//            cout<<a<<endl;
        j = 1 ;
        b = round(pow(10,j));

        while(a/b)
        {
            c = a%b ;
            d = a/b ;

            if(c>0 && d>0)
            {
                if(c+d == i)
                {
                    check[i] = true;
                    break ;
                }
            }
            j++;
            b = round(pow(10.0,(double)j));
        }
    }
}

int main()
{
    pre_cal();
    int tcase , a , b ;
    bool ck ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(a,b);
        ck = true;
        if(cas>1)
            printf("\n");

        printf("case #%d\n",cas);

        for(int i=a ; i<=b ; i++)
            if(check[i])
                printf("%d\n",i) , ck = false;

        if(ck)
        printf("no kaprekar numbers\n");
    }
    return 0;
}
