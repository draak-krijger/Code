#include <stdio.h>
int main()
{
    int i,a[5];
    for(i = 0 ; i < 5 ; i++){
    scanf("%d",&a[i]);
    }
    int max=0,min=100;
    for(i=0;i<5;i++){
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    printf("%d %d",max,min);
    return 0;
}
