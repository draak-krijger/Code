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

map<string,int>maping ;

long long int fyr , ltyr , num4 , num100 , num400 ;
int fd , ld ;
char fm[100] , lm[100] ;

void setmnth();
void inpcal(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);
    setmnth();

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }

    return 0 ;
}

void setmnth()
{
    maping["January"] = 1 ;
    maping["February"] = 2 ;
    maping["March"] = 3 ;
    maping["April"] = 4 ;
    maping["May"] = 5 ;
    maping["June"] = 6 ;
    maping["July"] = 7 ;
    maping["August"] = 8 ;
    maping["September"] = 9 ;
    maping["October"] = 10 ;
    maping["November"] = 11 ;
    maping["December"] = 12 ;
}

void inpcal(int cas)
{
    char c ;
    int a = 0 ;

    scanf("%s %d%c %lld",fm,&fd,&c,&fyr);
    scanf("%s %d%c %lld",lm,&ld,&c,&ltyr);

    num4 = (ltyr/4) - (fyr/4);
    num400 = (ltyr/400) - (fyr/400);
    num100 = (ltyr/100) - (fyr/100);

    num4 -= (num100 - num400);

    if(maping[fm]<=2)
    {
        if(!(fyr%4))
        {
            if(!(fyr%100))
            {
                if(!(fyr%400))
                    num4++;
            }

            else
                num4++;
        }
    }

    if(maping[lm]<=2)
    {
        if(ld != 29 || maping[lm] != 2)
        {
            if(!(ltyr%4))
            {
                if(!(ltyr%100))
                {
                    if(!(ltyr%400))
                        num4--;
                }

                else
                    num4--;
            }
        }
    }

    printf("Case %d: %lld\n",cas,num4);
}
