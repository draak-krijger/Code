#include <stdio.h>
int main()
{
    int n,i;
    while(1)
    {
        printf("Enter Your Required Namta:");
        scanf("%d",&n);
        for(i=1; i<=10; i=i+1)
        {
            printf("%dx%d=%d\n",n,i,n*i);
        }
        printf("\n");
    }
    return 0;
}
