#include<stdio.h>
#include<string.h>
int main()
{
    int a,i,len;
    char sen[100];
    scanf("%d",&a);
    int a_len[a];
    for(i=0;i<=a;i++){
        gets(sen);
        len=strlen(sen);
        a_len[i]=len;
    }
    printf("\n");
    for(i=1;i<=a;i++){
        printf("case %d : %d\n",i,a_len[i]);
    }
    return 0;
}
