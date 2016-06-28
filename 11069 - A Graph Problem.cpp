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

int num[100] ;

int main()
{
    num[1] = 1 ;
    num[2] = 1 ;

    for(int i=3 ; i<=76 ; i++)
        num[i] = num[i-2] + num[i-3] ;

    int n ;

    while(scanf("%d",&n) != EOF)
    {
        printf("%d\n",num[n]+num[n-1]);
    }
    return 0 ;
}
