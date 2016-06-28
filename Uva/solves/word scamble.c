#include <stdio.h>
#include <string.h>
int main()
{
    int a , i , j , k , l ;
    char st[1000];
    while(gets(st))
    {
        a = strlen(st);
        j = -1;
        for(i=0 ; i<a ; i++)
        {
            if(st[i]==' ')
            {
                for(k=i-1 ; k>j ; k--)
                    printf("%c",st[k]);
                printf(" ");
                j=i ;
            }
        }
        for(k=a-1 ; k>j ; k--)
            printf("%c",st[k]);
        printf("\n");
    }
    return 0;
}

