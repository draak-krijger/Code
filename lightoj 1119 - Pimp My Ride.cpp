#include <bits/stdc++.h>

using namespace std;

int n ;
long long int dp[1<<14+2] , price[17][17] ;

long long int bitmask(int mask);
int Set(int num,int pos);
bool check(int num,int pos);
void inpcal(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }
    return 0;
}

int Set(int num,int pos)
{
    num = num | (1<<pos);
    return num;
}

bool check(int num,int pos)
{
    bool ck = num & (1<<pos);
    return ck;
}

long long int bitmask(int mask)
{
    if(mask == (1<<n)-1)
        return 0;

    if(dp[mask] != -1)
        return dp[mask];

    long long int minm = 20000000000 ;

    for(int i=0 ; i<n ; i++)
    {
        if(!check(mask,i))
        {
            long long int fprice = price[i][i];
            for(int j=0 ; j<n ; j++)
            {
                if( i!=j && check(mask,j))
                    fprice += price[i][j] ;
            }

            long long int ld = fprice + bitmask(Set(mask,i));
            minm = min(minm,ld);
        }
    }
    return dp[mask] = minm;
}

void inpcal(int cas)
{
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%lld",&price[i][j]);
        }
    }

    memset(dp,-1,sizeof(dp));

    long long int ans = bitmask(0);

    printf("Case %d: %lld\n",cas,ans);
}
