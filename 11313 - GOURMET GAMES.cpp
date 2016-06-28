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

void calculation(int n , int m);

int main()
{
    int n , m , tcase ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&n,&m);
        calculation(n,m);
    }
    return 0 ;
}

void calculation(int n , int m)
{
    int countshow = 0 , a , b ;

    a = n ;
    b = 1 ;
    while(b)
    {
        b = a/m ;
        countshow += b ;
        a = b + (a%m) ;

        if(a == 1)
            break;
    }

    if(b)
        printf("%d\n",countshow);

    else
        printf("cannot do this\n");
}
