#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int i=0,l,j;
    char c[10000] ;
    while(gets(c))
    {
        l =strlen(c);
        for(j=0; j<l; j++)
        {
            if(c[j] == '"')
            {
                i++;
                if(i%2 == 1)
                    printf("``");
                else
                    printf("''");
            }
            else
            printf("%c",c[j]);
        }
        printf("\n");
    }
    return 0;
}

