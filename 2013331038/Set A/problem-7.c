#include<stdio.h>

int main()

{
    int i,n;
    scanf("%d",&n);
    int num=1,sum1=0,sum=0,res[n];
    for(i=0;i<n;i++){
        sum=sum1+num;
        num=sum1;
        sum1=sum;
        res[i]=sum;
    }
    for(i=0;i<n;i++){
        printf("%d\n",res[i]);
    }
    return 0;
}
