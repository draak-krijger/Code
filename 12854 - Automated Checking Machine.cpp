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
    int a[10] , b[10] ;
    bool check ;

    while(scanf("%d",&a[0]) == 1)
    {
        for(int i =1 ; i<5 ; i++)
            scanf("%d",&a[i]);

        check = true;

        for(int i=0 ; i<5 ; i++)
        {
            scanf("%d",&b[i]);

            if(a[i] == b[i])
                check = false ;
        }

        if(check)
            printf("Y\n");

        else
            printf("N\n");
    }
    return 0 ;
}
