// SCC(Tarjan's)
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 11111;
int low[MAXN],dfn[MAXN],belong[MAXN],deg[MAXN],ans,scc,t,n,m,depth;
vector<int> g[MAXN],gs[MAXN];
stack<int> s;
void init()
{
    for(int i=0; i<MAXN; i++)g[i].clear(),gs[i].clear();
    memset(dfn,-1,sizeof(dfn));
    memset(belong,-1,sizeof(belong));
    memset(deg,0,sizeof(deg));
    ans = scc = depth = 0 ;
    while(!s.empty())s.pop();
}
void tarjan(int u)
{
    low[u] = dfn[u] = depth++;
    s.push(u);
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(dfn[v]==-1)
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(belong[v]==-1)
        {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        int v;
        do
        {
            v = s.top();
            belong[v] = scc;
            s.pop();
        }
        while(v!=u);
        scc++;
    }
}
void DFS(int u)
{
    dfn[u] = 1;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(belong[u]!=belong[v])deg[belong[v]]++;
        if(!dfn[v])DFS(v);
    }
}
void solve()
{
    for(int i=0; i<scc; i++)if(!deg[i])ans++;
}
int main()
{
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        init();
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            g[a].push_back(b);
        }
        for(int i=0; i<n; i++)if(dfn[i]==-1)tarjan(i);
        memset(dfn,0,sizeof(dfn));
        for(int i=0; i<n; i++)if(!dfn[i])DFS(i);
        solve();
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
