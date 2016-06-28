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

int main()
{
    int n , a , b , c ;

    while(scanf("%d",&n) != EOF)
    {
        a = b = 1 ;

        while(a)
        {
            if(a<n)
            {
                a = a*10 + 1 ;
                b++;
            }
            a = a%n ;
        }

        printf("%d\n",b);
    }
    return 0 ;
}
