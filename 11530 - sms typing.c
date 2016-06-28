#include <stdio.h>
#include <string.h>

int main()
{
    int a , i , l ,b , j ;
    char c[200];
    while(scanf("%d",&b)==1)
    {
        for(j=0 ; j<b ;)
        {
            gets(c);
            a = 0 ;
            l = strlen(c);
            if(l ==0) continue ;
            for(i=0 ; i<l ; i++)
            {
                if(c[i] == 'a' || c[i] == 'd' || c[i] == 'g' || c[i] == 'j' || c[i] == 'm' || c[i] == 'p' || c[i] == 't' || c[i] == 'w' || c[i] == ' ')
                {
                    a++;
                    continue ;
                }
                if(c[i] == 'b' || c[i] == 'e' || c[i] == 'h' || c[i] == 'k' || c[i] == 'n' || c[i] == 'q' || c[i] == 'u' || c[i] == 'x')
                {
                    a = a+ 2;
                    continue ;
                }
                if(c[i] == 'c' || c[i] == 'f' || c[i] == 'i' || c[i] == 'l' || c[i] == 'o' || c[i] == 'r' || c[i] == 'v' || c[i] == 'y')
                {
                    a += 3;
                    continue ;
                }
                if(c[i] == 's' || c[i] == 'z')
                {
                    a += 4 ;
                    continue;
                }
            }
            printf("Case #%d: %d\n",j+1 ,a);
            j++;
        }
    }
    return 0 ;
}

