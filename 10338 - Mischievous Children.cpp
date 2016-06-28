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

int main()
{
    char str[30] ;
    int l , tcase , countl , b ;
    unsigned long long int fact , fact2 ;
    int check[50] ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        memset(check,0,sizeof check);

        scanf("%s",str);
        l = strlen(str);

        fact = 1 ;

        for(int i=0 ; i<l ; i++)
        {
            b = str[i] - 'A' ;

            check[b]++;

            fact = fact*(i+1);
        }

        fact2 = 1 ;

        for(int i=0 ; i<26 ; i++)
        {
            if(check[i]>1)
            {
                for(int j=2 ; j<=check[i] ; j++)
                    fact2 *= j ;
            }
        }
        fact = fact/fact2 ;
        printf("Data set %d: %llu\n",cas,fact);
    }
    return 0 ;
}

