#include <stdio.h>
int main()

{
   int n;
   printf("enter a number");
   scanf("%d",&n);
   if(n%2!=0 || n==2)
     printf("it is a prime number");
   else
     printf("it is not a prime number");
     return 0;
 }
