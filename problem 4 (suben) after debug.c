#include <stdio.h>

int main()
{
    int i,j,a;
    scanf("%d",&a);
    int b[a];
    char w[4];
        for(i=0;i<a;i++){
                b[i]=0;
                scanf("%s",w);
                for(j=0;j<3;j++){
                    b[i]=b[i]+w[j];
                }
        }
        for(i=0;i<a;i++)
        {
            printf("%d\n",b[i]);
        }


    return 0;
}
