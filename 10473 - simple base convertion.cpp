#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;

int main()
{
    long long int a ;
    char s[1000];

    while(scanf("%s",&s))
    {
        if(s[0] == '-')
            return 0 ;

        if(isdigit(s[1]) || strlen(s) == 1)
        {
            sscanf(s,"%lld",&a);
            printf("0x%X\n",a);
        }
        else
        {
            a = strtol(s,NULL,16);
            printf("%lld\n",a);
        }
    }
    return 0 ;
}
