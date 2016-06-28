#include<stdio.h>
int main()
{
    int i,n,j=1;
    while(scanf("%d",&n)){
    double sum=0,l,avr;
    for(i=0;i<n;i++){
        scanf("%lf",&l);
        sum=sum+l;
    }
    avr=sum/n;
    printf("Case %d : %lf\n",j,avr);
    j++;
    }
    return 0;
}
