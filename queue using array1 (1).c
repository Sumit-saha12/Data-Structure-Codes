#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int rear=-1,front=-1;

void ins(int *,int);
void del(int *);
void display(int *);

int main()
{
int ch,max;
int q[20];
printf("enter the maxsize :");
scanf("%d",&max);
while(1)
{


       printf("\n1.for insertion\n");
       printf("2.for deletion\n");
       printf("3.for display\n");
       printf("4.exit\n");
       printf("enter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	case 1: ins(q,max);
		break;
	case 2: del(q);
		break;
	case 3: display(q);
		break;
	case 4: exit(0);
		break;
	default: printf("wrong choice\n");
	}
}
getch();
}

void ins(int *queue,int MAX)
{
	if(rear==MAX-1)
	{
		printf("queue is full\n");
		return;
	}
	else
	{
		rear=rear+1;
		scanf("%d",&queue[rear]);
		if(rear==0)
            front=0;
	}
}

void del(int *queue)
{
	int item;
	if(front==-1)
	{
		printf("queue is empty\n");
		return;
	}
	else
    {
    item=queue[front];
	if(rear==front)
	{
		rear=-1;
		front=-1;
	}
	else
	{
		front=front+1;

	}
	printf("the deleted element is=%d\n",item);
    }
}

void display(int *queue)
{
	int n;
	if(front==-1)
	{
		printf("queue is empty\n");
		return;
	}
	for(n=front;n<=rear;n++)
	{
		printf("%d\t",queue[n]);
	}
}
