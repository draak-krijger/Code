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

int gcd(int a , int b);

int main()
{
    int a , b ;

    while(scanf("%d %d",&a,&b) != EOF )
    {
        if(gcd(a,b) == 1)
            printf("%10d%10d    Good Choice\n\n",a,b);

        else
            printf("%10d%10d    Bad Choice\n\n",a,b);
    }
    return 0 ;
}

int gcd(int a , int b)
{
    if(b == 0)
        return a ;

    else
        return gcd(b,a%b);
}

