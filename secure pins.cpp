#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std ;

int main()
{
    int tcase , num[15] , j , b , c , d ;
    char s[50];
    bool check;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s",&s);
        memset(num , 0 , sizeof num);

        j = 0 ;

        check = true ;

        for(int i=0 ; i<6 ; i++)
        {
            b = s[i] - '0' ;
            c = s[i+1] - '0' ;
            num[b]++;
            if(num[b] == 3)
            {
                check = false ;
                break;
            }

            if(i==5)
                break;

            b = b-c;

            if(b==1 || b == -1)
            {
                if(i==0)
                {
                    j++;
                    d = b ;
                    continue;
                }

                if(d==b)
                    j++;

                else
                    j=1;

                if(j==2)
                {
                    check = false;
                    break;
                }

                d=b ;
            }

            else
                j = 0 ;
        }

        if(check)
            printf("ACCEPTABLE\n");

        else
            printf("WEAK\n");
    }
    return 0 ;
}
