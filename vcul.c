#include<stdio.h>

#include<string.h>

#include<ctype.h>

int main()

{
    char str1[1000],i,lcase,ucase,vow,con;

    gets(str1);

    for(i=0;i<strlen(str1);i++){

        if(islower(str1[i])) lcase++;

        else if(isupper(str1[i])) ucase++;

        if (   str1[i]=='a' || str1[i]=='A'

            || str1[i]=='e' || str1[i]=='E'

            || str1[i]=='i' || str1[i]=='I'

            || str1[i]=='o' || str1[i]=='O'

            || str1[i]=='u' || str1[i]=='U')

                    vow++;

        else if(isalpha(str1[i])) con++;

    }

    printf("Uppercase::%d\n\nLowercase::%d\n\nVowel::%d\n\nConsnant::%d\n\n",ucase,lcase,vow,con);

    return 0;
}
