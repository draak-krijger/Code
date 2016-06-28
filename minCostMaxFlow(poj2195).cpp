//http://blog.csdn.net/acm_baihuzi/article/details/45510703
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#define INF 1<<29
#define N 310111
#define ll long long

using namespace std;

struct Edge
{
    int to,next,cap,flow,cost;
} edge[N];

struct node
{
    int x,y;
} H[N],M[N];
int lh,lm;
int head[N],tol;
int pre[N],dis[N];
bool vis[N];
int n,m;
int E;
int cost;

void init(int t)
{
    E=t;
    tol=0;
    memset(head,-1,sizeof head);
}

int dist(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void addedge(int u,int v,int cap,int cost)
{
    edge[tol].to=v;
    edge[tol].cap=cap;
    edge[tol].cost=cost;
    edge[tol].flow=0;
    edge[tol].next=head[u];
    head[u]=tol++;

    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].cost=-cost;
    edge[tol].flow=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}

bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < E; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i !=  -1; i = edge[i]. next)
        {
            int v = edge[i]. to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i]. cost )
            {
                dis[v] = dis[u] + edge[i]. cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}

//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i]. flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i]. cost * Min;
        }
        flow += Min;
    }
    return flow;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m),n+m)
    {
        char c[200];
        lh=0;
        lm=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",c);
            for(int j=0; j<m; j++)
            {
                if(c[j]=='H')
                {
                    H[lh].x=i;
                    H[lh].y=j;
                    lh++;
                }
                else if(c[j]=='m')
                {
                    M[lm].x=i;
                    M[lm].y=j;
                    lm++;
                }
            }
        }
        init(lh+lm+2);
        for(int i=0; i<lh; i++)
            for(int j=0; j<lm; j++)
            {
                addedge(i,lh+j,1,dist(H[i],M[j]));
            }
        for(int i=0; i<lh; i++)
        {
            addedge(lh+lm,i,1,0);
        }
        for(int j=0; j<lm; j++)
        {
            addedge(lh+j,lh+lm+1,1,0);
        }
        int cost;
        int res=minCostMaxflow(lm+lh,lm+lh+1,cost);
        printf("%d\n",cost);
    }
    return 0;
}
