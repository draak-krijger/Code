#include <stdio.h>

int main()
{
    int a,b,c=0,i;
    scanf("%d %d",&a ,&b);
    if(a>b){
        for(i=b;i<=a;i++){
            c=c+i;
        }
    }
    else{
        for(i=a;i<=b;i++){
            c=c+i;
        }
    }
    printf("%d",c);
    return 0;
}

