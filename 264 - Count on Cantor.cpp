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

void calculation(int n);

int main()
{
    int a ;

    while(scanf("%d",&a) != EOF)
        calculation(a);

    return 0 ;
}

void calculation(int n)
{
    long long  a , upper , lower , b ;

    a = ceil((ceil(sqrt(1+8*n))-1)/2);
    b = (a*a+a)/2 ;

    upper = b - n + 1 ;
    lower = a - upper + 1 ;

    if(a&1)
        printf("TERM %d IS %lld/%lld\n",n,upper,lower);

    else
        printf("TERM %d IS %lld/%lld\n",n,lower,upper);
}
