#include<stdio.h>
int main()
{
    int a,i,j=0;
    double x,y,a1,b1,c1,a2,b2,c2;
    scanf("%d",&a);
    double res[2*a];
    for(i=0;i<a;i++){
        scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&c1,&a2,&b2,&c2);
        printf("\n");
        x=(b2*c1-b1*c2)/(a1*b2-a2*b1);
        y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
        res[j]=x;
        res[j+1]=y;
        j=j+2;
    }
    j=1;
    for(i=0;i<2*a;i=i+2){
        printf("Case %d : X=%.3lf , Y=%.3lf\n",j,res[i],res[i+1]);
        j++;
    }
}
