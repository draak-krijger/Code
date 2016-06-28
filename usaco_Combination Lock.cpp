/*
ID: mohamma107
LANG: C++
TASK: combo
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
#define sz 50000+7
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

bool ck[110] ;

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);

    int f[4] , m[4] , a , n , ans = 250  , tmp = 1 , j ;

    sf1(n);

    if(n<=5)
    {
        ans = n*n*n ;
        printf("%d\n",ans);
        return 0;
    }

    forln(i,0,3)
    {
        sf1(f[i]);
    }

    forln(k,0,3)
    {
        sf1(m[k]);

        clr(ck,0);
        a = 0;

        for(int i=m[k]-2 ; i<=m[k]+2 ; i++)
        {
            j = i ;

            if(i<1)
                j = n+i ;

            else if(i>n)
                j = i-n ;
//deb(j);
            ck[j] = 1 ;

        }

        for(int i=f[k]-2 ; i<=f[k]+2 ; i++)
        {
            j = i ;

            if(i<1)
                j = n+i ;

            else if(i>n)
                j = i-n ;

            if(ck[j])
                a++;
        }
//deb(a);
        tmp*=a ;
    }

    printf("%d\n",ans-tmp);

    return 0;
}
