#include<stdio.h>
void enqueue(int*,int);
void dequeue(int*,int);
void display(int*,int);
int front=-1,rear=-1;
main()
{
	int q[100],i,max,ch;
	char c;
	printf("Enter the max size of the queue : ");
	scanf("%d",&max);
	do
	{
		printf("\n1.INSERT.\n");
		printf("2.DELET.\n");
		printf("3.DISPLAY.\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue(q,max);
				break;
			case 2:
				dequeue(q,max);
				break;
			case 3:
				display(q,max);
				break;
		   	default:
			   printf("Wrong choice.");		
		}
		fflush(stdin);
		printf("\nDo you want to continu?\n: ");
		scanf("%c",&c);
	}
	while(c=='Y'||c=='y');
}
void enqueue(int *q,int max)
{
	int data;
	if(((rear==(max-1))&&(front==0))||(rear==front-1))
	printf("Queue is full.");
	else
	{
		printf("Enter the data : ");
		scanf("%d",&data);
		if(rear==(max-1))
		rear=0;
		else
		rear++;
		q[rear]=data;
		if(rear==0&&front==-1)
		front=0;
	}
}
void dequeue(int *q,int max)
{
	int data;
	if(rear==-1&&front==-1)
	printf("Queue is empty.");
	else
	{
		data=q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			if(front==max-1)
			front=0;
			else
			front++;
		}
		printf("Deleted data is %d.",data);
	}
}
void display(int *q,int max)
{
	int i;
	if(rear==-1&&front==-1)
	printf("Queue is empty.");
	else
	{
		if(rear>front)
		{
			for(i=front;i<=rear;i++)
			printf("|%d|",q[i]);
		}
		else
		{
			for(i=front;i<=max-1;i++)
			printf("|%d|",q[i]);
			for(i=0;i<=rear;i++)
			printf("|%d|",q[i]);
		}
	}
}
