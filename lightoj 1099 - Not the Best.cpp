#include <bits/stdc++.h>
#define pb push_back
#define MAX 300000000

using namespace std ;

struct node
{
    long long int u , w ;

    bool operator < (const node &p) const
    {
        return w>p.w ;
    }
};

long long level1[5010] , level2[5010] , n ;
vector<long long int>graph[5010] , cost[5010] ;

void input();
void reset();
void djkastra();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        djkastra();
        printf("Case %d: %lld\n",cas,level2[n]);
    }
    return 0;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        level1[i] = MAX ;
        level2[i] = MAX ;
        graph[i].clear();
        cost[i].clear() ;
    }
}

void djkastra()
{
    priority_queue<node>q ;

    level1[1] = 0 ;
    int u , v ;
    node temp1 , temp2 ;
    long long int sum , w ;

    temp1.u = 1 ;
    temp1.w = 0 ;
    q.push(temp1);

    while(!q.empty())
    {
        temp1 = q.top();
        q.pop();

        u = temp1.u ;
        w = temp1.w ;
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];
            sum = w + cost[u][i] ;

            if(sum<level1[v])
            {
                level2[v] = level1[v];
                level1[v] = sum ;
                temp2.u = v ;
                temp2.w = sum;
                q.push(temp2);
            }

            else if(sum>level1[v] and sum<level2[v])
            {
                level2[v] = sum ;
                temp2.u = v ;
                temp2.w = sum ;
                q.push(temp2);
            }
        }
    }
}

void input()
{
    long long r ;
    int u , v , w ;

    scanf("%lld %lld",&n,&r);
    reset();

    for(int i=0 ; i<r ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
}
