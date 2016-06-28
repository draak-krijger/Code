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
#define Max 5000000+10

deque<int>myq ;
int l ;

void iftar(int n);

int main()
{
    int tcase , p , ate ;
    sf1(tcase);

    foren(cas,1,tcase)
    {
        sf2(p,l);
        iftar(p-l);

        printf("Case %d:",cas);

        if(!myq.empty())
        {
//            printf("%d",myq.front());
//            myq.pop_front();

            while(!myq.empty())
            {
                printf(" %d",myq.front());
                myq.pop_front();
            }
            printf("\n");
        }

        else
            printf(" impossible\n");
    }
    return 0;
}

void iftar(int n)
{
    myq.clear();
    for(int i=sqrt(n) ; i>0 ; i--)
    {
        if(i*i == n)
        {
            if(i>l)
                myq.pb(i);
        }

        else if(n%i == 0)
        {
            if(i>l)
                myq.push_front(i);

            if((n/i)>l)
                myq.pb(n/i) ;
        }
    }
}
