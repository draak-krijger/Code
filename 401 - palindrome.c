#include<stdio.h>
#include<string.h>
int main()
{
    char ch,str[25],mr[25],list[91],inp[25];
    list['A'] = 'A';
    list['E'] = '3';
    list['H'] = 'H';
    list['I'] = 'I';
    list['J'] = 'L';
    list['L'] = 'J';
    list['M'] = 'M';
    list['O'] = 'O';
    list['S'] = '2';
    list['T'] = 'T';
    list['U'] = 'U';
    list['V'] = 'V';
    list['W'] = 'W';
    list['X'] = 'X';
    list['Y'] = 'Y';
    list['Z'] = '5';
    list['1'] = '1';
    list['2'] = 'S';
    list['3'] = 'E';
    list['5'] = 'Z';
    list['8'] = '8';
    int i,p,m,len;
    while(scanf("%s",&str)==1)
    {
        p = 0;
        m = 0;
        len = strlen(str);
        for(i=0 ; i<len ; i++)
        {
            inp[i]=str[len-i-1];
        }
        inp[i]='\0';
        if(strcmp(str,inp)==0)
            p = 1;
        for(i=0; i<strlen(str); i++)
        {
            ch = list[str[i]];
            if((ch >='A' && ch <='Z')||(ch >='1' && ch <='9'))
            {
                mr[i] = ch;
                m = 1;
            }
            else
            {
                m = 0;
                break;
            }
        }
        mr[i] = '\0';
        if(m)
        {
            len = strlen(mr);
            for(i=0  ; i<len ; i++)
            {
                inp[i]=mr[len-i-1] ;
            }
            inp[i]='\0';
            if(strcmp(str,inp)!=0)
                m = 0;
        }
        printf("%s -- ",str);
        if(p==0 && m==0)
            printf("is not a palindrome.");
        else if(p && m==0)
            printf("is a regular palindrome.");
        else if(p==0 && m)
            printf("is a mirrored string.");
        else if(p && m)
            printf("is a mirrored palindrome.");
        printf("\n\n");
    }
    return 0;
}
