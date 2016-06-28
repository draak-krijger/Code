#include <bits/stdc++.h>

using namespace std ;

char A[100] , B[100] ;
int dp[50][50] ;
bool visit[50][50];
string answ ;

void printAll(int i,int j);
void printLCS(int i,int j);
int lcs(int i,int j);
void reset();

int main()
{
    scanf("%s %s",A,B);
    memset(dp,-1,sizeof(dp));
    reset();
    cout<<lcs(0,0)<<endl;
    printLCS(0,0);
    answ.clear();
    printAll(0,0);

    return 0;
}

int lcs(int i,int j)
{
    if(A[i] == '\0' || B[j] == '\0')
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0 ;

    if(A[i] == B[j])
        ans = 1 + lcs(i+1,j+1);

    else
    {
        int val1 = lcs(i,j+1);
        int val2 = lcs(i+1,j);
        ans = max(val1,val2);
    }

    return dp[i][j] = ans;
}

void printLCS(int i,int j)
{
    if(A[i] == '\0' || B[j]== '\0')
    {
        cout<<answ<<endl;
        return;
    }

    if(A[i] == B[j])
    {
        answ+=A[i];
        printLCS(i+1,j+1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            printLCS(i+1,j);

        else
            printLCS(i,j+1);
    }
}

void printAll(int i,int j)
{
    if(A[i] == '\0' || B[j] == '\0')
    {
        cout<<answ<<endl;
        return;
    }

    if(A[i] == B[j])
    {
        answ+=A[i];
        printAll(i+1,j+1);
        answ.erase(answ.end()-1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            printAll(i+1,j);

        else if(dp[i][j+1]>dp[i+1][j])
            printAll(i,j+1);

        else
        {
            printAll(i+1,j);
            printAll(i,j+1);
        }
    }
}

void reset()
{
    for(int i=0 ; i<=15 ; i++)
    {
        for(int j=0 ; j<15 ; j++)
            visit[i][j] = false;
    }
}
