#include <stdio.h>
#include <string.h>
int main()
{
    char ch[100], r_ch[100];
    int i, j, len,k,a;
    scanf("%d",&a);
    int l[a];
    for(i=0;i<a;i++){
        scanf("%s",ch);
        len = strlen(ch);
        for(j = 0, k = len - 1; j < len; j++, k--) {
            r_ch[j] = ch[k];
            }
        r_ch[j] = '\0';
        if (0 == strcmp(ch, r_ch)) {
            l[i]=1;
            }
        else {
        l[i]=0;
        }
    }
    for(i=0;i<a;i++){
        if(l[i]==1)
            printf("Case %d: Yes\n",i+1);
        else
            printf("Case %d: no\n",i+1);
    }
    return 0;
}
