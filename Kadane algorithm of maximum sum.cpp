#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std ;

int matrix[105][105] , temp[110] ;
int finalleft , finalright , finaltop , finalbottom , n , start , finish ;

void find_maxsum();
int kadane(int temp[]);

int main()
{
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    find_maxsum();

    return 0 ;
}

int kadane(int temp[])
{
    int sum = 0 , maxsum = 0 ,local_start = 0 ;

    finish = -1 ;

    for(int i=0 ; i<n ; i++)
    {
        sum += temp[i];

        if(sum<0)
        {
            sum = 0 ;
            local_start = i+1 ;
        }

        else if(sum>maxsum)
        {
            maxsum = sum ;
            start = local_start ;
            finish = i ;
        }
    }

    if(finish != -1)
        return maxsum;

    start = finish = 0 ;
    sum = temp[0] ;

    for(int i=1 ; i<n ; i++)
    {
        if(temp[i]>sum)
        {
            sum = temp[i] ;
            start = finish = i ;
        }
    }

    return sum ;
}

void find_maxsum()
{
    int maxSum = 0 , left , right , sum ;

    for(left = 0 ; left < n ; left++)
    {

        memset(temp,0,sizeof temp);

        for(right = left ; right<n ; right++)
        {
            for(int i=0 ; i<n ; i++)
                temp[i] += matrix[i][right];

            sum = kadane(temp);

            if(sum>maxSum)
            {
                maxSum = sum ;

                finalleft = left ;
                finalright = right ;
                finaltop = start ;
                finalbottom = finish ;
            }
        }
    }
    printf("%d\n",maxSum);
    printf("(Top, Left) (%d, %d)\n", finaltop, finalleft);
    printf("(Bottom, Right) (%d, %d)\n", finalbottom, finalright);
}
