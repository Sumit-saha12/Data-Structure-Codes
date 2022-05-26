#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void enqueue();
void dequeue();
void display();
main()
{
	int q[100],i,max,ch,front=-1,rear=-1;
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
				if(rear==max-1)
				printf("Queue is full.");
				else
				{
					rear++;
					if(rear==0)
					front=0;
					enqueue();
				}
				break;
			case 2:
				if(rear==-1&&front==-1)
				printf("Queue is empty.");
				else
				{
					dequeue();
					if(rear==front)
					{
						front=-1;
						rear=-1;
					}
					else
					front++;
				}
				break;
			case 3:
				if(rear==-1&&front==-1)
				printf("Queue is empty.");
				else
				display();
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
void enqueue()
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->next=NULL;
	}
}
void dequeue()
{
	NODE *p;
	if(head==NULL)
	printf("Empty list.");
	else
	{
        p=head;
        if(head->next==NULL)
            head=NULL;
        else
        {
            head=head->next;
            p->next=NULL;

        }
        printf("Deleted data is %d.",p->data);
	}	
}
void display()
{
	NODE *p=head;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		printf("The list is :");
		while(p!=NULL)
		{
			printf("|%d|",p->data);
			p=p->next;
		}
	}	
}
