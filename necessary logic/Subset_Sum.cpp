#include <bits/stdc++.h>

using namespace std ;

#define max_sum 100000
#define total_coin 500

int arr[] = {3, 34, 5, 12, 5, 2}, dp[max_sum][total_coin];

int rec(int n,int sum)
{
    if(sum == 0)
        return 1 ;

    if(n == 0)
        return 0 ;

    int& rat = dp[sum][n] ;

    if(rat != -1)
        return rat ;

    if(arr[n-1]>sum)
        rat = rec(n-1,sum);

    else
        rat = rec(n-1,sum) | rec(n-1,sum-arr[n-1]);

    return rat ;
}

int bottom_up(int n,int sum)
{
    for(int i=0 ; i<=sum ; i++)
        dp[i][0] = 0 ;

    for(int i=1 ; i<n ; i++)
        dp[0][i] = 1 ;

    for(int i=1 ; i<=sum ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            dp[i][j] = dp[i][j-1] ;

            if(arr[j-1]<=i)
                dp[i][j] = dp[i][j] | dp[i-arr[j-1]][j-1] ;
        }
    }
    return dp[sum][n] ;
}

int main()
{
//    memset(dp,-1,sizeof(dp));
//    int c = rec(6,8) ;

    int c = bottom_up(6,9);

    if(c)
        printf(":D\n");
    else
        printf(":(\n");

    return 0 ;
}
