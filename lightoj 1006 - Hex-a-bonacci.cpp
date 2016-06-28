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
#define pi acos(-1)

using namespace std ;

unsigned long long int  n , num[11000] ;

void input(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input(cas);
    }
}

void input(int cas)
{
    scanf("%llu %llu %llu %llu %llu %llu %llu",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5],&n);

    for(int i=6 ; i<=n ; i++)
        num[i] = (num[i-1] + num[i-2] + num[i-3] + num[i-4] + num[i-5] + num[i-6])%10000007 ;

    printf("Case %d: %llu\n",cas,num[n]%10000007);
}
