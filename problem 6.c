#include<stdio.h>

int main()
{
    int n,i,ans=1;
    scanf("%d",&n);
    if(n>=12){
        printf("Please enter a number less than 12.\n");
    }
    else{
    for(i=1;i<=n;i++)
    {
        ans=ans*i;
    }
    printf("%d\n",ans);
    }
    return 0;
}
