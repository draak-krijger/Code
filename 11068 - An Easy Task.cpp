#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int a1 , b1 , c1 , a2 , b2 , c2 ;
    double x , y , z ;

    while(scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2) != EOF)
    {
        if(a1==0 && b1==0 && c1 == 0 && a2 == 0 && b2 == 0 && c2 == 0)
            return 0 ;

        z = a1*b2 - a2*b1;

        if(z == 0){
            printf("No fixed point exists.\n");
        continue;
        }

        x = (b2*c1 - b1*c2)/z ;
        y = (a1*c2 - a2*c1)/z ;

        if(x==-0.0)
            x = 0 ;
        if(y == -0.0)
            y = 0;

        printf("The fixed point is at %.2lf %.2lf.\n",x,y);
    }

    return 0 ;
}
