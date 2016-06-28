#include <stdio.h>
int main()
{
    int a,i;
    scanf("%d",&a);
    for(i=0; i<a; i++)
    {
        int b,j,k;
        scanf("%d",&b);
        int dol[b],max_dol[b],max,index,sum;
        for(j=0; j<b; j++)
        {
            scanf("%d",&dol[i]);
        }
        for(j=0; j<b; j++)
        {
            max=0;
            for(k=0; k<b; k++)
            {
                if(dol[k]>max)
                {
                    max=dol[k];
                    index=k;
                }
            }
            max_dol[j]=max;
            dol[index]=0;
            printf("%d",max_dol[j]);
        }
        if(b%3 != 0)
        {
            b=(b/3)*3;
        }
        sum=0;
        for(j=2; j<b; j=j+3)
        {
            sum=sum+max_dol[j];
        }
        printf("%d",sum);
    }
    return 0;
}
