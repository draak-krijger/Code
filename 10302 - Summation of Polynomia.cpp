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

using namespace std;

int main()
{
    long long unsigned n ;

    while(scanf("%llu",&n) != EOF)
    {
        n = (n*(n+1))/2 ;
        n = n*n ;
        printf("%llu\n",n);
    }
    return 0 ;
}
