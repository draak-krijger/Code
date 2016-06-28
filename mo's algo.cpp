
struct _index
{
    int indx , l , r , box ;
};

_index qury[sz] ;
int cont[1000000+7] , block , ans , valu[30000+11] , fans[sz] ;

bool cmp(_index a,_index b)
{
    if(a.box == b.box)
        return a.r < b.r ;

    return a.box < b.box ;
}

void add(int v)
{
    cont[v]++;

    if(cont[v] == 1)
        ans++;
}

void _remove(int v)
{
    cont[v]--;

    if(!cont[v])
        ans--;
}

int main()
{
    int n , q , l , r , box ;

    sf1(n);

    box = sqrt(n) ;
    box += 10 ;

    for(int i=0 ; i<n ; i++)
        sf1(valu[i+1]);

    sf1(q);

    for(int i=0 ; i<q ; i++)
    {
        sf2(qury[i].l,qury[i].r);
        qury[i].box = qury[i].l / box ;
        qury[i].indx = i ;
    }

    sort(qury,qury+q,cmp);

    l = 1 ;
    r = 1 ;

    for(int i=0 ; i<q ; i++)
    {
        while(r<=qury[i].r)
        {
            add(valu[r]);
            r++;
        }

        while(r>qury[i].r+1)
        {
            _remove(valu[r-1]);
            r--;
        }

        while(l>qury[i].l)
        {
            add(valu[l-1]);
            l--;
        }

        while(l<qury[i].l)
        {
            _remove(valu[l]);
            l++;
        }
//deb(qury[i].l,qury[i].r,ans);
        fans[qury[i].indx] = ans ;
    }

    for(int i=0 ; i<q ; i++)
        pf("%d\n",fans[i]);

    return 0;
}
