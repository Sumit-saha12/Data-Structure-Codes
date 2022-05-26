#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void push();
void pop();
void display();
main()
{
	int s[30],i,max,ch,top=-1;
	char c;
	printf("Enter the max size : ");
	scanf("%d",&max);
	do
	{
		printf("\n1.INSERT.\n");
		printf("2.DELET.\n");
		printf("3.DISPLAY.\n");
		printf("4.EXIT.\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    if(top==max-1)
			    printf("Stack overflow.");
			    else
			    {
			        top++;
			        push();
				}
			    break;
			case 2:
				if(top==-1)
				printf("Stack underflow.");
				else
				{
					pop();
					top--;
				}
				break;
			case 3:
				if(top==-1)
				printf("Stack underflow.");
				else
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice.");		        
		}
		fflush(stdin);
		printf("\nDo you want to continu?\n: ");
		scanf("%c",&c);
	}
	while(c=='Y'||c=='y');
}
void push()
{
	NODE *p;
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
		p->next=head;
		head=p;
	}
}
void pop()
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
		printf("The list is : \n");
		while(p!=NULL)
		{
			printf("|%d|\n",p->data);
			p=p->next;
		}
	}	
}

