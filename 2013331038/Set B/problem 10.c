#include <stdio.h>
int main()
{
    double a=2,i;
    int l,t=0;
    for(a;a>0;a++){
        for(i=2;i<=a;i++){
            if(fmod(a,i)==0)
                {
                if(a!=i)
                   break;
                if(a==i){
                    t++;
                    if(t==1500)
                        l=a;
                }
            }
        }
        if(t==1500)
            break;
    }
    printf("%d",l);
    return 0;
}

