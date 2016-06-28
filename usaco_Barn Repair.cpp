/*
ID: mohamma107
LANG: C++
TASK: barn1
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
#define sz 200+7
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

bool ck[sz] ;

struct node
{
    ll stall1 , stall2 , diff ;
};

bool cmp(node a , node b )
{
    if(a.diff>b.diff)
        return 1 ;

    return 0;
}

bool cmp2(node a, node b)
{
    if(a.stall1<b.stall2)
        return 1;

    return 0;
}

node arr[sz] ;
int data[sz] ;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);

    int m , s , c , j = 0 ;
    ll ans = 0 ;

    scanf("%d %d %d",&m,&s,&c);

    for(int i=0 ; i<c ; i++)
    {
        scanf("%d",&data[i]);
    }

    sort(data,data+c);

    for(int i=1 ; i<c ; i++)
    {
            arr[i-1].stall1 = data[i-1] ;
            arr[i-1].stall2 = data[i] ;
            arr[i-1].diff = abs(data[i-1]-data[i]);
    }

    if(m==1)
    {
        ans = data[c-1] - data[0] ;
        ans += m ;
    }

    else if(m>c)
        ans = c ;

    else
    {
        sort(arr,arr+c-1,cmp);
        sort(arr,arr+m-1,cmp2);

        ans = arr[0].stall1 - data[0] ;

        for(int i=1 ; i<m-1 ; i++)
        {
            ans += (arr[i].stall1 - arr[i-1].stall2) ;
        }

        ans+= (data[c-1] - arr[m-2].stall2);
        ans += m ;
    }

    printf("%lld\n",ans);

    return 0;
}
