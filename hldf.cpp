int tree[9*sz] , chainInd[sz] , chainHead[sz] , nodeInd[sz] , nodeIndcst[sz] ,
 subsize[sz] , parent[sz][21] , otherEnd[sz] , depth[sz] , n , chain_num , ptr ;
vector<int>graph[sz] , cost[sz] , id[sz] ;

void dfs(int par,int cur,int dep)
{
    subsize[cur] = 1 ;
    depth[cur] = dep ;
    parent[cur][0] = par ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par)
        {
            otherEnd[id[cur][i]] = v ;
            dfs(cur,v,dep+1);
            subsize[cur] += subsize[v] ;
        }
    }
}

void build_lca()
{
    for(int i=1 ; (1<<i)<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(parent[j][i-1] != -1)
                parent[j][i] = parent[parent[j][i-1]][i-1] ;
        }
    }
}

int LCA(int u,int v)
{
    if(depth[u]<depth[v])
        swap(u,v);

    for(int i=LN ; i>=0 ; i--)
    {
        if((depth[u]-(1<<i))>=depth[v])
            u = parent[u][i] ;
    }

    if(u == v)
        return u ;

    for(int i=LN ; i>=0 ; i--)
    {
        if(parent[u][i] != -1 and parent[u][i] != parent[v][i])
        {
            u = parent[u][i] ;
            v = parent[v][i] ;
        }
    }

    return parent[u][0] ;
}

void hld(int par,int cur,int cst)
{
    if(chainHead[chain_num] == -1)
        chainHead[chain_num] = cur ;

    chainInd[cur] = chain_num ;
    nodeInd[cur] = ptr ;
    nodeIndcst[ptr++] = cst ;

    int special = -1 , ct = -1 ;

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par)
        {
            if(special == -1 or subsize[v]>ct)
            {
                ct = subsize[v] ;
                cst = cost[cur][i] ;
                special = v ;
            }
        }
    }

    if(special != -1)
    {
        hld(cur,special,cst);
    }

    for(int i=0 ; i<graph[cur].size() ; i++)
    {
        int v = graph[cur][i] ;

        if(v != par and v != special)
        {
            chain_num++;
            hld(cur,v,cost[cur][i]);
        }
    }
}

void build_stree(int node,int s,int e)
{
    if(s == e)
    {
        tree[node] = nodeIndcst[s] ;
        return ;
    }

    int lft = node*2 , rgt = 2*node + 1 , mid = (s+e)/2 ;

    build_stree(lft,s,mid);
    build_stree(rgt,mid+1,e);

    tree[node] = max(tree[lft],tree[rgt]);
}

int query_tree(int node,int s,int e,int i,int j)
{
    if(e<i or s>j)
        return 0;

    if(s>=i and e<=j)
        return tree[node] ;

    int lft = 2*node , rgt = 2*node + 1 , mid = (s+e)/2 ;

    return max(query_tree(lft,s,mid,i,j),query_tree(rgt,mid+1,e,i,j));
}

void update_tree(int node,int s,int e,int x,int valu)
{
    if(s>x or e<x)
        return ;

    if(s == x and e == x)
    {
        tree[node] = valu ;
        return ;
    }

    int lft = 2*node , rgt = lft+1 , mid = (s+e)/2 ;

    update_tree(lft,s,mid,x,valu);
    update_tree(rgt,mid+1,e,x,valu);

    tree[node] = max(tree[lft],tree[rgt]);
}

int query_chain(int u,int v)
{
    int uchain , vchain = chainInd[v] , ans = 0 ;

    while(1)
    {
        uchain = chainInd[u] ;

        if(uchain == vchain)
        {
            if(u == v)
                return ans ;

            ans = max(ans,query_tree(1,1,ptr,nodeInd[v]+1,nodeInd[u]));//deb("ok",u,v,ans);
            return ans ;
        }

        ans = max(ans,query_tree(1,1,ptr,nodeInd[chainHead[uchain]],nodeInd[u]));//deb(u,v,ans);
        u = chainHead[uchain];
        u = parent[u][0] ;
    }
}

int query(int u,int v)
{
    if(u == v)
        return 0 ;

    int anc = LCA(u,v);
//deb(query_chain(u,anc),query_chain(v,anc));
    int ans = max(query_chain(u,anc),query_chain(v,anc));

    return ans ;
}

void change(int ind,int valu)
{
    int u = otherEnd[ind] ;
    update_tree(1,1,ptr,nodeInd[u],valu);
}

int main()
{
    int tcase ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        chain_num = 1 ;
        ptr = 1 ;

        for(int i=0 ; i<sz-2 ; i++)
        {
            graph[i].clear();
            cost[i].clear();
            id[i].clear();
            chainHead[i] = -1 ;
            chainInd[i] = -1 ;
            nodeInd[i] = -1 ;
            nodeIndcst[i] = -1 ;
            subsize[i] = 0 ;
            otherEnd[i] = 0 ;
            depth[i] = 0 ;

            for(int k=0 ; k<21 ; k++)
                parent[i][k] = -1 ;
        }

        sf1(n);

        for(int i=1 ; i<n ; i++)
        {
            int u , v , cs ;

            sf2(u,v);
            sf1(cs);

            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(cs);
            cost[v].pb(cs);
            id[u].pb(i);
            id[v].pb(i);
        }

        dfs(-1,1,0);
        build_lca();
        hld(-1,1,0);
        build_stree(1,1,ptr);

        while(1)
        {
            char str[100] ;
            int u , v ;

            sf("%s",str);

            if(str[0] == 'D')
                break;

            sf2(u,v);

            if(str[0] == 'Q')
            {
                int ans = query(u,v);
                pf("%d\n",ans);
            }

            else
                change(u,v);
        }
    }

    return 0;
}
