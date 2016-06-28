#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,i=0,ans[1000];
    long long c;
    while(1){
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)
            break;
        c=pow(a,b);
        if(c>100007)
            c=fmod(c,100007);
        ans[i]=c;
        i++;
    }
    for(a=0;a<i;a++){
        printf("%ld\n",ans[a]);
    }
    return 0;
}

