#include<math.h>
#include <stdio.h>
int main()
{
    double a = 1, i, t = 0;
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
            else if(fmod(i , 5) == 0)
            {
                i = i / 5;
            }
            else if(fmod(i , 3) == 0)
            {
                i = i / 3;
            }
            else if(fmod(i , 2) == 0)
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

    printf("The 1500'th ugly number is <%lf>.", a);
    return 0;
}
