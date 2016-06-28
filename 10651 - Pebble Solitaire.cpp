#include <bits/stdc++.h>

using namespace std ;

int n ;

int Reset(int num , int pos);
bool check(int num , int pos);
int Set(int num , int pos);
int call(int board);
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        printf("%d\n",call(n));
    }
    return 0;
}

int Reset(int num , int pos)
{
    num = num & ~(1<<pos);
    return num ;
}

bool check(int num , int pos)
{
    return num & (1<<pos);
}

int Set(int num , int pos)
{
    num = num | (1<<pos);
    return num ;
}

int call(int board)
{
    int u , v , cont = 0 , fc = 1000 , c1 = 1000 , c2 = 1000;
    bool ck = false;

    for(int i=0 ; i<12 ; i++)
    {
        if(!check(board,i))
        {
            u = i-2 ;
            v = i+2 ;
            ck = true;

            if(u>=0)
            {
                int board1 = board;
                if(check(board1,u) && check(board1,i-1))
                {
                    board1 = Reset(board1,u);
                    board1 = Reset(board1,i-1);
                    board1 = Set(board1,i);
                    c1 = call(board1);
                    ck = false;
                }
            }

            if(v<12)
            {
                int board1 = board;
                if(check(board1,v) && check(board1,v-1))
                {
                    board1 = Reset(board1,v);
                    board1 = Reset(board1,v-1);
                    board1 = Set(board1,i);
                    c2 = call(board1);
                }
            }

            fc = min(fc,min(c1,c2));
        }

        else cont++;
    }

    return fc = min(fc,cont);
}

void input()
{
    char cha ;
    getchar();
    n = 0;

    for(int i=0 ; i<12 ; i++)
    {
        scanf("%c",&cha);

        if(cha == 'o')
            n = Set(n,i);

        else if(cha == '-')
            n = Reset(n,i);
    }
}
