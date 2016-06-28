#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    char c ;

    while(scanf("%c",&c) != EOF)
    {
        if (c=='2')
            printf("`");

        else if (c=='3')
            printf("1");

        else if (c=='4')
            printf("2");

        else if (c=='5')
            printf("3");

        else if (c=='6')
            printf("4");

        else if (c=='7')
            printf("5");

        else if (c=='8')
            printf("6");

        else if (c=='9')
            printf("7");

        else if (c=='0')
            printf("8");

        else if (c=='-')
            printf("9");

        else if (c=='=')
            printf("0");

        else if (tolower(c)=='e')
            printf("q");

        else if (tolower(c)=='r')
            printf("w");

        else if (tolower(c)=='t')
            printf("e");

        else if (tolower(c)=='y')
            printf("r");

        else if (tolower(c)=='u')
            printf("t");

        else if (tolower(c)=='i')
            printf("y");

        else if (tolower(c)=='o')
            printf("u");

        else if (tolower(c)=='p')
            printf("i");

        else if (c=='[')
            printf("o");

        else if (c==']')
            printf("p");

        else if (c=='\\')
            printf("[");

        else if (tolower(c)=='d')
            printf("a");

        else if (tolower(c)=='f')
            printf("s");

        else if (tolower(c)=='g')
            printf("d");

        else if (tolower(c)=='h')
            printf("f");

        else if (tolower(c)=='j')
            printf("g");

        else if (tolower(c)=='k')
            printf("h");

        else if (tolower(c)=='l')
            printf("j");

        else if (c==';')
            printf("k");

        else if (c=='\'')
            printf("l");

        else if (tolower(c)=='c')
            printf("z");


        else if (tolower(c)=='v')
            printf("x");

        else if (tolower(c)=='b')
            printf("c");

        else if (tolower(c)=='n')
            printf("v");

        else if (tolower(c)=='m')
            printf("b");

        else if (c==',')
            printf("n");

        else if (c=='.')
            printf("m");

        else
            putchar(c);
    }

    return 0 ;
}

