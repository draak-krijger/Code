#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    double min , sec , hour , time1 , time2=0 , v1 , v2=0 , value=0 , l ;
    int i ;
    char s[50];

    while(gets(s))
    {
        hour = (s[0] - '0')*10 + s[1] - '0';
        min = (s[3] - '0')*10 + s[4] - '0' ;
        sec = (s[6] - '0')*10 + s[7] - '0' ;

        time1 = hour + (min/60) + (sec/3600) ;

        l = strlen(s);
        v1 = 0 ;

        if(l>8)
        {
            for(i=9 ; i<l ; i++)
            {
                v1 = v1*10 ;
                v1 += s[i] - '0';
            }

            value += (time1 - time2)*v2 ;
            time2 = time1 ;
            v2 = v1 ;
        }

        else
        {
            value += (time1 - time2)*v2;
            time2 = time1 ;

            printf("%s %.2lf km\n",s,value);
        }
    }
    return 0 ;
}
