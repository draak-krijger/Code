// Digit dp
#include <bits/stdc++.h>

using namespace std;
char str[100];
int dp[12][2][90][90], L, K;
int vis[12][2][90][90], v=1;

int rec(int pos, bool imax, int sum, int m)
{
    if(pos >= L)
        return sum%K == 0 and m == 0;
    int& ret = dp[pos][imax][sum][m];
    int& vi = vis[pos][imax][sum][m];
    if(vi == v) return ret;
    ret = 0;
    vi  = v;
    int end = imax ? str[pos] - '0': 9;
    for(int i=0; i<=end; i++)
    {
        ret += rec(pos + 1, imax and i==end, sum + i, (m*10 + i)%K);
    }
    return ret;
}

int main()
{
    int A, B, test, cases=1;
    cin>>test;
    while(test--)
    {
        cin>>A>>B>>K;
        if(K>=90)
        {
            printf("Case %d: %d\n", cases++, 0);
            continue;
        }
        int ans;
        sprintf(str, "%d", B);
        L = strlen(str);
        v++;
        ans = rec(0, 1, 0, 0);
        sprintf(str, "%d", A-1);
        L = strlen(str);
        v++;
        ans -= rec(0, 1, 0, 0);
        printf("Case %d: %d\n", cases++, ans);
    }
    return 0;
}
