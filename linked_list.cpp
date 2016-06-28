/*
------------------------- ALLAH is Almighty -----------------------------
    author: Mohammad Nazim Uddin
    University: SUST
    OJ: contest-02
    problem name: divisable
*/

#include <bits/stdc++.h>

using namespace std ;

#define NAZIM
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000000
#define sz 65535+7
#define Mod 200000+20
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

struct node
{
    int data ;
    node *next ;
};

bool ck ;

void insert(node *head , int data)
{
    node *temp = new node ;

    temp->data = data ;
    temp->next = NULL ;

    if(ck)
    {
        head->data = data ;
        head->next = NULL ;
        ck = false;
        return;
    }

    node *cur = head ;

    while(cur)
    {
        if(cur->next == NULL)
        {
            cur->next = temp ;
            return;
        }
        cur = cur->next ;
    }
}

void insertatbegin(node **head,int data)
{
    node *temp = new node ;
    temp->data = data ;
    temp->next = *head ;
    *head = temp ;
}

void display(node *head)
{
    node *temp = head ;

    if(temp->next == NULL)
    {
        printf("EMPTY\n");
        return ;
    }

    printf("start\n");

    while(temp)
    {
        printf("%d\n",temp->data);
        temp = temp->next ;
    }
    printf("end\n");
}

void insertatloc(node *head,int loc,int data)
{
    node *cur = head , *temp = new node , *temp2 ;

    temp->data = data ;

    if(loc == 1)
    {
        temp->next = head;
        head = temp ;
    }

    int i = 1 ;

    while(cur)
    {
        i++;

        if(i == loc)
        {
            temp2 = cur->next ;
            temp->next = temp2 ;
            cur->next = temp ;
            return;
        }

        cur = cur->next ;
    }
}

void delbegin(node **head)
{
    node *temp = *head;
    *head = temp->next ;
    delete temp;
}

void dellast(node **head)
{
    node *cur = *head , *temp ;

    while(cur->next != NULL)
    {
        temp = cur ;
        cur = cur->next ;
    }

    delete cur ;
    temp->next = NULL;
    cur = temp ;
}

void delpos(node **head,int loc)
{
    node *curr = *head , *temp1 , *temp2 ;

    if(loc == 1)
    {
        *head = curr->next ;
        delete curr;
        return ;
    }

    int i=1 ;

    while(curr)
    {
        i++;
        if(i == loc)
        {
            temp1 = curr->next ;
            curr->next = temp1->next ;
            delete temp1 ;
            return;
        }
        curr = curr->next ;
    }
}

void deletelist(node **head)
{
    node *temp = *head , *tmp ;

    while(temp)
    {
        tmp = temp->next ;
        free(temp);
        temp = tmp ;
    }
}

int main()
{
    node *head = new node ;
    head->next = NULL ;
    ck = 1 ;

    display(head);
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);
    insertatbegin(&head,6);
    display(head);
    insert(head,7);
    display(head);
    insertatloc(head,3,32);
    display(head);
    delbegin(&head);
    display(head);
    dellast(&head);
    display(head);
    delpos(&head,2);
    display(head);
    cout<<"ok"<<endl;
    dellast(&head);
    display(head);

    return 0;
}
