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
#define Max 600000+10

int arra[38] , n , tacken[38] ;
vector<int>result ;
bool prime[38] ;

void initial();
void backtracking();

int main()
{
    initial();
    int cas = 1 ;

    while(sf1(n) != EOF)
    {
        if(cas>1)
            printf("\n");

        printf("Case %d:\n",cas++);
        result.clear();
        result.pb(1);
        tacken[1] = 1 ;
        backtracking();
    }
    return 0;
}

void initial()
{
    for(int i=1 ; i<=35 ; i++)
    {
        prime[i] = true;
        arra[i] = i ;
        tacken[i] = 0 ;
    }

    prime[2] = false;
    prime[3] = false;
    prime[5] = false;
    prime[7] = false;
    prime[11] = false;
    prime[13] = false;
    prime[17] = false ;
    prime[19] = false ;
    prime[23] = false ;
    prime[29] = false ;
    prime[31] = false ;
}

void backtracking()
{
    if(result.size()== n)
    {
        if(prime[result[n-1]+1])
            return;

        printf("%d",result[0]);

        for(int i=1 ; i<n ; i++)
            printf(" %d",result[i]);

        printf("\n");
        return;
    }

    for(int i=2 ; i<=n ; i++)
    {
        if(!tacken[i])
        {
            if(prime[arra[i]+result[result.size()-1]])
                continue;

//            if(prime[arra[i]+1] && result.size() == n-1)
//                continue;

            tacken[i] = 1 ;
            result.pb(arra[i]);
            backtracking();
            tacken[i] = 0 ;

            //if(result.size() != 1)
                result.pp();
        }
    }
}
