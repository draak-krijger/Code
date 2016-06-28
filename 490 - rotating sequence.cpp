#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int length = 0 , i = 0 ,lenck ;
    char sentence[150][150] ;
//freopen("input.txt", "r" , stdin);
    for(int j =0 ; j<110 ; j++)
    {
        for(int i=0 ; i<110 ; i++)
            sentence[j][i] = ' ';
    }

    while(gets(sentence[i]))
    {
        lenck = strlen(sentence[i]);
        sentence[i][lenck] = ' ';

        if(lenck>length)
            length =  lenck;

        i++;
    }

    for(int j =0 ; j<length ; j++)
    {
        for(int k = i-1 ; k>=0 ; k--)
        {
            printf("%c",sentence[k][j]);
        }

        printf("\n");
    }
    return 0 ;
}
