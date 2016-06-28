#include <stdio.h>
int main(){
    char ara1[5];
    scanf("%s",ara1);
    int i,sum=0;
    for(i=0;i<5;i++){
        sum=sum +ara1[i];
    }
    printf("%d",sum);

    return 0;
}
