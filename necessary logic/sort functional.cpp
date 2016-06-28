// sort using function
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <cstdio>

using namespace std ;

int main()
{
    int a , i , b[100] ;
    priority_queue<int>q ;
    while(scanf("%d",&a) != EOF)
    {
        for(i=0 ; i<a ; i++){
            scanf("%d",&b[i]);
            q.push(b[i]);
        }

        sort(b , b+a , greater <int>()) ;

        for(i=0 ; i<a ; i++){
            printf("%d ",q.top());
            q.pop();
        }

        printf("\n");
    }
    return 0 ;
}
