#include<stdio.h>
#include<conio.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);
int main()
{
int a[25],i,n,beg=0,end;
printf("enter the number n:");
scanf("%d",&n);
printf("enter the array element");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
end=i-1;
mergesort(a,beg,end);
printf("the sorted element are");
	for(i=0;i<n;i++)
	{
	printf("\na[%d]=%d",i,a[i]);
	}
getch();
}
void mergesort(int a[],int beg,int end)
{
int mid;
if(beg!=end)
{
mid=(beg+end)/2;
mergesort(a,beg,mid);
mergesort(a,mid+1,end);
merge(a,beg,mid,end);
}
}
void merge(int a[],int top,int size,int bottom)
{
int f,t,s,temp[20],upper,i;
f=top;
s=size+1;
t=top;
while((f<=size)&&(s<=bottom))
{
	if(a[f]<=a[s])
	{
		temp[t]=a[f];
		f++;
	}
	else
	{
	temp[t]=a[s];
	s++;
	}
	t++;
}
if(f<=size)
{
	for(i=f;i<=size;i++)
	{
	temp[t]=a[i];
	t++;
	}
}
else
{
	for(i=s;i<=bottom;i++)
	{
	temp[t]=a[i];
	t++;
	}
}
	for(upper=top;upper<=bottom;upper++)
	{
	a[upper]=temp[upper];
	}
}


