#include<stdio.h>
int main()
{
    int a,rem,i,num[100],b,j=0;
    scanf("%d",&a);
    b=a;
    for(i=0;i<=a;i++){
            rem=b%2;
            num[i]=rem;
            j++;
            b=b/2;
            if(b==0)
            break;

    }
    b=a;
    for(i=j-1;i>-1;i--){
            b=b/2;
        printf("%d",num[i]);
    if(b==0)
        break;
    }
    return 0;
}
