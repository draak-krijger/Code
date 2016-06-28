#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>

using namespace std ;

int fibonacci[1010][5000] , length[1010] ;

void calfibo();

int main()
{
    int n ;
    calfibo();

    while(scanf("%d",&n) != EOF)
    {
        for(int i=length[n] ; i>=0 ; i--)
            printf("%d",fibonacci[n][i]);

        printf("\n");
    }
    return 0 ;
}

void calfibo()
{
    int r = 0 , j ;
    fibonacci[0][0] = 1 ;
    fibonacci[1][0] = 2 ;
    length[0] = 0 ;
    length[1] = 0 ;

    for(int i=2 ; i<=1005 ; i++)
    {
        for(j=0 ; j<=length[i-1] ; j++)
        {
            if(j<=length[i-2])
            {
                r = (fibonacci[i-1][j] + fibonacci[i-2][j] + r);
                fibonacci[i][j] = r%10;
                r = r/10;
            }

            else
            {
                r = (fibonacci[i-1][j] + r);
                fibonacci[i][j] = r%10;
                r = r/10;
            }
        }

        if(r)
        {
            while(r)
            {
                fibonacci[i][j++] = r%10;
                r = r/10;
            }
        }

        length[i] = j-1;
    }
}
