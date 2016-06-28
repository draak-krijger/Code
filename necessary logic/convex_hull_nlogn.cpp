jora_int points[sz] ;
stack<jora_int>st ;
int n ;

int orientation(jora_int p,jora_int q,jora_int r)
{
    int valu = (p.sc - q.sc)*(q.fs - r.fs) - (p.fs - q.fs)*(q.sc - r.sc) ;

    if(valu == 0)
        return 0;

    return (valu>0 ? 1 : 2) ;
}

int dist(jora_int a,jora_int b)
{
    int valu = (a.fs - b.fs)*(a.fs - b.fs) + (a.sc - b.sc)*(a.sc - b.sc) ;

    return valu ;
}

bool cmp(jora_int a,jora_int b)
{
    int valu = orientation(points[0],a,b) ;

    if(valu == 0)
    {
        if(dist(points[0],a) > dist(points[0],b))
            return 0 ;

        return 1 ;
    }

    return (valu == 2) ;
}

jora_int next_top()
{
    jora_int tp = st.top() , valu ;
    st.pop();

    valu = st.top();
    st.push(tp);

    return valu ;
}

void convex_hull()
{
    int mn = 0 ;

    for(int i=1 ; i<n ; i++)
    {
        if(points[i].sc<points[mn].sc)
            mn = i ;

        else if(points[i].sc == points[mn].sc and points[i].fs<points[mn].fs)
            mn = i ;
    }

    swap(points[0],points[mn]);

    sort(points+1,points+n,cmp);

    int m = 1 ;

    for(int i=1 ; i<n ; i++)
    {
        while(i<n-1 and orientation(points[0],points[i],points[i+1]) == 0)
            i++;

        points[m++] = points[i] ;
    }

    if(m<3)         // is checking convex polygon possible
        return ;

    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for(int i=3 ; i<m ; i++)
    {
        while(orientation(next_top(),st.top(),points[i]) != 2)
            st.pop();

        st.push(points[i]);
    }

    // here all point in stack is polygon co-ordinate
}
