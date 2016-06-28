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

map<int , char>maping;

void set_map();

int main()
{
    char s[100] ;
    int length , tcase , a ;

    set_map();
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        while(gets(s))
        {
            length = strlen(s);

            if(!length)
                break;

            for(int i=0 ; i<length ; i++)
            {
                if(isdigit(s[i]))
                {
                    a = s[i] - '0';
                    printf("%c",maping[a]);
                    continue;
                }
                printf("%c",s[i]);
            }
            printf("\n");
        }

        if(tcase)
            printf("\n");
    }
    return 0 ;
}

void set_map()
{
    maping[0] = 'O';
    maping[1] = 'I';
    maping[2] = 'Z';
    maping[3] = 'E';
    maping[4] = 'A';
    maping[5] = 'S';
    maping[6] = 'G';
    maping[7] = 'T';
    maping[8] = 'B';
    maping[9] = 'P';
}
