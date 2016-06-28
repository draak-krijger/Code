#include <stdio.h>
int main()
{
    int a,b,c,d,i,j,k;
    scanf("%d",&a);
    if(a<=100){
    int ans[a];
    for(i=0;i<a;i++){
        ans[i]=0;
        scanf("%d",&b);
        if(b<1 || b>1000)
            break;
        for(j=0;j<b;j++){
            scanf("%d",&c);
            if(c<1 || c>99)
                break;
            ans[i]+=c;
        }
        if(c<1&&c>99)
            break;
    }
    for(i=0;i<a;i++){
        if(b>0 && b<1001){
            if(b<1 || b>1000)
                break;
            if(c<1 || c>99)
                break;
        printf("Case %d: %d\n",i+1,ans[i]);
        }
    }
    }
    return 0;
}

