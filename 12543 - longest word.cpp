#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int length ,lng , i=0 , lnf=0 , indx=0 , j ;
    char s[150] , sf[150];

    while(scanf("%s",s) != EOF)
    {
        if(strcmp(s,"E-N-D")==0)
            break;

        length = strlen(s) ;
        lng = 0 ;

        for(i=0 ; i<length ; i++)
        {
            if(isalpha(s[i]) || s[i] == '-')
            {
                lng++;

                if(i==length-1)
                {
                    if(lng > lnf)
                    {
                        lnf = lng;
                        indx = i+1 ;
                        for(j=0 ; j<lnf ; j++)
                        {
                            sf[j]=s[indx-lng];
                            lng-- ;
                        }
                    }
                }
            }

            else
            {
                if(lng > lnf)
                {
                    lnf = lng;
                    indx = i ;
                    for(j=0 ; j<lnf ; j++)
                    {
                        sf[j]=s[indx-lng];
                        lng-- ;
                    }
                }
                lng = 0 ;

            }
        }
    }

    for(i=0 ; i<lnf ; i++)
    {
        printf("%c",tolower(sf[i]));
    }
    printf("\n");
    return 0 ;
}
