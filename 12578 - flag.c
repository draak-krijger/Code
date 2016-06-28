#include <stdio.h>
#include <math.h>
#define pi acos(-1)

int main()
{

    int a , t ;
    double b  ;

    while(scanf("%d",&t) != EOF)
   {
       while(t--)
       {
           scanf("%d",&a) != EOF;

           b = pi*pow((a*(double)2/(double)10),2) ;

           printf("%.2lf ",b);

           b = (a*a*(double)6/(double)10)-b ;

           printf("%.2lf\n",b);

       }
   }

    return 0 ;
}

