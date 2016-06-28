#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0;
    char c[10] ;
    while(gets(c))
    {
        if(c[0] == '*')
            break;
        i++;
        if(strcmp(c,"Hajj") == 0)
            printf("Case %d: Hajj-e-Akbar\n",i);
        else if(strcmp(c,"Umrah") == 0)
            printf("Case %d: Hajj-e-Asghar\n",i);
    }
    return 0 ;
}

