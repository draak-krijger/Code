#include <stdio.h>

int main()
{
    int t,a,b,c,i;
    scanf("%d",&t);
    int sum[t];
    for(i=0;i<t;i++){
        scanf("%d%d%d",&a,&b,&c);
        sum[i]=a*b+b*c+c*a;
    }
    for(i=0;i<t;i++){
    printf("%d\n",sum[i]);
    }
    return 0;
}

