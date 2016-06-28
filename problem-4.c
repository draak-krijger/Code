#include<stdio.h>

int main()

{
    int i,n;
    scanf("%d",&n);
    int num[n],sum=0,res[n];
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum=sum+num[i];
        res[i]=sum;
    }
    for(i=0;i<n;i++){
        printf("%d ",res[i]);
    }
    return 0;
}
