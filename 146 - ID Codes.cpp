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
    char s[100] ;

    while(gets(s))
    {
        if(strcmp(s,"#") == 0)
            return 0 ;

        int l = strlen(s);

        if(next_permutation(s,s+l))
            printf("%s\n",s);

        else
            printf("No Successor\n");
    }
    return 0 ;
}
