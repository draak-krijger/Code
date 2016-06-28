#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , i , j = 0 , b , k , d ;
    char line[1000000] , c ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s",line);

        b=0;
        d = strlen(line);

        printf("Case %d: ",++j);

        for(i=0 ; i<d ; i++)
        {
            if(isalpha(line[i]))
                c = line[i];

            else if(isdigit(line[i]))
            {
                b = b*10 + line[i] - '0';

                if(isalpha(line[i+1]) || i == d-1 )
                {
                    for(k=0 ; k<b ; k++)
                        printf("%c",c);

                    b = 0 ;
                }
            }
        }

        printf("\n");
    }
    return 0 ;
}
