#include <iostream>
#include <cstdio>

using namespace std;

int sum[5100][2000] ;
int length[5100];

int main()
{
    int a , i , j , e , c , b ;
    sum[0][0] = 0 ; sum[1][0]=1 ;
    length[0]=length[1]=b=0;

    for(j=2 ; j<=5000 ; j++)
    {
        c=0;
        i =0;

        while(1)
        {
            e = sum[j-1][i] + sum[j-2][i] + c;

            if(e>=10)
            {
                sum[j][i] = e%10 ;
            }

            else
                sum[j][i] = e ;

            c=e/10 ;

            if(i == b)
            {
                if(c != 0)
                {
                    i++;
                    sum[j][i] = c ;
                }

                break ;
            }

            i++;
        }
        b=i ;
        length[j] = i ;
    }

    while(cin >> a)
    {
        printf("The Fibonacci number for %d is ",a);
        for(i=length[a] ; i>=0 ; i--)
            cout << sum[a][i];
        cout << endl ;
    }
    return 0 ;
}
l
