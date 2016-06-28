#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, d, i, j, k, l;
    char nam[12][20], nam_test[20];
    int amn[12];

    char first = 1;

    while(scanf("%d", &a) == 1)
    {
        if(first == 0) putchar('\n');

        for(i = 0; i < a; i++)
        {
            amn[i] = 0;
            scanf(" %s", nam[i]);
        }

        for(i = 0; i < a; i++)
        {
            scanf(" %s", nam_test);
            j = 0;
            while(strcmp(nam[j], nam_test) != 0) j++;

            scanf("%d", &b);
            scanf("%d", &c);
            if(c == 0) continue;

            d = b / c;
            amn[j] = amn[j] - (d * c);

            for(k = 0; k < c; k++)
            {
                scanf(" %s", nam_test);
                l = 0;
                while(strcmp(nam[l], nam_test) != 0) l++;
                amn[l] = amn[l] + d;
            }
        }

        for(i = 0; i < a; i++)
        {
            printf("%s %d\n", nam[i], amn[i]);
        }

        first = 0;
    }

    return 0;
}

