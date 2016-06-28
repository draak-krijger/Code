/*
ID: mohamma107
LANG: C++
TASK: transform
*/

#include <bits/stdc++.h>
#define PPP system("pause");

using namespace std ;

int n ;
bool check ;
char finalgraph[15][15] , graph2[15][15] , graph[15][15] ;

void  _reflection();
void  _90();
void  _180();
void  _270();
void original();

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);

    while(scanf("%d",&n) != EOF)
    {
        getchar();

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                scanf("%c",&graph[i][j]);
                graph2[i][j] = graph[i][j] ;
            }
            getchar();
        }

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                scanf("%c",&finalgraph[i][j]);
            }
            getchar();
        }

        check = true ;
        _90();

        if(!check)
        {
            check = true;
            _180();

            if(!check)
            {
                check = true;
                _270();

                if(!check)
                {
                    check = true;
                    _reflection();

                    if(!check)
                    {
                        check = true;
                        _90();

                        if(!check)
                        {
                            check = true;
                            _180();

                            if(!check)
                            {
                                check = true;
                                _270();

                                if(!check)
                                {
                                    check = true;
                                    original();

                                    if(!check)
                                    {
                                        printf("7\n");
                                    }

                                    else
                                        printf("6\n");
                                }

                                else
                                    printf("5\n");
                            }

                            else
                                printf("5\n");
                        }

                        else
                            printf("5\n");
                    }

                    else
                        printf("4\n");
                }

                else
                    printf("3\n");
            }

            else
                printf("2\n");
        }

        else
            printf("1\n");
    }
    return 0;
}

void  _90()
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=0 ; j--)
        {
            if(graph[j][i] != finalgraph[i][n-1-j])
            {
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }
}

void _180()
{
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=n-1 ; j>=0 ; j--)
        {
            if(graph[i][j] != finalgraph[n-1-i][n-1-j])
            {
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }
}

void _270()
{
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(graph[j][i] != finalgraph[n-1-i][j])
            {
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }
}

void  _reflection()
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=n-1 ; j>=0 ; j--)
        {
            graph[i][n-1-j] = graph2[i][j];

            if(graph2[i][j] != finalgraph[i][n-1-j])
                check = false;
        }
    }
}

void original()
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(graph2[i][j] != finalgraph[i][j])
            {
                check = false;
                break;
            }
        }

        if(!check)
            break;
    }
}
