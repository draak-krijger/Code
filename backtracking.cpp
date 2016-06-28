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
#define jora pair<int,int>
#define pb push_back

using namespace std ;

char arr[100];
vector<char>result ;
int taken[10] , length_uwant , length_str ;

void reset();
void backtracking();

int main()
{
    while(scanf("%s",arr))
    {
        length_str = strlen(arr);
        result.clear();
        scanf("%d",&length_uwant);
        backtracking();
    }
    return 0;
}

void reset()
{
    result.clear();
    for(int i=0 ; i<=length_str ; i++)
        taken[i] = 0;
}

void backtracking()
{
    if(result.size() == length_uwant)
    {
        for(int i=0 ; i<4 ; i++)
            printf("%c ",result[i]);
        printf("\n");
        return;
    }

    for(int i=0 ; i<length_str ; i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1 ;
            result.push_back(arr[i]);
            backtracking();
            taken[i] = 0 ;
            result.pop_back();
        }
    }
}
