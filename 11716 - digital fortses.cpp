#include<iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , length , i , j , sk ;
    char s[1000000];

    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        gets(s);

        length = strlen(s);
        sk = sqrt(length);

        if(sk*sk == length)
            {
                for(i=0 ;i < sk ; i++)
                {
                    for(j=i ; j<length ; j = j+sk)
                        printf("%c",s[j]);
                }

                printf("\n");
            }

        else
            printf("INVALID\n");

    }
    return 0 ;
}

