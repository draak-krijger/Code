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
    unsigned long long int s , d , days ;

    while(scanf("%llu %llu",&s,&d) == 2)
    {
        s = (s*(s-1))/2 ;
        s += d;

        days = ceil((sqrt(8*s + 1)-1)/2) ;
        printf("%llu\n",days);
    }
    return 0 ;
}
