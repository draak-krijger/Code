#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int a , b , i , j , lin[100] , first , last , mid ;
    bool check;

    while(scanf("%d",&a))
    {

        for(i=0 ; i<a ; i++)
            scanf("%d",&lin[i]);

        sort(lin , lin+a);

        while(scanf("%d",&b))
        {
            if(b==0)
                break;
            check = false;
            first = 0 ;
            last = a;

            while(first<=last)
            {
                mid = (first+last)/2 ;

                if(b>lin[mid])
                    first=mid+1;

                else if(b<lin[mid])
                    last = mid-1;

                else
                {
                    if(b==lin[mid])
                        check = true ;
                    break;
                }
            }

            if(check)
                printf("%d has %d position in line\n",b,mid);

            else
                printf("its not in array\n");
        }
    }
    return 0 ;
}

