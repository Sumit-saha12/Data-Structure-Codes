#include<stdio.h>
struct pol
{
	int cof,exp;
};
typedef struct pol pol;
main()
{
	pol a[10],b[10],c[20];
	int n,m,i,j,k;
	printf("\nenter the no of term for 1st pol: ");
	scanf("%d",&n);
	printf("\nenter the number of term for 2nd pol: ");
	scanf("%d",&m);
	printf("\nenter the 1st polynomial");
	for(i=0;i<n;i++)
	{
		printf("\nenter coefficient");
		scanf("%d",&a[i].cof);
		printf("\nenter the exponent");
		scanf("%d",&a[i].exp);
	}
	printf("\nenter the 2nd polynomial");
	for(j=0;j<m;j++)
	{
		printf("\nenter coefficient");
		scanf("%d",&b[j].cof);
		printf("\nenter the exponent");
		scanf("%d",&b[j].exp);
	}
	i=0;
	j=0;
	k=0;
	while(i<n&&j<m)
	{
		if(a[i].exp==b[j].exp)
		{
			c[k].cof=a[i].cof+b[j].cof;
			c[k].exp=a[i].exp;
			i++;
			j++;
		}
		else if(a[i].exp>b[j].exp)
		{
			c[k].cof=a[i].cof;
			c[k].exp=a[i].exp;
			i++;
		}
		else
		{
			c[k].cof=b[j].cof;
			c[k].exp=b[j].exp;
			j++;
		}
		k++;
	}
	while(i<n)
	{
		c[k].cof=a[i].cof;
		c[k].exp=a[i].exp;
		i++;
		k++;
	}
	while(j<m)
	{
		c[k].cof=b[j].cof;
		c[k].exp=b[j].exp;
		j++;
		k++;
	}
	printf("\npolynomial addition is: ");
	for(i=0;i<k;i++)
	{
		if(i!=(k-1))
		printf("(%d)x^%d+",c[i].cof,c[i].exp);
		else
		printf("(%d)x^%d",c[i].cof,c[i].exp);
	}
}
