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

struct id
{
    int indx ;
    char num[1000] ;
};

bool cmp(id a,id b)
{
    if(a.indx<b.indx)
        return true;

    return false;
}

id arra[10000] ;

int main()
{
    int tcase , len , num , j ;
    char str[1000000] ;

    sf1(tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        getchar();
        getchar();

        if(cas>1)
            printf("\n");

        gets(str);
        len = strlen(str);
        j = 0 ;
        num = 0 ;
        for(int i=0 ; i<len ; i++)
        {//cout<<str[i];
            if(isdigit(str[i]))
            {
                num = num*10 + (str[i] - '0') ;

                if(i==len-1)
                    arra[j++].indx = num ;
            }

            else
            {
                arra[j++].indx = num ;
                num = 0 ;
            }
        }

        for(int i=0 ; i<j ; i++)
        {
            scanf("%s",&arra[i].num);
        }

        sort(arra,arra+j,cmp);

        for(int i=0 ; i<j ; i++)
        {
            printf("%s\n",arra[i].num);
        }
    }
    return 0;
}
