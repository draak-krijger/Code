#include<stdio.h>
#include<math.h>
int prime(int a)
{
    int b = 1 , i , j ;
    if(a == 1)
        b = 0 ;
    for(i=2 ; i<=sqrt(a) ; i++)
    {
        if(a%i == 0)
        {
            b = 0;
            break;
        }
    }
    return b;
}
int main()
{
    int a , b , c , d , i , j  , k , l[50] ;
    while(scanf("%d",&a) == 1)
    {
        c=0;
        j=0;
        if(a == 0)
            break;
        for(i=0 ; i<50 ; i++)
            l[i]=0 ;
        for(i=2 ; i<=a ; i++)
        {
            if(prime(i) == 1)
            {
                l[j]++;
                j++;
            }
            else
            {
                c = 0;
                d = i;
                for(k=2 ; k<=d ;)
                {
                    if(prime(k) == 1)
                    {
                        if(d%k == 0)
                        {
                            l[c]++ ;
                            d = d/k ;
                        }
                        else
                        {
                            k++;
                            c++;
                        }
                    }
                    else
                        k++;
                }
            }
        }
        printf("%3d! =",a);
        for(i=0 ; i<j ; i++)
        {
            printf("%3d",l[i]);
            if (i == 14 && i != j-1)
                printf("\n%6c",' ');
        }
        printf("\n");
    }
    return 0 ;
}

