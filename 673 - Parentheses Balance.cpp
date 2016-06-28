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

int main()
{
    stack<char>mystack;
    int tcase;
    char str[200] , c ;

    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        gets(str);

        for(int i=0 ; i<strlen(str) ; i++)
        {
            if(!mystack.empty())
            {
                c = mystack.top();

                if((c == '(' && str[i] == ')') || (c == '[' && str[i] == ']'))
                    mystack.pop();

                else
                    mystack.push(str[i]);
            }

            else
                mystack.push(str[i]);
        }

        if(mystack.empty())
            printf("Yes\n");

        else
        {
            while(!mystack.empty())
                mystack.pop();

            printf("No\n");
        }
    }
    return 0 ;
}
