// Big digit multiple
#include<stdio.h>
#include<string.h>
#define MAX 300
int main()
{
    char a[MAX], b[MAX];
    int a1[MAX], b1[MAX];
    int c[2 * MAX] = {0};
    int lena, lenb, n, i, j;
    while(scanf("%s%s",a,b) == 2)
    {
        memset(c,0,sizeof(c));
        lena = strlen(a);
        for(i = lena - 1,j = 0; i >= 0; i--, j++)
        {
            a1[j] = a[i] - '0';
        }
        lenb = strlen(b);
        for(i = lenb - 1,j = 0; i >= 0; i--, j++)
        {
            b1[j] = b[i] - '0';
        }
        for(i = 0; i < lena; i++)
            for(j = 0, n = i; j < lenb; j++)
            {
                c[n] += b1[j] * a1[i];
                n++;
            }
        for(i = 0; i < n-1; i++)
        {
           if(c[i] > 9)
           {
               c[i+1] += c[i] / 10;
               c[i] %= 10;
           }
        }
        for(i = n - 1; i >= 0; i--)
            if(c[i] != 0)
            break;
       if(i == -1)
            printf("0\n");
       else
       {
           for(; i >= 0; i--)
               printf("%d",c[i]);
            printf("\n");
       }

    }
    return 0;
}
