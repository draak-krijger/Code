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
    int tcase ;
    unsigned long long p ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%llu",&p);
        printf("%llu\n",p>>1);
    }
    return 0 ;
}
