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

int n , m ;

void inpandcal();

int main()
{
    while(scanf("%d %d",&n,&m) != EOF)
        inpandcal();

    return 0 ;
}

void inpandcal()
{
    bool check ;
    int cont  = 0 , a ;

    for(int i = 0 ; i<n ; i++)
    {
        check = true;

        for(int j=0 ; j<m ; j++)
        {
            scanf("%d",&a);

            if(!a)
                check = false;
        }

        if(check)
            cont++;
    }
    printf("%d\n",cont);
}
