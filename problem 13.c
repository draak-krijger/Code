#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    double vow,con,dig,a,len;
    vow=con=dig=0;
    int i;
    char ch='%';
    char str[100];
    scanf("%s",str);
    //* English has only 5 vowels.
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]=='A'|| str[i]=='a'||
           str[i]=='E'|| str[i]=='e'||
           str[i]=='I'|| str[i]=='i'||
           str[i]=='O'|| str[i]=='o'||
           str[i]=='U'|| str[i]=='u')
            vow++;
        else if(isalpha(str[i]))
            con++;
        else if(isdigit(str[i]))
            dig++;
    }
    a=vow+con+dig;
    double v,c,d;
    v=c=d=1;
    v=(vow/a)*100;
    c=(con/a)*100;
    d=(dig/a)*100;
    printf("Vowels: %.02lf %c\nConsonants: %.02lf %c\nDigits: %.02lf %c\n",v,ch,c,ch,d,ch);
    return 0;
}
