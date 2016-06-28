#include<stdio.h>
int main()
{
    int a,rem,sum=0,i,b;
    scanf("%d",&a);
    b=a;
    for(i=0;i<a;i++){
        rem=b%10;
        sum=sum+rem*pow(2,i);
        b=b/10;
        if(b==0)
            break;
    }
    printf("%d",sum);
    return 0;
}

