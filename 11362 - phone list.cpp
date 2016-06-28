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

struct node
{
    bool endmark;
    node *next[11] ;

    node()
    {
        endmark = false;

        for(int i=0 ; i<10 ; i++)
            next[i] = NULL;
    }
};

node *root ;
bool mark , lastmark ;

void del(node *curr);
void set_try(char str[] , int length);

int main()
{
    int tcase , n ;
    char str[20];

    scanf("%d",&tcase);

    while(tcase--)
    {
        root = new node();
        scanf("%d",&n);
        lastmark = false;
        mark = false;

        for(int i=0 ; i<n ; i++)
        {
            scanf("%s",str);

            if(!lastmark && !mark)
            {
                lastmark = true ;
                set_try(str,strlen(str));
            }

        }

        if(lastmark || mark)
            printf("NO\n");

        else
            printf("YES\n");

        del(root);
    }
    return 0 ;
}

void set_try(char str[] , int length)
{
    node *curr = root;
    int a ;

    for(int i = 0 ; i<length ; i++)
    {
        a = str[i] - '0' ;

        if(curr->next[a] == NULL)
        {
            lastmark = false;
            curr->next[a] = new node() ;
        }

        curr = curr->next[a];

        if(curr->endmark)
            mark = true;
    }

    curr->endmark = true;
}

void del(node *curr)
{
    for(int i=0 ; i<10 ; i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }
    delete(curr);
}
