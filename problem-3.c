#include<stdio.h>

int main()
{
    int a,i,sum=0;
    scanf("%d",&a);
    int num[a];
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);
        sum=sum+num[i];
    }
    printf("%d",sum);
    return 0;
}

