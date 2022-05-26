#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL;
void ins_beg();
void ins_end();
void ins_any_pos();
void ins_any_val();
void del_beg();
void del_end();
void del_any_pos();
void del_any_val();
void count();
void display();
main()
{
	int ch;
	char c;
	do
	{
		printf("\nMENU\n1.Insert at the begining.\n2.Insert at the end.\n3.Insert at any position.\n4.Insert after any value.\n5.Delete at begining.\n6.Delete at end.\n7.Delete at any position.\n8.Delete any value.\n9.Display.\n10.Node count\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				ins_beg();
				break;
			case 2:
				ins_end();
				break;
			case 3:
				ins_any_pos();
				break;
			case 4:
				ins_any_val();
				break;
			case 5:
				del_beg();
				break;
			case 6:
				del_end();
				break;
			case 7:
				del_any_pos();
				break;
			case 8:
				del_any_val();
				break;
			case 9:
				display();
				break;
            case 10:
				count();;
				break;
			default:
			   printf("Invalid choice.");
		}
		fflush(stdin);
		printf("\nDo you want to retry press y<for YES> or n for<for NO> : ");
		scanf("%c",&c);
	}
	while(c=='Y'||c=='y');
}
void ins_beg()
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next=head;
	}
	else
	{
		q=head;
		while(q->next!=head)
		q=q->next;
		p->next=head;
		head=p;
		q->next=head;
	}
}
void ins_end()
{
	NODE *p,*q;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next=head;
	}
	else
	{
		q=head;
		while(q->next!=head)
		q=q->next;
		q->next=p;
		p->next=head;
	}
}
void ins_any_pos()
{
	NODE *p,*q,*r;
	int i,pos;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next=head;
	}
	else
	{
		printf("Enter the position : ");
	 	scanf("%d",&pos);
		i=1;
		q=head;
		while(q->next!=head&&i!=pos)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=head)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(i==pos&&q->next==head)
		{
			q->next=p;
			p->next=head;
		}
		else
		{
			printf("Position not present.");
		}
	}
}
void ins_any_val()
{
	NODE *p,*q,*r;
	int key;
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
		printf("Enter the value after you want to insert : ");
		scanf("%d",&key);
		q=head;
		while(q->next!=head&&q->data!=key)
		{
			q=q->next;
		}
		if(q->data==key&&q->next!=head)
		{
			p->next=q->next;
			q->next=p;
		}
		else if(q->data==key&&q->next==head)
		{
			q->next=p;
			p->next=head;
		}
		else
		{
			printf("Value not present.");
		}
	}
}
void del_beg()
{
	NODE *p,*q;
	if(head==NULL)
	printf("Empty list.");
	else
	{
        p=head;
        if(head->next==head)
        {
        	printf("Deleted data is %d.",head->data);
            head=NULL;
		}	
        else
        {
        	q=head;
        	while(p->next!=head)
        	p=p->next;
            head=head->next;
            p->next=head;
            q->next=NULL;
            printf("Deleted data is %d.",q->data);
        }
	}
}
void del_end()
{
	NODE *p=head,*q;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		if(head->next==head)
		{
			printf("Deleted data is %d.",head->data);
			head=NULL;
		}
		else
		{
			q=p;
			while(p->next!=head)
			{
				q=p;
				p=p->next;
			}
			q->next=head;
			p->next=NULL;
			printf("Deleted data is %d.",p->data);
		}
	}
}
void del_any_pos()
{
	NODE *p=head,*q;
	int pos,i;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		printf("Enter the position you want to delete : ");
		scanf("%d",&pos);
		if(head->next==head&&pos==1)
		{
			printf("Deleted data is %d.",head->data);
			head=NULL;
		}
		else
		{	
			i=1;
			q=p;
			while(p->next!=head&&i!=pos)
			{
				q=p;
				p=p->next;
				i++;
			}
			if(i==1&&p->next!=head)
			{
				q=head;
        		while(p->next!=head)
        		p=p->next;
            	head=head->next;
            	p->next=head;
            	q->next=NULL;
				printf("Deleted data is %d.",q->data);
			}
			else if(i==pos&&p->next!=head)
			{
				q->next=p->next;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(i==pos&&p->next==head)
			{
				q->next=head;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else
			printf("Position does not exist.");
		}
	}
}
void del_any_val()
{
	NODE *p=head,*q;
	int key;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		printf("Enter the value you want to delete : ");
		scanf("%d",&key);
		if(head->next==head&&head->data==key)
		{
			printf("Deleted data is %d.",head->data);
			head=NULL;
		}
		else
		{
			q=p;
			while(p->next!=NULL&&p->data!=key)
			{
				q=p;
				p=p->next;
			}
			if(p->data==head->data&&p->next!=head)
			{
				q=head;
        		while(p->next!=head)
        		p=p->next;
            	head=head->next;
            	p->next=head;
            	q->next=NULL;
				printf("Deleted data is %d.",q->data);
			}
			else if(p->data==key&&p->next!=NULL)
			{
				q->next=p->next;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(p->data==key&&p->next==NULL)
			{
				q->next=head;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else
			printf("Position does not exist.");
		}
	}
}
void display()
{
	NODE *p=head;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		p=head;
		printf("The list is :");
		do
		{
			printf("|%d|->",p->data);
			p=p->next;
		}
		while(p!=head);
		printf("Head");
	}
}
void count()
{
	int i=0;
	NODE *p=head;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		p=head;
		do
		{
			p=p->next;
			i++;
		}
		while(p!=head);
	}
	printf("Number nodes is %d.",i);
}
