#include <stdio.h>
#include <math.h>
#include<string.h>

int prime(int a)
{
    int b,i;
    b=1;
    for(i=2; i<=sqrt(a); i++)
    {
        if(a%i == 0)
        {
            b=0;
            break;
        }
    }
    return b;
}

int cap(int a)
{
    return 27+(a-'A');
}
int small(int a)
{
    return 1+(a-'a');
}

int main()
{
    int a,b,c,i,j,k;
    char word[30];
    while(scanf("%s",word)==1)
    {
        c=0;
        b=strlen(word);
        for(i=0; i<b; i++)
        {

            if('a'<= word[i] && word[i] <= 'z')
            {
                c =c + small(word[i]);
            }

            else if('A'<= word[i] && word[i] <= 'Z')
            {
                c = c + cap(word[i]);
            }
        }
        if(prime(c)==1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}

