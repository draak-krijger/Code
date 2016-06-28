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

char s1[500] , s2[500] ;
int result[500] , i ;

void calculation();
void publishresult();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s %s",s1,s2);
        calculation();
        publishresult();
    }
    return 0 ;
}

void calculation()
{
    int length1 , length2 , a , b , r ;

    length1 = strlen(s1) - 1 ;
    length2 = strlen(s2) - 1 ;
    r = 0 ;

    if(length1>length2)
    {
        for(i=0 ; i<=length1 ; i++)
        {
            a = s1[i] - '0' ;

            if(i<=length2)
                b = s2[i] - '0' ;

            r = a+b+r ;

            result[i] = r%10;
            r = r/10;
            b = 0 ;
        }

        if(r)
        {
            while(r)
            {
                result[i++] = r%10 ;
                r /= 10 ;
            }
        }
    }

    else
    {
        for(i=0 ; i<=length2 ; i++)
        {
            a = s2[i] - '0' ;

            if(i<=length1)
                b = s1[i] - '0' ;

            r = a+b+r ;

            result[i] = r%10;
            r = r/10;
            b = 0 ;
        }

        if(r)
        {
            while(r)
            {
                result[i++] = r%10 ;
                r /= 10 ;
            }
        }
    }
}

void publishresult()
{
    bool check = true;

    for(int j = i-1 ; j>=0 ; j--)
    {
        if(!result[j])
            i--;

        else
            break;
    }

    for(int j=0 ; j<i ; j++)
    {
        if(!result[j] && check)
            continue;

        check = false;
        printf("%d",result[j]);
    }
    printf("\n");
}
