#include <stdio.h>
int main ()
{
    int n,a,sum;
    printf("n=");
    scanf("%d",&n);
    for(a=1,sum=0;a<=n;a=a+1){
        sum=a+sum;
    }
    printf("sum is :%d\n",sum);
    return 0;
}
