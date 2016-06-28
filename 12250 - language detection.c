#include <stdio.h>
#include <string.h>

int main()
{
    int i=0 ;
    char s[20];
    while(scanf("%s",s) != EOF)
    {
        i++ ;

        if(strcmp(s,"#") == 0)
            break ;

        if(strcmp(s,"HELLO") == 0)
            printf("Case %d: ENGLISH\n",i);

         else if(strcmp(s,"HOLA") == 0)
            printf("Case %d: SPANISH\n",i);

         else if(strcmp(s,"HALLO") == 0)
            printf("Case %d: GERMAN\n",i);

         else if(strcmp(s,"BONJOUR") == 0)
            printf("Case %d: FRENCH\n",i);

        else if(strcmp(s,"CIAO") == 0)
            printf("Case %d: ITALIAN\n",i);

        else if(strcmp(s,"ZDRAVSTVUJTE") == 0)
            printf("Case %d: RUSSIAN\n",i);

        else
            printf("Case %d: UNKNOWN\n",i);
    }
    return 0 ;
}

