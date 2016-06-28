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
    unsigned long long int a ;

    while(scanf("%llu",&a) == 1)
    {
        if(a == 0)
            return 0 ;

        if(a & (a+1))
            printf("Alice\n");

        else
            printf("Bob\n");
    }
    return 0 ;
}
