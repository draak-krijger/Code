#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a ;
    double c ;

    while(scanf("%d %lf",&a,&c) != EOF)
    {
        if(a%5 == 0 && a<=(c-.5))
        {
            c = c-a ;
            c -= .5 ;

            printf("%.2lf\n",c);
        }

        else
            printf("%.2lf\n",c);
    }
    return 0 ;
}

