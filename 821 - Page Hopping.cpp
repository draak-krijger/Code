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
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000000+10
#define MOD 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

int matrix[110][110] ;
bool conc[110] ;

void reset()
{
    for(int i=1 ; i<110 ; i++)
    {
        for(int j=1 ; j<110 ; j++)
        {
            matrix[i][j] = Max;
        }
        conc[i] = true;
    }
}

void floyed()
{
    forln(i,1,101)
    {
        forln(j,1,101)
        {
            forln(k,1,101)
            {
                if(matrix[k][i]+matrix[i][j]<matrix[k][j])
                    matrix[k][j] = matrix[k][i]+matrix[i][j] ;
            }
        }
    }
}

int main()
{
    int a , b , n = 0 , sum , tcase = 1;

    while(scanf("%d %d",&a,&b) != EOF)
    {
        reset();

        if(!a && !b)
            return 0;
//cout<<"ok"<<endl;
        if(conc[a])
            n++,conc[a] = false;

        if(conc[b])
            n++,conc[b]=false;
        matrix[a][b] = 1 ;

        while(scanf("%d %d",&a,&b) != EOF)
        {
            if(!a && !b)
                break;

            if(conc[a])
                n++,conc[a] = false;

            if(conc[b])
                n++,conc[b]=false;

            matrix[a][b] = 1 ;
        }
        floyed();
        sum = 0 ;

        forln(i,1,101)
        {
            forln(j,1,101)
            {
                if(matrix[i][j] != Max && i!= j)
                    sum += matrix[i][j] ;
            }
        }

        printf("Case %d: average length between pages = %.3lf clicks\n",tcase++,(double)sum/(double)(n*(n-1)));
        n = 0 ;
    }
    return 0;
}
