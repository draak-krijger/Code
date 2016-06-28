/*
ID: mohamma107
LANG: C++
TASK: milk
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
#define sz 5000+7
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

struct node
{
    ll a , b ;
};

bool cmp(node a , node b )
{
    if(a.a<b.a)
        return 1 ;

    return 0;
}

node arr[sz] ;

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);

    int n , m ;
    ll ans = 0;

    scanf("%d %d",&n,&m);

    forln(i,0,m)
    {
        scanf("%d %d",&arr[i].a,&arr[i].b);
    }

    sort(arr,arr+m,cmp);

    for(int i=0 ; i<m ; i++)
    {//deb(arr[i].a,arr[i].b);
        if(arr[i].b<=n)
        {
            ans += (arr[i].b*arr[i].a);//deb(ans);
            n-=arr[i].b;
        }

        else if(n)
        {
            ans += (n*arr[i].a);
            n = 0 ;
        }

        if(!n)
            break;
    }

    printf("%lld\n",ans);


    return 0;
}
