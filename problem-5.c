#include<stdio.h>
#include<string.h>
int main()
{
    int a,i;
    scanf("%d",&a);
    char name[a][100];
    for(i=0;i<a;i++){
        scanf("%s",name[i]);
    }
    for(i=0;i<a;i++){
        printf("Case %d: Hello %s\n",i+1,name[i]);
    }
    return 0;
}
