#include<stdio.h>
#include<conio.h>
void quicksort(int a[],int,int);
int partition(int a[],int,int);
int main()
{
  int k[50],i,n;
  printf("Enter the number of element(n) :");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0;i<n;i++)
  {
    printf("a[%d] :",i);
    scanf("%d",&k[i]);
  }
    quicksort(k,0,n-1);
    printf("\nSorted elements are :");
    for(i=0;i<n;i++)
		  printf("\na[%d]=%d",i,k[i]);
getch();
}
void quicksort(int a[],int p,int r)
{
	 int q;
	 if(p<r)
	 {
		q=partition(a,p,r);
		quicksort(a,p,q);
		quicksort(a,q+1,r);
	 }
}
int partition(int a[],int p,int r)
{
	  int x,i,j,t;
	  x=a[p];
	  i=p-1;
	  j=r+1;
	  while(1)
	  {
		 do
		 {
		 j=j-1;
		 }while(a[j]>x);
		 do
		 {
		 i=i+1;
		 }while(a[i]<x);
		 if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
		 else
		 return(j);
		}
}
