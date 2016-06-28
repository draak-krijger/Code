// Segment Tree 1
#include <bits/stdc++.h>

using namespace std ;

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 100000+10
#define ll long long

int arra[Max] ;
long long tree[3*Max] ;

long long query(int node , int b , int e , int i , int j);
void initial(int node , int b , int e);
void update(int node , int b , int e , int i , int valu);

int main()
{
    int tcase , n , q , a , ith , jth , valu ;
    long long b ;

    sf1(tcase);

    foren(cas,1,tcase)
    {
        printf("Case %d:\n",cas);
        sf2(n,q);

        foren(i,1,n)
        {
            sf1(arra[i]);
        }

        initial(1,1,n);

        forln(i,0,q)
        {
            sf1(a);

            if(a == 1)
            {
                sf1(ith);
                b = query(1,1,n,ith+1,ith+1) ;

                printf("%lld\n",b);
                update(1,1,n,ith+1,-b);
            }

            else if(a == 2)
            {
                sf2(ith,valu);
                update(1,1,n,ith+1,valu);
                //cout<<query(1,1,n,ith+1,ith+1)<<endl;
            }

            else if(a == 3)
            {
                sf2(ith,jth);
                b = query(1,1,n,ith+1,jth+1);
                printf("%lld\n",b);
            }
        }
    }
    return 0;
}

void initial(int node , int b , int e)
{
    if(b == e)
    {
        tree[node] = arra[b];
        return;
    }

    int lft , rigt , mid ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    initial(lft,b,mid);
    initial(rigt,mid+1,e);

    tree[node] = tree[lft] + tree[rigt] ;
}

void update(int node , int b , int e , int i , int valu)
{
    if(i<b || i>e)
        return ;

    if(i<=b && i>=e )
    {
        tree[node] += valu ;
        return;
    }

    int lft , rigt , mid ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    update(lft,b,mid,i,valu);
    update(rigt,mid+1,e,i,valu);

    tree[node] = tree[lft] + tree[rigt];
}

long long query(int node , int b , int e , int i , int j)
{
    if(j<b || i>e)
        return 0 ;

    if(i<=b && j>=e)
        return tree[node];

    int lft , rigt , mid ;
    long long p1 , p2 ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    p1 = query(lft,b,mid,i,j);
    p2 = query(rigt,mid+1,e,i,j);

    return p1+p2 ;
}

