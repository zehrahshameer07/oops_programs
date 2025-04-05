#include<stdio.h>
int main()
{
	int a[20];
	int i,n,sum,mean;
	sum=0;
	printf("Enter the size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the value of a[%d]:",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
	    sum=sum+a[i];
	}
	mean=sum/n;
    printf("The sum is:%d",sum);
	printf("\nThe mean is:%d",mean);
	return 0;
}
