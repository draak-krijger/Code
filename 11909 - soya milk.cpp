#include <iostream>
#include <cstdio>
#include <cmath>
#define pi acos(-1)

using namespace std ;

int main()
{
    int l , w , h , deg , area ;
    double volume ;

    while(scanf("%d %d %d %d",&l,&w,&h,&deg) != EOF)
    {
        volume = l*tan(((double)deg * pi)/180) ;

        if(volume>h)
        {
            volume = .5*h*h*l*w/volume ;
        }

        else
        {
            volume = l*w*(h - (volume*.5));
        }

        printf("%.3lf mL\n",volume);
    }
    return 0 ;
}
