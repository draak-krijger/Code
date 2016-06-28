struct sfx
{
    int tple[2] , indx ;

    bool operator < (const sfx& p) const
    {
        return tple[0] == p.tple[0] ? tple[1]<p.tple[1] : tple[0] < p.tple[0] ;
    }
};

sfx arr[sz] ;
int rnk[20][sz] , step ;
char str[sz] ;

void build_suffix_array()
{
    int len = strlen(str);

    for(int i=0 ; i<len ; i++)
    {
        rnk[0][i] = str[i] ;

        arr[i].tple[0] = arr[i].tple[1] = 0 ;
    }

    step = 1 ;

    for(int i=1 ; i<len ; step++, i<<=1)
    {
        for(int j=0 ; j<len ; j++)
        {
            arr[j].indx = j ;
            arr[j].tple[0] = rnk[step-1][j] ;
            arr[j].tple[1] = (j+i < len ? rnk[step-1][j+i] : -1) ;
        }

        sort(arr,arr+len);

        rnk[step][arr[0].indx] = 0 ;

        for(int j=1 ; j<len ; j++)
        {
            if(arr[j].tple[0] == arr[j-1].tple[0] and arr[j].tple[1] == arr[j-1].tple[1])
                rnk[step][arr[j].indx] = rnk[step][arr[j-1].indx] ;

            else
                rnk[step][arr[j].indx] = j ;
        }
    }

    for(int i=0 ; i<len ; i++)
        deb(arr[i].indx);
}

int build_lcp()
{
    int lcp = 0 , len = strlen(str) ;

    for(int j=1 ; j<len ; j++)
    {
        int id1 = arr[j-1].indx , id2 = arr[j].indx , lp = 0 ;

        for(int i=step-1 ; i>=0 ; i--)
        {
            if(rnk[i][id1] == rnk[i][id2] and rnk[i][id2])
            {
                lp += (1<<i) ;
                id1 += (1<<i) ;
                id2 += (1<<i) ;
            }
        }
        lcp += lp ;
    }
    return lcp ;
}

int main()
{
    sf("%s",str);

    build_suffix_array();
    int ans = build_lcp();

    deb(ans);

    return 0;
}

