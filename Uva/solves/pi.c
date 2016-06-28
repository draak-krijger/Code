#include<stdio.h>
#include <math.h>
int gcd( int a, int b)
{
int k;
do
{
k=a ;
a=b%a ;
b=k ;
}while(a!=0);
return k;
}
int main()
{
    int a , b , i , j , k , l ;
    double d ;
    while(scanf("%d",&a) == 1)
    {
        if(a == 0)
            break ;
        l=0;
        int c[a];
        b = 0;
        for(i=0 ; i<a ; i++)
        {
            scanf("%d",&c[i]);
            b = b + i ;
        }
        k = 0;
        for(i = 0 ; i < a-1 ; i++)
        {
            k++;
            for(j=k ; j<a ; j++)
            {
                if(gcd(c[i],c[j]) < 2)
                    l++;
            }
        }
        if(l==0)
            printf("No estimate for this data set.\n");
        else{
                d = sqrt((b*6)/(l*1.0));
                printf("%.6lf\n",d);
        }
    }
    return 0;
}

