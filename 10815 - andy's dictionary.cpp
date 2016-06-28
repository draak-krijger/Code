#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <list>

using namespace std ;

char st[5500][210] ;

int main()
{
    list<string>word;
    list<string>::iterator it ;

    char s[210] , s1[210] ;
    bool check ;
    int i , j , k , l = 0 ;

    while(cin >> s)
    {
        memset(s1 , 0 , sizeof(s1));

        for(i=0,j=0 ; i<strlen(s) ; i++)
        {
            if(isalpha(s[i]))
            {
                s1[j] = tolower(s[i]) ;
                st[l][j] = s1[j] ;
                j++ ;
            }
        }

        check = true ;

        for(k=0 ; k<l ;k++)
        {
            if(strcmp(st[k],st[l]) == 0)
            {
                check = false ;
                break;
            }
        }

        l++;

        if(check)
            word.push_back(s1);
    }

    word.sort();

    for(it = word.begin() ; it != word.end() ; ++it)
        cout << *it << endl ;

    return 0 ;
}
