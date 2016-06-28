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
#define MOD 1000000001

using namespace std ;

char number[100] ;
unsigned long long int a ;

bool isarmstrong(char s[]);

int main()
{
    int tcase ;
    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s",number);

        if(isarmstrong(number))
            printf("Armstrong\n");

        else
            printf("Not Armstrong\n");
    }
    return 0 ;
}

bool isarmstrong(char s[])
{
    int length ;

    length = strlen(s);
    unsigned long long int n = 0 , b ;
    a = 0 ;

    for(int i=0 ; i<length ; i++)
    {
        b = s[i] - '0' ;
        a = a*10 + b ;
        b = round(pow((double)b,(double)length));
        n += b%MOD;
        n = n%MOD;
    }

    if((a%MOD) == n)
        return true;

    else
        return false;
}
