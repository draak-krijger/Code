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

char a[300] , b[300] ;
int c[600] ;

int main()
{
    int len1 , len2 , tcase , n , num1 , num2 ;

    while(scanf("%s %s",a,b) != EOF)
    {
        len1 = strlen(a) ;
        len2 = strlen(b) ;
        clr(c,0);

        for(int i=len1-1 ; i>=0 ; i--)
        {
            num1 = a[i] - '0' ;
            n = len1-1-i ;
            for(int j=len2-1 ; j>=0 ; j--)
            {
                num2 = b[j] - '0' ;
                c[n++] += num1*num2 ;
            }
        }

        for(int i=0 ; i<n-1 ; i++)
        {
            if(c[i]>9)
            {
                c[i+1] += c[i]/10 ;
                c[i] %= 10 ;
            }
        }

        int i ;

        for(i=n-1 ; i>=0 ; i--)
        {
            if(c[i] != 0)
                break;
        }

        if(i == -1)
            printf("0\n");

        else
        {
            for(;i>=0 ; i--)
                printf("%d",c[i]);

            printf("\n");
        }
    }
    return 0;
}
