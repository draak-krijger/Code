//header file

#include <bits/stdc++.h>

using namespace std ;

//define function

#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define MAX 17
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define mem(a,b) memset(a,b,sizeof(a))

//other
int dp[1<<MAX][18] , n , matrix[17][17] ;

int set_bit(int num , int pos)
{
    num = num|(1<<pos);
    return num ;
}

bool check_bit(int num , int pos)
{
    return (num&(1<<pos));
}

int reset_bit(int num,int pos)
{
    num = num & ~(1<<pos);
    return num ;
}

int bit_mask(int mask,int i)
{
    if(i>=n)
        return 0;

    int ret = 0 ;

    if(dp[mask][i] != -1)
        return dp[mask][i] ;

    forln(j,0,n)
    {
        if(!check_bit(mask,j))
        {
            ret = max(ret,bit_mask(set_bit(mask,j),i+1) + matrix[i][j]);
        }
    }

    return dp[mask][i] = ret ;
}

void input()
{
    sf1(n);

    forln(i,0,n)
    {
        forln(j,0,n)
        {
            sf1(matrix[i][j]);
        }
    }
}

int main()
{
    int tcase , ans ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        mem(dp,-1);
        input();
        ans = bit_mask(0,0);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
