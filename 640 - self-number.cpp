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
#define MAX 1000000

using namespace std ;

bool num[MAX];
void calculation();
void output();

int main()
{
    calculation();
    output();
    return 0 ;
}

void calculation()
{
    int sum , n , i ;

    i = 1 ;

    while(i<=MAX)
    {
        sum = n = i ;

        while(n)
        {
            sum += n%10;
            n /= 10 ;
        }

        if(sum<=MAX)
            num[sum] = true;
        i++;
    }
}

void output()
{
    for(int i=1 ; i<=MAX ; i++)
    {
        if(!num[i])
            printf("%d\n",i);
    }
}
