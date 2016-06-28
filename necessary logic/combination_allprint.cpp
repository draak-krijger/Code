// Combination print
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
#define Max 500+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

vector<int>q ;
int arra[1000] , n ;

void print_combi(const vector<int>& v)
{
    for(int i=0 ; i<v.size() ; i++)
    {
        printf("%d ",v[i]);
    }
    cout<<endl;
}

void combination(int st , int k)
{
    if(k == 0)
    {
        print_combi(q);
        return;
    }

    for(int i=st ; i<=n-k ; i++)
    {
        q.pb(arra[i]);
        combination(i+1,k-1);
        q.pp();
    }
}

int main()
{
    int k ;
    sf2(n,k);

    forln(i,0,n)
    {
        sf1(arra[i]);
    }

    combination(0,k);
    return 0;
}
