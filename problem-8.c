#include <stdio.h>
int main()
{
    int a,n;
    while(scanf("%d",&a)){
            if(a==0)
            break;
    int b,i,j=0,cou=0;
    int dv[a];
    for(i=0;i<a;i++){
        b=a/(i+1);
        if(a%(i+1)==0){
                dv[j]=b;
                j++;
                cou++;
                if(b==1)
                    break;
            }
    }
    n=cou-1;
    printf("Divisor of %d: ",a);
    for(n;n>-1;n--){
        printf("%d ",dv[n]);
    }
    printf("\n");
    }
    return 0;
}
