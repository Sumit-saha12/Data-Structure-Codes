#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10],n,i,j,flag,t;
	printf("enter the number of elements :");
	scanf("%d",&n);
	printf("\nenter the data of array :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	printf("\nsorted data are :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	

}
