// Bitmask
#include <bits/stdc++.h>

using namespace std ;

#define NAZIM
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
#define Max 1000000
#define sz 100+5
#define Mod 200000+20
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

struct data
{
    char s[3][100];
};

data arra[20] ;
int graph[20][20] , n ;

int issame(int i,int j)
{
    int l = 0 ;

    for(int k=0 ; k<3 ; k++)
    {
        for(int m=0 ; m<3 ; m++)
        {
            if(strcmp(arra[i].s[k],arra[j].s[m]) == 0)
            {
                l = 1 ;
                break;
            }
        }
        if(l)
            break;
    }
    return l ;
}

bool check(int n,int pos)
{
    return (n&(1<<pos));
}

int set_bit(int n,int pos)
{
    return (n | (1<<pos));
}

int bit_count(int x)
{
    int ans = 0 ;

    for(int i=0 ; i<=n ; i++)
    {
        if(check(x,i))
            ans++;
    }

    return ans ;
}

int bitmask()
{
    bool ck ;
    int ans = 0 ;

    for(int i=0 ; i<(1<<n) ; i++)
    {
        ck = 0 ;
        for(int j=0 ; j<n ; j++)
        {
            if(!check(i,j))
                continue;

            for(int l=0 ; l<j ; l++)
            {
                if(check(i,l) and graph[j][l])
                {
                    ck = true;
                    break;
                }
            }

            if(ck)
                break;
        }

        if(ck)
            continue;
        ans = max(ans,bit_count(i));
    }
    return ans ;

}

int main()
{
    sf1(n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s %s %s",arra[i].s[0],arra[i].s[1],arra[i].s[2]);
    }

    clr(graph,0);

    for(int i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            graph[j][i] = graph[i][j] = issame(i,j);
        }
    }

    int res = bitmask();
    printf("%d\n",res);
    return 0;
}
