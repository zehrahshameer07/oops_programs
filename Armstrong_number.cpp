/*Program to find if it is an armstrong number*/
#include<stdio.h>
int main()
{
	int n,digit,sum;
	scanf("%d",&n);
	printf("The number entered is: %d",n);
	sum=0;
	while(n!=0)
	{
		digit=n%10;
		printf("\n The digits are:%d",digit);
		digit=digit*digit*digit;
		sum=sum+digit;
		n=n/10;
		
	}
	printf("\n Sum is: %d ",sum);
	return 0;
	
}
