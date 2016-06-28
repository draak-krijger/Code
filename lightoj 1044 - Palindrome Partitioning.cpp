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
#define Max 10000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int pos[1000+10] ;
char str[1000+10] ;

int rec(int i,int j , bool ck)
{
    if(ck)
    {
        if(j<i || i == j )
            return 1 ;

        if(str[i] != str[j])
            return 0 ;
//cout<<i<<endl;
        return rec(i+1,j-1,true) ;
    }

    else
    {
        if(i == j)
            return 0 ;

        if(pos[i] != -1)
            return pos[i] ;

        pos[i] = Max ;

        for(int k=i ; k<j ; k++)
        {
            if(rec(i,k,true))
            {
                pos[i] = min(pos[i],1+rec(k+1,j,false)) ;
            }
        }
        return pos[i] ;
    }
}

int main()
{
    int tcase ;
    sf1(tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        clr(pos,-1);
        scanf("%s",str);
        printf("Case %d: %d\n",cas,rec(0,strlen(str),false));
    }
    return 0;
}

