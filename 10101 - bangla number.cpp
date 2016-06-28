#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    char num[1000] , check ;
    int d1 , s1 , h1 , l1 , k1 , d2 , s2 , h2 , l2 , k2 , leng , i , j=0 ;

    while(scanf("%s",num) != EOF)
    {
        check = '0';
        d1 = s1 = h1 = l1 = k1 = d2 = s2 = h2 = l2 = k2 = 0 ;

        i = strlen(num);
        i = i-1 ;

        if(i>=0)
        {
            d1 = num[i] - '0' ;

            if(i>0)
                d1 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i>0)
        {
            s1 = num[i-1] - '0';

            i = i-1 ;
        }

        if(i>0)
        {
            h1 = num[i-1] - '0' ;

            i = i-1 ;

            if(i>0)
                h1 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i>0)
        {
            l1 = num[i-1] - '0' ;

            i = i-1 ;

            if(i>0)
                l1 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i<=2)
        {
            if(i>0)
            {
                k1 = num[i-1] - '0' ;

                i = i-1 ;

                if(i>0)
                    k1 += (num[i-1] - '0')*10 ;

                i = i-1;
            }
        }

        if(i>0)
        {
            d2 = num[i-1] - '0' ;

            i=i-1 ;

            if(i>0)
                d2 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i>0)
        {
            s2 = num[i-1] - '0';

            i = i-1 ;
        }

        if(i>0)
        {
            h2 = num[i-1] - '0' ;

            i = i-1 ;

            if(i>0)
                h2 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i>0)
        {
            l2 = num[i-1] - '0' ;

            i = i-1 ;

            if(i>0)
                l2 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        if(i>0)
        {
            k2 = num[i-1] - '0' ;

            i = i-1 ;

            if(i>0)
                k2 += (num[i-1] - '0')*10 ;

            i = i-1;
        }

        printf("%4d.",++j);

        if(strcmp(num,"0") == 0)
        {
            printf(" 0\n");
            continue;
        }

        if(k2>0)
        {
            printf(" %d kuti",k2);
            check = '1' ;
        }

        if(l2>0)
        {
            printf(" %d lakh",l2);
            check = '1' ;
        }

        if(h2>0)
        {
            printf(" %d hajar",h2);
            check = '1' ;
        }

        if(s2>0)
        {
            printf(" %d shata",s2);
            check = '1' ;
        }

        if(d2>0)
        {
            printf(" %d",d2);
            check = '1' ;
        }

        if(check == '0')
        {
            if(k1>0)
            {
                printf(" %d kuti",k1);
            }
        }

        else if(check == '1')
            printf(" kuti");

        if(l1>0)
        {
            printf(" %d lakh",l1);
        }

        if(h1>0)
        {
            printf(" %d hajar",h1);
        }

        if(s1>0)
        {
            printf(" %d shata",s1);
        }

        if(d1>0)
        {
            printf(" %d",d1);
        }

        printf("\n");
    }
    return 0 ;
}
