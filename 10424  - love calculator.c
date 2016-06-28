#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int a[2] , d[2] , b , i , j ;
    double e ;
    char c[2][29];
    while(gets(c[0]) && gets(c[1]) != EOF)
    {
        for(j=0 ; j<2 ; j++)
        {
            a[j] = 0 ;
            b = strlen(c[j]);
            for(i=0 ; i<b ; i++)
            {
                if(isalpha(c[j][i]))
                {
                    if(islower(c[j][i]))
                    {
                        a[j] += c[j][i] - 'a' + 1 ;
                    }
                    else if(isupper(c[j][i]))
                    {
                        a[j] += c[j][i] - 'A' + 1;
                    }
                }
            }
            loop:
                e = 0 ;
                while(a[j]>0)
                {
                    e += a[j]%10 ;
                    a[j] /= 10 ;
                }
                if(e>9)
                {
                    a[j] = e ;
                    goto loop ;
                }
                d[j]= e ;
        }
        if(d[0] > d[1])
            e = ((double)d[1]/d[0])*100;
        else
            e = ((double)d[0]/d[1])*100;
        printf("%.02lf %%\n",e);
    }
    return 0 ;
}

