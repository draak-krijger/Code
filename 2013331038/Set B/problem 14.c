#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000],rev_str[1000];
    int len,i,j,k=0;
    gets(str);
    len=strlen(str);
    for(i=0,j=len-1;j>-1;i++,j--){
            if(isalpha(str[j])|| isdigit(str[j])){
                rev_str[i]=str[j];
                k++;
            }
            else
                i--;
    }
    for(i=0;i<k;i++){
        printf("%c",rev_str[i]);
    }
    return 0;
}

