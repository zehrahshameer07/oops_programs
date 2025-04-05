#include <stdio.h>
int main()
{
	int num;
	printf("Enter an integer number:");
	scanf("%d",& num);
		printf("\n Multiplication table of %d is:", num);
	for(int i=1;i<=10;i++)
	{
		printf("\n %d*%d = %d", num,i,(num*i)); 
	}
	return 0;
}
