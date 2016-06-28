#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    char a[1000000];
    int b , l , n , l4 , h , i , bl , t  , ln=0 ;

    while(gets(a))
    {
        b = strlen(a);
        l=n=l4=h=t = bl = 0 ;

        for(i=0 ; i<b ; i++)
        {
            l = l*10 + (a[i] - '0');
            l = l%4 ;

            n = n*10 + (a[i]-'0');
            n=n%100 ;

            l4 = l4*10 + (a[i]-'0');
            l4=l4%400 ;

            h = h*10 + (a[i] - '0');
            h = h%15 ;

            bl = bl*10 + (a[i]-'0');
            bl=bl%55 ;
        }

        if(ln != 0)
            cout << endl ;
        ln=1 ;

        if((l==0 && n != 0) || l4 == 0)
        {
            cout << "This is leap year." << endl ;
            t=1 ;
        }

        if(h==0)
            cout << "This is huluculu festival year." << endl ;

        if(bl==0 && t==1)
            cout << "This is bulukulu festival year." << endl;

        if(t==0 && h != 0)
            cout << "This is an ordinary year." << endl ;

    }

    return 0 ;
}

