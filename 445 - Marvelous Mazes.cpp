#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;
char str;

int main()
{
    int i , j , k =0, length ;
    bool check = false ;
    freopen("input.txt","r",stdin);

        while(scanf("%c",&str) != EOF)
        {
            if(isdigit(str))
            {
                k += str - '0' ;
            }

            else if(isalpha(str))
            {
                if(str == 'b')
                    for(j=0 ; j<k ; j++)
                        printf(" ");
                else
                    for(j=0 ; j<k ; j++)
                        printf("%c",str);

                k=0;
            }

            else if(str == '!')
                printf("\n");

            else if(str == '*')
            {
                for(j=0 ; j<k ; j++)
                    printf("%c",str);

                k = 0 ;
            }

            else
                printf("%c",str);
        }

    return 0 ;
}
