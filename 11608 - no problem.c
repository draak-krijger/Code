#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int a , problem[50] , problem_r[50] , i , j , b , s ;
    j=0 ;

    while(cin >> s)
    {
        if(s<0)
            return 0 ;

        j++ ;

        for(i=0 ; i<12 ; i++)
            cin >> problem[i] ;

        for(i=0 ; i<12 ; i++)
            cin >> problem_r[i] ;

        b = s ;

        cout << "Case " << j << ":" << endl ;

        for(i=0 ; i<12 ; i++)
        {
            if(i>0)
                b += problem[i-1] ;
            if(b >= problem_r[i])
            {
                b = b-problem_r[i] ;
                cout << "No problem! :D" << endl ;
            }

            else
                cout << "No problem. :(" << endl ;

        }
    }
    return 0 ;
}

