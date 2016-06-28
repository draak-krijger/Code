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
    double length , wide , deep , weight ;
    int cont = 0 , tcase ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%lf %lf %lf %lf",&length,&wide,&deep,&weight);

        if(((length+wide+deep)<=125 || (length<=56 && wide<=45 && deep<=25)) && weight<=7)
        {
            printf("1\n");
            cont++;
        }

        else
            printf("0\n");
    }
    printf("%d\n",cont);
    return 0 ;
}
