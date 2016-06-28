#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std ;

set<char>solve ;
char s1[1000] ;
set<char>::iterator it ;

bool check ;

int main()
{
    int a , cont ;
    char c ;
    while(scanf("%d",&a) == 1)
    {
        getchar();

        if(a==-1)
            return 0 ;

        scanf("%s",s1);
        solve.clear();

        for(int i=0 ; i<strlen(s1) ; i++)
        {
            solve.insert(s1[i]);
        }

        scanf("%s",s1);
        cont = 0 ;

        for(int i=0 ; i<strlen(s1) ; i++)
        {
            check = false ;

            for(it = solve.begin() ; it!=solve.end() ; it++)
            {
                if(s1[i] == *it)
                {
                    check = true ;
                    break;
                }
            }

            if(check)
                solve.erase(s1[i]);

            else
                cont++;

            if(cont == 7)
                break;

            if(solve.empty())
                break;
        }

        if(solve.empty())
            printf("Round %d\nYou win.\n",a);

        else if(cont == 7)
            printf("Round %d\nYou lose.\n",a);

        else
            printf("Round %d\nYou chickened out.\n",a);
    }
    return 0 ;
}

