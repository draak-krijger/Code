#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len;
    char cl[80];
    scanf("%s",cl);
    len=strlen(cl);
    char rev_cl[80];
    for(i=0,j=len-1;i<len;i++,j--){
        rev_cl[i]=cl[j];
    }
    rev_cl[i]='\0';
    printf("%s\n",rev_cl);

        if(cl==rev_cl)
            printf("Its a palindrome!!!! ");
        else
            printf("Its not a palindrome!!! ");

        return 0;
}
