#include <stdio.h>
#include <math.h>
int main()
{
    double u , v , s , t ,a ;
    int b,i=0,j ,k ;
    while(scanf("%d",&b))
    {
        i++;
        if(b == 0)
            break;
        else if(b == 1)
        {
            scanf("%lf %lf %lf",&u ,&v ,&t);
            a = (v-u)/t ;
            s= (v*v-u*u)/(2*a) ;
            printf("Case %d: %.3lf %.3lf\n",i,s,a);
        }
        else if(b == 2)
        {
            scanf("%lf %lf %lf",&u ,&v ,&a);
            s= (v*v-u*u)/(2*a) ;
            t= (v-u)/a ;
            printf("Case %d: %.3lf %.3lf\n",i,s,t);
        }
        else if(b == 3)
        {
            scanf("%lf %lf %lf",&u ,&a ,&s);
            v = sqrt(u*u+2*a*s);
            t =(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",i,v,t);
        }
        else if(b == 4)
        {
            scanf("%lf %lf %lf",&v ,&a,&s);
            u = sqrt(v*v - 2*a*s);
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",i,u,t);
        }
    }
    return 0;
}

