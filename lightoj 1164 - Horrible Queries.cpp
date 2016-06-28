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
#define Max 100000+20

struct node
{
    long long int sum , prog ;
};

node tree[3*Max] ;

long long query(int node , int b , int e , int i , int j , long long int carry );
void initial(int node,int b , int e);
void update(int node , int b , int e , int i , int j , int x);

int main()
{
    int tcase , n , m , tst ,x , y , v ;
    long long result ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        printf("Case %d:\n",cas);
        sf2(n,m);
        initial(1,1,n);

        forln(i,0,m)
        {
            sf1(tst);

            if(tst == 0)
            {
                sf3(x,y,v);
                update(1,1,n,x+1,y+1,v);
            }

            else if(tst == 1)
            {
                sf2(x,y);
                result = query(1,1,n,x+1,y+1,0);
                printf("%lld\n",result);
            }
        }
    }
    return 0;
}

void initial(int node,int b , int e)
{
    if(b==e)
    {
        tree[node].sum = 0 ;
        tree[node].prog = 0 ;
        return;
    }

    int lft , rigt , mid ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    initial(lft,b,mid);
    initial(rigt,mid+1,e);

    tree[node].sum = 0 ;
    tree[node].prog = 0 ;
}

void update(int node , int b , int e , int i , int j , int x)
{
    if(i>e || j<b)
        return;

    if(i<=b && j>=e)
    {
        tree[node].sum += (long long)((e-b+1)*x) ;
        tree[node].prog +=x ;
        return;
    }

    int lft , rigt , mid ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    update(lft,b,mid,i,j,x);
    update(rigt,mid+1,e,i,j,x);

    tree[node].sum = tree[lft].sum + tree[rigt].sum + ((e-b+1)*tree[node].prog) ;
}

long long query(int node , int b , int e , int i , int j ,long long int carry )
{
    if(i>e || j<b)
        return 0;

    if(i<=b && j>=e)
    {
        return tree[node].sum + carry*(e-b+1);
    }

    int lft , rigt , mid ;
    long long p , q ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;

    p = query(lft,b,mid,i,j,carry+tree[node].prog);
    q = query(rigt,mid+1,e,i,j,carry+tree[node].prog);

    return p+q ;
}
