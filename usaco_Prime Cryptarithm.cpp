/*
ID: mohamma107
LANG: C++
TASK: crypt1
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
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 500000
#define sz 100000+7
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second
#define wait system("pause")

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

bool ck[10] ;

bool check(int a)
{
    char str[20] ;

    int len = 0 , temp  ;

    while(a)
    {
        str[len++] = (a%10+'0') ;
        a/=10 ;
    }
//deb(str);
    for(int i=0 ; i<len ; i++)
    {
        temp = str[i] - '0' ;

        if(!ck[temp])
            return 0 ;
    }
    return true ;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int n , arr[20] , l1 , l2 , l3 , cont = 0 , l4 ;
//check(187);
    sf1(n);

    clr(ck,0);

    forln(i,0,n)
    {
        sf1(arr[i]);
        ck[arr[i]] = 1 ;
    }

    forln(i,0,n)
    {
        forln(j,0,n)
        {
            forln(k,0,n)
            {
                l1 = arr[i]*100 + arr[j]*10 + arr[k] ;

                forln(l,0,n)
                {
                    forln(m,0,n)
                    {
                        l2 = l1*arr[m] ;
                        l3 = l1*arr[l] ;
                        l4 = l2 + (10*l3) ;

                        if(l2<1000 and l3<1000)
                        {
                            if(check(l2) and check(l3) and check(l4))
                                cont++;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n",cont);

    return 0;
}
