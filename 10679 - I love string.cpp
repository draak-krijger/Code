#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;
char s[1000000] , s1[10000] ;

int main()
{
    int tcase , len1 , len2 , q ;
    bool check ;
//    freopen("input.txt","r",stdin);
    while(scanf("%d",&tcase) != EOF)
    {
        scanf("%s",&s);

        len1 = strlen(s);

        scanf("%d",&q);

        while(q--)
        {
            scanf("%s",s1);
            len2 = strlen(s1);
            check = false;

            for(int i = 0 ; i<len1 ; i++)
            {
                if(s[i] == s1[0])
                {
                    for(int j = 1 ; j<len2 ; j++)
                    {
                        i++;
                        if(s[i] != s1[j])
                        {
                            i-- ;
                            break;
                        }

                        if(j == len2-1)
                        {
                            check = true ;
                            break;
                        }
                    }
                    if(check)
                        break;
                }
            }
            if(check)
                printf("y\n");

            else
                printf("n\n");
        }
    }
    return 0 ;
}
