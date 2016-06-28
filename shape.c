#include<stdio.h>
int main()
{
    int i,j,a=1,b;
    char c='*';
    scanf("%d",&b);
    for(i=0;i<a;i++)
    {
        printf("%c",c);
        if(i==(a-1))
        {
            printf("\n");
            a++;
            i=-1;
        }
        if(a==b){
            for(i=1;i<(a-1);i++){
                printf("%c",c);
                if(i==(a-2)){
                    printf("\n");
                    a--;
                    i=0;
                }
            }
        }
        if(a==0)
            break;
    }
}
