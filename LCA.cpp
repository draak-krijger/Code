int valu[sz] , stable[sz][20] ;

void build(int n)
{
    for(int i=1 ; (1<<i)<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(stable[j][i-1] != -1)
                stable[j][i] = stable[stable[j][i-1]][i-1] ;
        }
    }
}

int LCA(int u,int w)
{
     int ans = 0 ;

    if(depth[q]>depth[p])
        swap(p,q);

    for(int i=LN ; i>=0 ; i--)
    {
        if(depth[p]-(1<<i)>=depth[q])
        {
            p = stable[p][i] ;
        }
    }

    if(p == q)
        return p ;

    for(int i=LN ; i>=0 ; i--)
    {
        if(stable[p][i] != -1 and stable[p][i] != stable[q][i])
        {
            p = stable[p][i] ;
            q = stable[q][i] ;
        }
    }

    return stable[p][0] ;
}

int main()
{
    int tcase , n , u , v , q , ans ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(n,q);

        clr(stable,-1);
        valu[0] = 1 ;

        for(int i=1 ; i<n ; i++)
        {
            sf2(u,v);
            stable[i][0] = u ;
            valu[i] = v ;
        }

        build(n);

        pf("Case %d:\n",cas);

        while(q--)
        {
            sf2(u,v);
            ans = LCA(u,v);
            deb(ans);
        }
    }
    return 0;
}
