#include <iostream>
#include <iomanip>
using namespace std;

const int n = 100;
void HornerD(char[], int, int);

int main()
{
int x;
char P[n];

cout<<"Enter a number: ";
cin>>P;
int n=strlen(P);
cout<<"Enter the base: ";
cin>>x;

HornerD(P, n, x);
return 0;
}

void HornerD(char *a, int n, int x)
{
int *p;

p=new int[n];
p[0]=a[0]-48;

for(int i=0; i<n; i++)
p[i+1]=p[i]*x + (a[i+1]-48);
cout << "Result in decimal is: "<<p[n-1]<<endl;
}
