#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int num[a],i;
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);
    }
    int min=num[0];
    for(i=1;i<a;i++){
        if(min>num[i])
            min=num[i];
    }
    int max=num[0];
    for(i=1;i<a;i++){
        if(max<num[i])
            max=num[i];
    }
    printf("%d",max-min);
    return 0;
}
