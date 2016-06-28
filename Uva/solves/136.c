#include <stdio.h>

int main()
{
    int a = 1, i, t = 0;
    //freopen("a.txt","w",stdout);
    while(1)
    {
        i = a;
        while(1)
        {
            if(i == 1)
            {
                t++;
                break;
            }
            else if(i % 5 == 0)
            {
                i = i / 5;
            }
            else if(i % 3 == 0)
            {
                i = i / 3;
            }
            else if(i % 2 == 0)
            {
                i = i / 2;
            }
            else
                break;
        }

        if(t == 1500)
            break;

        a++;
    }
    printf("The 1500'th ugly number is <%d>.", a);
    return 0;
}
