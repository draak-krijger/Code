#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int a ;
    char s[20];

    scanf("%d",&a);
    getchar();

    while(a--)
    {
        gets(s);

        if(strlen(s) == 5)
            printf("3\n");

        else
        {
            if((s[0] == 'o' && s[1] == 'n') ||
                (s[1] == 'n' && s[2] == 'e') ||
                (s[0] == 'o' && s[2] == 'e'))
                    printf("1\n");

            else
                printf("2\n");
        }
    }
    return 0;
}

