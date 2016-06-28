#include <stdio.h>
int main()
{
    int a , b , c , i , j ;
    double avr , k ;
    scanf("%d",&a);
    for(i=0; i<a; i++)
    {
        avr = 0;
        k=0;
        scanf("%d",&b);
        double num[b];
        for(j=0; j<b ; j++)
        {
            scanf("%lf",&num[j]);
            avr = avr+num[j];
        }
        avr = avr/b ;
        for(j=0; j<b ; j++)
        {
            if(num[j]>avr)
                k++;
        }
        printf("%.3lf%%\n",k/b*100);
    }
    return 0;
}

