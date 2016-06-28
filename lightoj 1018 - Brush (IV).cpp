#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define pp pop_back
#define foren(i,a,b) for(int i=a ; i<=b ; i++)
#define forln(i,a,b) for(int i=a ; i<b ; i++)
#define fore0(i,a,b) for(int i=a ; i>=b ; i--)
#define fore0(i,a,b) for(int i=a ; i>b ; i--)
#define clr(a,b) memset(a,b,sizeof(a))
#define pii acos(-1.0)
#define Max 1<<18
#define Mod 10000007
#define sf1i(a) scanf("%d",&a)
#define sf1l(a) scanf("%lld",&a)
#define ll long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c)) min(a,min(b,c))

struct point
{
    int x , y ;
};

int dp[Max] , straight[18][18] , n ;
point co_ordinate[18] ;

int set_bit(int n,int pos)
{
    n = n | (1<<pos);
    return n ;
}

bool check_bit(int n,int pos)
{
    return n & (1<<pos);
}

bool isstraight(point a,point b,point c)
{
    if((ll)(a.x-b.x)*(b.y-c.y) == (ll)(a.y-b.y)*(b.x-c.x))
        return true;

    return false;
}

void pre_cal()
{
    forln(i,0,n)
    {
        forln(j,0,n)
        {
            int bit = (1<<j) ;

            forln(k,0,n)
            {
                if(isstraight(co_ordinate[i],co_ordinate[j],co_ordinate[k]))
                    bit = set_bit(bit,k);
            }
            straight[i][j] = set_bit(bit,i) ;
            //cout<<i << " " << j << " " <<straight[i][j]<<endl;
        }
    }
}

int rec(int mask)
{
    if(mask == (1<<n)-1)
        return 0;
//cout<<mask<<endl;
    if(dp[mask] != -1)
        return dp[mask];

    int ans = 500 ;

    for(int i=0 ; i<n ; i++)
    {
        if(!check_bit(mask,i))
        {
            for(int j=i+1 ; j<n ; j++)
            {
                ans = min(ans,rec(mask | straight[i][j])+1);
                //cout<<rec(mask | straight[i][j])<<" "<<mask<<endl;
            }
            break;
        }
    }
//    cout<<mask<<" "<<ans<<endl;
    return dp[mask] = ans;
}

int main()
{
    int tcase , result ;
    sf1i(tcase);

    foren(cas,1,tcase)
    {
        sf1i(n);
        clr(dp,-1);

        forln(i,0,n)
        {
            scanf("%d %d",&co_ordinate[i].x,&co_ordinate[i].y);
        }
        //cout<<"ok :"<<endl<<endl;
        pre_cal();
        result = 1 ;

        if(n != 1)
            result = rec(0) ;

        printf("Case %d: %d\n",cas,result);
    }
    return 0;
}
