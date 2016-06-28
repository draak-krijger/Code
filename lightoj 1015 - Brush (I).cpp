#include <stdio.h>

int main()
{
    int a, b, c, d, i, j, k;
    scanf("%d", &a);

    for(i = 0; i < a; i++)
    {
        int ans = 0;
        scanf("%d", &b);

        for(j = 0; j < b; j++)
        {
            scanf("%d", &c);
            if(c > 0)
                ans += c;
        }

        printf("Case %d: %d\n", i + 1, ans);
    }

    return 0;
}
