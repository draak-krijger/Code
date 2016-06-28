#include <bits/stdc++.h>

using namespace std ;

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 600000+10

char str[Max] ;
int leng ;

struct node{
    bool endmark ;
    node *next[3] ;

    node()
    {
        endmark = false;

        for(int i=0 ; i<3 ; i++)
            next[i] = NULL ;
    }
}*root;

void initial();
bool query(int i ,node *p , bool ok);
void  del(node *curr);

int main()
{
    int n , m ;

    while(sf2(n,m) != EOF)
    {
        root = new node();

        forln(i,0,n)
        {
            scanf("%s",str);

            leng = strlen(str);
            initial();
        }

        forln(i,0,m)
        {
            scanf("%s",str);

            leng = strlen(str);

            if(query(0,root,false))
                printf("YES\n");

            else
                printf("NO\n");
        }
        del(root);
    }
    return 0;
}

void initial()
{
    int id ;

    node *curr = root ;

    for(int i=0 ; i<leng ; i++)
    {
        id = str[i] - 'a' ;

        if(curr->next[id] == NULL)
            curr->next[id] = new node();

        curr = curr->next[id] ;
    }

    curr->endmark = true;
}

bool query(int i , node *p , bool ok)
{
    int id ;
    node *curr = p , *temp ;

    for(;i<leng ; i++)
    {
        id = str[i] - 'a' ;

        if(!ok)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(j == id)
                    continue;
                temp = curr->next[j] ;
                if(curr->next[j] != NULL && query(i+1,temp,true))
                    return true;

                //curr = curr->next[j] ;
            }
        }

        if(curr->next[id] == NULL)
            return false;

        curr = curr->next[id];
    }

    return (ok && curr->endmark);
}

void  del(node *curr)
{
    for(int i=0 ; i<3 ; i++)
        if(curr->next[i])
            del(curr->next[i]);

    delete(curr);
}
