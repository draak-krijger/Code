#include <stdio.h>
int main()

{
   double num;
   printf("enter your number:");
   scanf("%lf",&num);
   if(num<=1||num>=10)
   {
       printf("yes\n");
   }
   else
    {
    printf("no\n");
   }
   return 0;
}
