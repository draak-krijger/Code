#include<bits/stdc++.h>
using namespace std;
#define Max 10000005
int ST[24][Max];
int A[Max];
void Compute_ST(int N)
{
    for (int i=0;i<N;i++)ST[0][i] = i;
    for (int k = 1;(1 << k)<N; k++)
    {
        for (int i=0;i+(1<<k)<=N;i++)
        {
            int x = ST[k-1][i];
            int y = ST[k-1][i+(1<<k-1)];
            ST[k][i]=A[x]<=A[y]?x:y;
        }
    }
}

int RMQ(int i, int j)
{
    int k = log2(j-i);
    int x = ST[k][i];
    int y = ST[k][j-(1<<k)+1];
    return A[x] <= A[y] ? x : y;
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    Compute_ST(N);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<A[RMQ(x,y)]<<endl;
    }
    return 0;
}
