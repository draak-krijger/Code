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

void one(int n);
void two(int n);
void three(int n);
void four(int n);
void five(int n);
void six(int n);
void seven(int n);
void eight(int n);
void nine(int n);
void zero(int n);
void calculation(int n , int s);

int main()
{
    int n , s ;

    while(1)
    {
        printf("Enter Size : ");
        scanf("%d",&n);

        printf("\nDigit : ");
        scanf("%d",&s);

            calculation(n,s);
    }
    return 0 ;
}

void calculation(int n , int s)
{
        if(s == 0)
            zero(n);

        else if(s == 1)
            one(n);

        else if(s == 2)
            two(n);

        else if(s == 3)
            three(n);

        else if(s == 4)
            four(n);

        else if(s == 5)
            five(n);

        else if (s == 6)
            six(n);

        else if(s == 7)
            seven(n);

        else if(s == 8)
            eight(n);

        else if(s == 9)
            nine(n);

//        if(i != l)
//        {
//            for(int j=0 ; j<2*n+3 ; j++)
//                printf("\n");
//        }

}

void one(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == n+1 || i==0 || i == (2*n+2))
        {
            for(int j=0 ; j<(n+2) ; j++)
                printf(" ");

            printf("\n");
            continue;
        }

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("|\n");
    }
}

void two(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i>n+1)
            printf("|");

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        if(i<n+1)
            printf("|\n");

        else
            printf("\n");
    }
}

void three(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("|\n");
    }
}

void four(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == (2*n+2))
        {
            for(int j=0 ; j<n+2 ; j++)
                printf(" ");

            printf("\n");
            continue;
        }

        if(i == n+1)
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i<n+1)
        {
            printf("|");

            for(int j=0 ; j<n ; j++)
                printf(" ");

            printf("|\n");

            continue;
        }

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("|\n");
    }
}

void five(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i<n+1)
            printf("|");

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        if(i>n+1)
            printf("|\n");

        else
            printf("\n");
    }
}

void six(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i>n+1)
        {
            printf("|");

            for(int j=0 ; j<n ; j++)
                printf(" ");

            printf("|\n");

            continue;
        }

        printf("|");
        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("\n");
    }
}

void seven(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == n+1 || i == (2*n+2))
        {
            for(int j=0 ; j<(n+2) ; j++)
                printf(" ");

            printf("\n");
            continue;
        }

        if(i==0)
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("|\n");
    }
}

void eight(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        printf("|");

        for(int j=0 ; j<n ; j++)
            printf(" ");

        printf("|\n");
    }
}

void nine(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == n+1 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i<n+1)
        {
            printf("|");

            for(int j=0 ; j<n ; j++)
                printf(" ");

            printf("|\n");

            continue;
        }

        for(int j=0 ; j<n+1 ; j++)
            printf(" ");

        printf("|\n");
    }
}

void zero(int n)
{
    for(int i=0 ; i<2*n+3 ; i++)
    {
        if(i == 0 || i == (2*n+2))
        {
            printf(" ");

            for(int j=0 ; j<n ; j++)
                printf("-");

            printf(" \n");

            continue;
        }

        if(i == n+1)
        {
            for(int j=0 ; j<n+2 ; j++)
                printf(" ");

            printf("\n");

            continue;
        }

        printf("|");

        for(int j=0 ; j<n ; j++)
            printf(" ");

        printf("|\n");
    }
}
