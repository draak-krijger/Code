#include <stdio.h>
int main ()
{
    int t, n, i, age[15], j ;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n%2 == 0)
         break;
        if(n%2 != 0){
        for(j=0;j<n;j++)
        {
            scanf("%d", &age[j]);
        }
        n=n/2;
        printf("Case %d: %d\n",i+1 ,age[n]);
        }
    }
    return 0;
}

