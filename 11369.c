#include <stdio.h>

int main()
{
    int b, cas, j;
    scanf("%d", &b);
    for(cas = 0; cas < b; cas++)
    {
        int a, sum = 0;
        scanf("%d", &a);

        int dol[a];
        int max_dol[a];
        for(j = 0; j < a; j++)
        {
            scanf("%d", &dol[j]);
        }

        int max, i, index;
        for(j = 0; j < a; j++)
        {
            max = 0;
            for(i = 0; i < a; i++)
            {
                if(dol[i] > max)
                {
                    max = dol[i];
                    index = i;
                }
            }

            max_dol[j] = max;
            dol[index] = 0;
        }

        if(a % 3 != 0)
        {
            a = (a / 3) * 3;
        }
        for(j = 2; j < a; j = j + 3)
        {
            sum = sum + max_dol[j];
        }

        printf("%d\n", sum);
    }

    return 0;
}
