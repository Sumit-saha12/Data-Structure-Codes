#include<stdio.h>
#include<stdlib.h>
void push(int*,int);
void pop(int*);
void display(int*);
int top=-1;
int main()
{
	int s[30],i,max,ch;
	char c;
	printf("Enter the max size : ");
	scanf("%d",&max);
	while(1)
	{
		printf("\n1.PUSH.\n");
		printf("2.POP.\n");
		printf("3.DISPLAY.\n");
		printf("4.EXIT.\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			        push(s,max);
			        break;
			case 2:
					pop(s);
					break;
			case 3:
					display(s);
					break;
			case 4:
					exit(1);
			default:
					printf("Wrong choice.");		        
		}
	
	}
	
}
void push(int *s,int max)
{
	if(top==(max-1))
		printf("Stack overflow.");
	else
	{
		top++;
		printf("\nEnter the data : ");
		scanf("%d",&s[top]);
	}
}
void pop(int *s)
{
	int x;
	if(top==-1)
		printf("Stack is empty.");
	else
	{
		x=s[top];
		top--;
		printf("Deleted data is %d",x);
	}
}
void display(int *s)
{
	int i;
	if(top==-1)
		printf("Stack is empty.");
	else
	{
		printf("Stack elements are : \n");
		for(i=top;i>=0;i--)
			printf("|%d|\n",s[i]);
	}
}

