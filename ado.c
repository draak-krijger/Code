#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()

{
    char str1[1000],i,alpha,digit,others;

    gets(str1);

    for(i=0;i<strlen(str1);i++){

        if(isalpha(str1[i])) alpha++;

        else if(isdigit(str1[i])) digit++;

        else others++;
    }

    printf("Alphabet::%d\n\nDigit::%d\n\nOther::%d\n\n",alpha,digit,others);

    return 0;
}

