#include<stdio.h>
#include<math.h>
int main()
{
    int t,i,a,j;
    scanf("%d",&t);
    int l[t];
    for(i=0;i<t;i++){
            l[i]=0;
        scanf("%d",&a);
        if(a>pow(2,31))
            break;
        if(a==1){
            l[i]=1;
        }
        for(j=2;j<a;j++){
            if(a%j==0){
                l[i]=1;
                break;
            }
        }
    }
    for(i=0;i<t;i++){
        if(l[i]==1)
            printf("Case %d: No\n",i+1);
        else if(l[i]==0)
            printf("Case %d: Yes\n",i+1);
    }
    return 0;
}
