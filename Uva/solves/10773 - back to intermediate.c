#include <stdio.h>
#include <math.h>
int main()
{
    int t ,i,j;
    double k ,s,v,u;
    scanf("%d",&t);
    for(i=0 ; i<t ; i++)
    {
        scanf("%lf %lf %lf",&s,&v,&u);
        if(v== 0 || u==0 || v>=u)
        {
            printf("Case %d: can't determine\n",i+1);
            continue;
        }
            k=(s/(sqrt(u*u-v*v))) - (double)(s/u) ;
            printf("Case %d: %.3lf\n",i+1,k);
    }
    return 0;
}

