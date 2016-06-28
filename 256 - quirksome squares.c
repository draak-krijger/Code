/*#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,d,e,i,j,k=0,num[100];
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    while(scanf("%d",&a) == 1)
    {
        k=0;
        b=round(pow(10,a))-1;
        c=round(pow(10,(a/2)))-1;
        if( a == 2 || a == 4 || a==6 || a==8)
        {
            for(i=0; i<=c; i++)
            {
                for(j=0; j<=c; j++)
                {
                    d=round(pow((i+j),2));
                    e=round(i* pow(10,(a/2))+j);
                    if(d==e)
                    {
                        num[k]=e;
                        k++;
                    }
                }
            }
            for(i=0; i<k; i++)
            {
                if(a==2)
                    printf("%02d\n",num[i]);
                else if(a==4)
                    printf("%04d\n",num[i]);
                else if(a==6)
                    printf("%06d\n",num[i]);
                else if(a==8)
                    printf("%08d\n",num[i]);
            }
        }
        else
            break;
    }
    return 0;
}*/
//this problem accepted another way...

#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if (n==2)
            printf("00\n01\n81\n");
        else if (n==4)
            printf("0000\n0001\n2025\n3025\n9801\n");
        else if (n == 6)
            printf("000000\n000001\n088209\n494209\n998001\n");
        else if (n == 8)
            printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
        else
            break;
    }
    return 0;
}


