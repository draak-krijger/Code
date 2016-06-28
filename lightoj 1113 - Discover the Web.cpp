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

char current[100] ;
char bk[150][100] , frwd[150][100] ;
int b , f ;

void reset();
void bak();
void frward();
void visit();
void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        calculation(cas);

    return 0 ;
}

void reset()
{
    strcpy(current,"http://www.lightoj.com/") ;

    b = f = -1 ;
}

void bak()
{
    if(b<0)
        printf("Ignored\n");

    else
    {
        strcpy(frwd[++f],current);
        strcpy(current,bk[b]);
        printf("%s\n",current);
        b--;
    }
}

void frward()
{
    if(f<0)
        printf("Ignored\n");

    else
    {
        strcpy(bk[++b],current);
        strcpy(current,frwd[f]);
        printf("%s\n",current);
        f--;
    }
}

void visit()
{
    strcpy(bk[++b],current);
    scanf("%s",current);
    printf("%s\n",current);
    f = -1 ;
}

void calculation(int cas)
{
    reset();

    char cmd[50] ;
    printf("Case %d:\n",cas);

    while(scanf("%s",cmd) != EOF)
    {
        if(!strcmp(cmd,"QUIT"))
            break;

        else if(!strcmp(cmd,"BACK"))
            bak();

        else if(!strcmp(cmd,"FORWARD"))
            frward();

        else if(!strcmp(cmd,"VISIT"))
            visit();
    }
}
