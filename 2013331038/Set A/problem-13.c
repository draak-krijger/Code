#include <stdio.h>
#include <string.h>

int main()
{
    int len1,len2,i,j,k,t=0,a,l;
    char str[1000],word[100];
    gets(str);
    len1=strlen(str);
    scanf("%d",&a);
    int ck[a];
    for(i=0;i<a;i++){
        scanf("%s",word);
        len2=strlen(word);
        ck[i]=0;
        for(j=0;j<len1;j++){
            l=j;
            for(k=0;k<len2;k++){
                if(word[k] != str[l])
                    break;
                if(str[l]==word[len2-1])
                    ck[i]=1;
                l++;
            }
        }

    }
    for(i=0;i<a;i++){
        if(ck[i]==1)
            printf("Case %d : yes\n",i+1);
        else if(ck[i]==0)
            printf("Case %d : No\n",i+1);
    }
    return 0;
}

