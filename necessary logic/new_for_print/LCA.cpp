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

void LCA(int u,int w)
{
    for(int i=LN ; i>=0 ; i--)
    {
        if(stable[u][i] != -1)
        {
            int temp = stable[u][i] ;

            if(valu[temp]>=w)
                u = stable[u][i] ;
        }
    }
    pf("%d\n",u);
}

int main()
{
    int tcase , n , u , v , q ;

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
            LCA(u,v);
        }
    }
    return 0;
}
