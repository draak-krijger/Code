#include <stdio.h>
int main()
{
    int a,b,ans[10000],i=0;
    long long int c;
    while(1){
        c=1;
        scanf("%d %d",&a,&b);
        if(a==0||b==0)
            break;
        while(b!=0){
            c=(c*a)%100007;
            b--;
        }
        ans[i]=c;
        i++;
    }
    for(c=0;c<i;c++){
        printf("%d\n",ans[c]);
    }
    return 0;
}
