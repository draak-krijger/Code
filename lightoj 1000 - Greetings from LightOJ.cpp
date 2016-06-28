#include <stdio.h>
int main()
{
    int t,a,b,i;
    scanf("%d",&t);
    int res[t];
    if(t<=125){
        for(i=0;i<t;i++){
            scanf("%d%d",&a,&b);
            if(-1<a&&a<11&&-1<b&&b<11){
            res[i]=a+b;
            }
            else
                break;
            }
            for(i=0;i<t;i++){
                if(-1<a&&a<11&&-1<b&&b<11){
                printf("Case %d: %d\n",i+1,res[i]);
                }
            }
    }
    return 0;
}
