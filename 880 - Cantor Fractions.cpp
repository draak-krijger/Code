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

void calculation(long long int n);

int main()
{
    long long int a ;

    while(scanf("%lld",&a) != EOF)
        calculation(a);

    return 0 ;
}

void calculation(long long int n)
{
    long long  a , upper , lower , b ;

    a = ceil((ceil(sqrt(1+8*n))-1)/2);
    b = (a*(a+1))/2 ;

    upper = b - n + 1 ;
    lower = a - upper + 1 ;
    printf("%lld/%lld\n",upper,lower);
}
