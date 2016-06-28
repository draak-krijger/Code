#include <stdio.h>
#include <string.h>
int main()
{
    int a,b,c,d,i,j,k,l;
    scanf("%d",&a);
    char nam[a][12],nam_test[12];
    int amn[a];
    for(i=0; i<a; i++)
    {
        amn[i]=0;
        scanf("%s",&nam[i]);
    }
    for(i=0; i<a; i++)
    {
        scanf("%s",&nam_test);
        j=0;
        while(1)
        {
            if(strcmp(nam[j],nam_test)==0)
                break;
            j++;
        }
        scanf("%d",&b);
        scanf("%d",&c);
        if(c==0)
            continue;
        d=b/c;
        amn[j]=amn[j]-(d*c);
        for(k=0; k<c; k++)
        {
            scanf("%s",&nam_test);
            l=0;
            while(1)
            {
                if(strcmp(nam[l],nam_test)==0)
                    break;
                l++;
            }
            amn[l]=amn[l]+d;
        }
    }
    for(i=0; i<a; i++)
    {
        printf("%s %d\n",nam[i],amn[i]);
    }
    return 0;
}

