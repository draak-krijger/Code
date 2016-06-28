#include<stdio.h>
int main()
{
    int i,n,j;
    for(j=1;j>0;j++){
    while(scanf("%d",&n)){
    double sum=0,l,avr;
    for(i=0;i<n;i++){
        scanf("%lf",&l);
        sum=sum+l;
    }
    avr=sum/n;
    printf("Case %d : %.02lf\n",j,avr);
    j++;
    }
    }
    return 0;
}
