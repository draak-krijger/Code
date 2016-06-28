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

int result[500010] ;

int main()
{
    int a ;

    result[1] = 1 ;
    result[2] = 1 ;

    a = 2 ;

    for(int i=3 ; i<=500009 ; i++)
    {
        if(i<a)
            a = 2 ;

        result[i] = a ;
        a = a+2 ;
    }

    while(scanf("%d",&a) && a)
    {
        printf("%d\n",result[a]);
    }

    return 0 ;
}
