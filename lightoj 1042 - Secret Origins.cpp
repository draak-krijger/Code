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

unsigned long long int n , p ;
int bin[500] , len , cont ;

void inpcal(int cas);
void inttobin(unsigned long long int a);
void bintodec();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcal(cas);

    return 0 ;
}

void inttobin(unsigned long long int a)
{
    int  revbin[500] ;
    len = 0 ;
    cont = 0 ;

    while(a)
    {
        revbin[len++] = a%2 ;
        a = a/2 ;
    }

    a = 0 ;

    for(int i=len-1 ; i>=0 ; i--)
    {
        bin[a++] = revbin[i] ;

        if(revbin[i])
            cont++;
    }
}

void bintodec()
{
    p = 0 ;
    int a = 0 ;

    for(int i=len-1 ; i>=0 ; i--)
    {
        p += (bin[i] * pow((double)2,(double)a));
        a++;
    }

}

void inpcal(int cas)
{
    scanf("%llu",&n);

    if(n&(n-1))
    {
        inttobin(n);

        if(next_permutation(bin,bin+len))
        {
            bintodec();
            printf("Case %d: %llu\n",cas,p);
        }

        else
        {
            cont -= 1 ;
            p = 0 ;

            for(int i=0 ; i<cont ; i++)
                p +=  pow((double)2,(double)i);

            p +=  pow((double)2,(double)len);

            printf("Case %d: %llu\n",cas,p);
        }
    }

    else
        printf("Case %d: %llu\n",cas,2*n);
}
