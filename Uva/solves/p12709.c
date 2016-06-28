#include <stdio.h>
#define g 9.81
int main()
{
    int a,e=0,i,j,k=0,test[500];
    double max;
    while(1){
    scanf("%d",&a);
    if(a==0)
        break;
    double f[a];
    int b[a],c[a],d[a],v[a];
    if(a>0 && a<101){
        for(i=0;i<a;i++){
        scanf("%d%d%d",&b[i],&c[i],&d[i]);
            f[i]=g-(g/(2*d[i]));
            v[i]=b[i]*c[i]*d[i];
        }
        max=f[0];
        for(i=1;i<a;i++){
            if(max==f[i]){
                if(v[i]>v[i-1]){
                    max=f[i];
                    e=v[i];
                }
                else{
                    max=f[i-1];
                    e=v[i];
                }
            }
            if(max<f[i]){
                max=f[i];
                e=v[i];
            }
        }
        test[k]=e;
    }
    k++;
    }
    for(i=0;i<k;i++){
        printf("%d\n",test[i]);
    }
    return 0;
}

