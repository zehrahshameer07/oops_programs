#include <stdio.h>
int main()
{
	int num,prod;
	int i;
	printf("Enter an integer number:");
	scanf("%d",& num);
	i=1;
		printf("\n Multiplication table of %d is:", num);
		
	while(i<=10)
	{
		prod=num*i;
		printf("\n %d*%d = %d", num,i,(prod)); 
		i++;
	}
	return 0;
}
