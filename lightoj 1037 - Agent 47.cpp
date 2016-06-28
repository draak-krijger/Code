#include <bits/stdc++.h>

using namespace std ;

long long int n , dp[1<<15+2] , shot[20] ;
int bullet[20][20];

long long ajent(int a[],int mask);
int Set(int num,int pos);
bool check(int num,int pos);
void inpcal(int cas);

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcal(cas);

    return 0;
}

int Set(int num,int pos)
{
    num = num | (1<<pos);
    return num ;
}

bool check(int num,int pos)
{
    return num & (1<<pos);
}

long long ajent(int a[],int mask)
{
    if(mask == (1<<n)-1)
        return 0;

    if(dp[mask] != -1)
        return dp[mask];

    long long int mn = 200000000 ;
    int b[20] ;

    for(int i=0 ; i<n ; i++)
    {
        if(!check(mask,i))
        {
            long long int rt = ceil((double)shot[i]/(double)a[i]);

            for(int j=0 ; j<n ; j++)
            {
                if(i!=j && !check(mask,j))
                {
                    b[j] = max(a[j],bullet[i][j]);
                }
            }
            long long int ld = rt + ajent(b,Set(mask,i));
            mn = min(mn,ld);
        }
    }

    return dp[mask] = mn ;
}

void inpcal(int cas)
{
    scanf("%lld",&n);
    int s[20] ;

    for(int i=0 ; i<n ; i++)
    {
        scanf("%lld",&shot[i]);
        s[i] = 1 ;
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            scanf("%1d",&bullet[i][j]);
    }

    memset(dp,-1,sizeof(dp));

    printf("Case %d: %lld\n",cas,ajent(s,0));
}
