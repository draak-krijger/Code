#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std ;

int main()
{
    int i , l , a[30]  , b[30] , A[30] , B[30] , j ;
    char s[500];
    //freopen("input.txt","r",stdin);

    while(gets(s))
    {
        l = strlen(s);

        memset(a , 0 , sizeof(a));
        memset(b , 0 , sizeof(b));
        memset(A , 0 , sizeof(A));
        memset(B , 0 , sizeof(B));

        for(i=0 ; i<l ; i++)
        {
            if(isalpha(s[i]))
            {
                if(islower(s[i]))
                {
                    a[s[i] - 'a']++;
                    b[s[i] - 'a']++;
                }

                else if (isupper(s[i]))
                {
                    A[s[i] - 'A']++;
                    B[s[i] - 'A']++;
                }
            }
        }

        sort(a , a+30 , greater<int>());
        sort(A , A+30 , greater<int>());

        if(A[0] >= a[0])
        {
            l = A[0];
            for(i=0 ; i<26 ; i++)
            {
                for(j=0 ; j<26 ; j++)
                {
                    if(A[i] == B[j])
                    {
                        printf("%c",j+'A');
                        B[j] = 0 ;
                        break;
                    }
                }
                if(i < 25)
                {
                    if(A[i] != A[i+1])
                        break;
                }
            }
        }

        if(a[0] >= A[0])
        {
            l = a[0];
            for(i=0 ; i<26 ; i++)
            {
                for(j=0 ; j<26 ; j++)
                {
                    if(a[i] == b[j])
                    {
                        printf("%c",j+'a');
                        b[j] = 0 ;
                        break;
                    }
                }
                if(i < 25)
                {
                    if(a[i] != a[i+1])
                        break;
                }
            }
        }
        printf(" ");
        printf("%d\n",l);
    }
    return 0 ;
}
