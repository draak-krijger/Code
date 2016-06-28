#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;

char line[10000000] , c ;
int a[30] , b[30] ;
int main()
{
    int m , i , j , d ;

    scanf("%d",&m);
    getchar();

    for(i=0 ; i<m ; i++)
    {
        gets(line);
        //printf("clear\n")
        for(j=0 ; j<strlen(line) ; j++)
        {
            if(isalpha(line[j]))
            {
                c = toupper(line[j]);
                a[c-'A']++;
                b[c - 'A']++;
            }
        }
    }

    sort(a , a+26);

    for( i=25 ; i>0 ; i-- )
    {
        if(a[i]>0)
        {
            for(j=0 ; j<26 ; j++)
            {

                if(a[i] == b[j])
                {
                    d = j+'A' ;
                    printf("%c %d\n",d,a[i]);
                    b[j] = 0 ;
                    break ;
                }
            }
        }
    }
    return  0 ;
}
