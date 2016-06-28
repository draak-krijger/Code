#include <stdio.h>

int max(int a,int b,int c)
{
    int maxi=a;
    if(b>a)
        maxi = b;
    if(maxi < c)
        maxi = c;
    return maxi;
}

int min(int a,int b,int c)
{
    int mini = a;
    if(b < a)
        mini = b;
    if(mini > c)
        mini = c;
    return mini;
}
int main()
{
    int t, a, b, c, d, e, i;
    scanf("%d ",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d",&a ,&b ,&c);
        d = max(a,b,c);
        e = min(a,b,c);
        if(a < d && a > e)
            printf("Case %d: %d\n",i+1 ,a);
        else if(b < d && b > e)
            printf("Case %d: %d\n",i+1 ,b);
        else
            printf("Case %d: %d\n",i+1 ,c);
    }
    return 0;
}

