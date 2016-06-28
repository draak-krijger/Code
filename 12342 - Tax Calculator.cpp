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
    int tcase ;
    long long a , fsum ;
    double sum ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lld",&a);

        sum = 0 ;

        if(a>(180000+300000+400000+300000))
            sum = 30000 + 2*60000 + ((double)(a-(180000+300000+400000+300000))*25.0)/100.0 ;

        else if(a>(180000+300000+400000))
            sum = 30000 + 60000 + ((double)(a-(180000+300000+400000))*20.0)/100.0 ;

        else if(a>(180000+300000))
            sum = 30000 + ((double)(a-(180000+300000))*15.0)/100.0 ;

        else if(a>(180000)){
            sum = ((double)(a-(180000))*10.0)/100.0 ;}

        if(sum<2000 && sum>0)
            sum = 2000 ;

        fsum = ceil(sum);
        printf("Case %d: %lld\n",cas,fsum);
    }
    return 0 ;
}
