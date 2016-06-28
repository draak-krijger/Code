#include<stdio.h>
#include<math.h>

int main()
{
    int a,i;
    double pi=2*acos(0.0);
    scanf("%d",&a);
    if(a<1000){
    float red[a],ans[a];
    for(i=0;i<a;i++){
        scanf("%f",&red[i]);
        if(0 < red[i] <= 1000){
        ans[i]=pow((2*red[i]),2)-(pi*pow(red[i],2));
        }
    }
    for(i=0;i<a;i++){
        printf("%.2f\n",ans[i]);
    }
    }
    return 0;
}
