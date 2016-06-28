/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: Codeforces
    problem name: E
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
#define Max 100000+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int mymap1[Max] , mymap2[Max] , mymap3[Max] ;

int main()
{
    int n , a ;

    while(sf1(n) != EOF)
    {
        for(int i=0 ; i<n ; i++)
        {
            sf1(a);
            mymap1[i] = a ;
        }

        for(int i=0 ; i<n-1 ; i++)
        {
            sf1(a);
            mymap2[i] = a ;
        }

        for(int i=0 ; i<n-2 ; i++)
        {
            sf1(a);
            mymap3[i] = a;
        }

        sort(mymap1,mymap1+n);
        sort(mymap2,mymap2+(n-1));
        sort(mymap3,mymap3+(n-2));

        int i = 0 , j = 0 , k = 0 , a = 0 , b = 0 ;

        for(; i<n ; i++,j)
        {
            if(j<n-1)
            {
                if(k<n-2)
                {
                    if(mymap2[j] != mymap3[k])
                        b = mymap2[j];

                    else
                        k++;
                }

                else
                {
                    if(b == 0)
                        b = mymap2[j];
                }

                if(mymap1[i] != mymap2[j])
                {
                    a = mymap1[i] ;
                    k--;
                }

                else
                    j++;
            }

            else
            {
                if(a == 0)
                    a = mymap1[i];
            }
        }

        printf("%d\n%d\n",a,b);
    }
    return 0;
}
