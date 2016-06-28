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

int arra[Max] , tree[3*Max] ;

void initial(int node , int b , int e);
int quary(int node , int b , int e , int i , int j );

int main()
{
    int tcase , n , q , ith , jth ;

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

        while(q--)
        {
            sf2(ith,jth);
            printf("%d\n",quary(1,1,n,ith,jth));
        }
    }
    return 0;
}

void initial(int node , int b , int e)
{
    if(b==e)
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

    tree[node] = min(tree[lft],tree[rigt]);
    //cout<<tree[node]<<endl;
}

int quary(int node , int b , int e , int i , int j )
{
    if(i>e || j<b)
        return 100010 ;

    if(i<=b && j>=e)
        return tree[node];
    //cout<<"ok "<<endl;
    int lft , rigt , mid , p1 , p2 ;

    lft = 2*node ;
    rigt = 2*node + 1 ;
    mid = (b+e)/2 ;
    p1 = quary(lft,b,mid,i,j);
    p2 = quary(rigt,mid+1,e,i,j);
//cout<<p1<< " " << p2 <<endl;
    return min(p1,p2);
}
