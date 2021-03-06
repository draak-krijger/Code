/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: codeforces
    problem name: Tetrahedron
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
#define Max 15000000+9
#define sz 3000+7
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second

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

vector<int>finala,finalb,a,b ;

int main()
{
    int n , k1 , k2 , tmp , tmp2 , cont = 0 , tm = 0 ;

    sf1(n);
    sf1(k1);

    for(int i=0 ; i<k1 ; i++)
    {
        sf1(tmp);
        finala.pb(tmp);
        a.pb(tmp);
    }

    sf1(k2);

    for(int i=0 ; i<k2 ; i++)
    {
        sf1(tmp);
        finalb.pb(tmp);
        b.pb(tmp);
    }
    int i = 0 ;
    for(;i<=200 ; i++)
    {
        if(a.empty())
        {
            tm = 2 ;
            break;
        }

        else if(b.empty())
        {
            tm = 1 ;
            break;
        }
        cont++;
        tmp = a[0];
        tmp2 = b[0];
        a.erase(a.begin());
        b.erase(b.begin());

        if(tmp>tmp2)
        {
            a.pb(tmp2);
            a.pb(tmp);
        }

        else
        {
            b.pb(tmp);
            b.pb(tmp2);
        }
    }

    if(a.size() == 0 or b.size() == 0)
        printf("%d %d\n",cont,tm);

    else
        printf("-1\n");

    return 0;
}
