#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std ;

int main()
{
    int i , l , a[30]  , b[30] , tcase , j ;
    char s;
    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        memset(a , 0 , sizeof(a));
        memset(b , 0 , sizeof(b));

        while(scanf("%c",&s))
        {
            if(s == '\n')
                break;

            if(isalpha(s))
            {
                a[tolower(s) - 'a']++;
                b[tolower(s) - 'a']++;
            }
        }

        sort(a , a+30 , greater<int>());

        for(i=0 ; i<26 ; i++)
        {
            for(j=0 ; j<26 ; j++)
            {
                if(a[i] == b[j])
                {
                    printf("%c",j+'a');
                    b[j] = 0 ;
                    break;
                }
            }
            if(i < 25)
            {
                if(a[i] != a[i+1])
                    break;
            }
        }
        printf("\n");
    }
    return 0 ;
}
