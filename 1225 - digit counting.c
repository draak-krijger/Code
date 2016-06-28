#include <stdio.h>
int main()
{
    int a , b , c , d , i , j ,l[10];
    while(scanf("%d",&c) == 1)
    {
        for(j=0 ; j<c ; j++)
        {
            b=0;
            for(i=0 ; i<10 ; i++)
            l[i] = 0 ;
            scanf("%d",&a) != EOF ;
            while(a>0)
            {
                if(b == 0)
                {
                    b = a;
                    a--;
                }
                d = b%10;
                b = b/10 ;
                if(d==0)
                    l[0]++;
                else if(d==1)
                    l[1]++;
                else if(d==2)
                    l[2]++;
                else if(d==3)
                    l[3]++;
                else if(d==4)
                    l[4]++;
                else if(d==5)
                    l[5]++;
                else if(d==6)
                    l[6]++;
                else if(d==7)
                    l[7]++;
                else if(d==8)
                    l[8]++;
                else if(d==9)
                    l[9]++;
            }
            for(i=0 ; i<10 ; i++)
            {
                printf("%d",l[i]);
                if(i==9)
                {
                    printf("\n");
                    break;
                }
                printf(" ");
            }
        }
    }
    return 0;
}

