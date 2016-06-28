int left[mx] , right[mx] , seen[mx] ;
vector<int>adj[mx] ;

bool kuhn(int u)
{
    for(int i=0 ; i<adj[u].size() ; i++)
    {
        int v = adj[u][i] ;
        if(seen[v])
            continue;

        seen[v] = 1 ;

        if(right[v] == -1 or kuhn(right[v]))
        {
            right[v] = u ;
            left[u] = v ;
            return 1 ;
        }
    }
    return 0 ;
}

int biparatematching()
{
    clr(left,-1);
    clr(right,-1);
    int cont = 0 ;

    for(int i=0 ; i<m ; i++) // m is the number of person in left side
    {
        clr(seen,0);
        if(kuhn(i))
            cont++;
    }
    return cont ;
}
