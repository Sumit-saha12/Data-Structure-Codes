#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *prev;
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
		printf("\nMENU\n1.Insert at the begining.\n2.Insert at the end.\n3.Insert after any position.\n4.Insert after any value.\n5.Delete at begining.\n6.Delete at end.\n7.Delete any position.\n8.Delete any value.\n9.Count the number of nodes.\n10.Display.\n");
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
				count();
				break;
			case 10:
				display();
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
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		p->next=head;
		head->prev=p;
		p->prev=NULL;
		head=p;
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
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->prev=q;
		p->next=NULL;
	}
}
void ins_any_pos()
{
	NODE *p,*q;
	int i,pos;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	printf("Enter the position : ");
	scanf("%d",&pos);
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		i=1;
		q=head;
		while(q->next!=NULL&&i!=pos)
		{
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=NULL)
		{
			p->next=q->next;
			q->next->prev=p;
			q->next=p;
			p->prev=q;
		}
		else if(i==pos&&q->next==NULL)
		{
			q->next=p;
			p->prev=q;
			p->next=NULL;
		}
		else
		{
			printf("Position not present.");
		}
	}
}
void ins_any_val()
{
	NODE *p,*q;
	int key;
	p=(NODE*)malloc(sizeof(NODE));
	printf("Enter the data : ");
	scanf("%d",&p->data);
	printf("Enter the value after you want to insert : ");
	scanf("%d",&key);
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		q=head;
		while(q->next!=NULL&&q->data!=key)
		{
			q=q->next;
		}
		if(q->data==key&&q->next!=NULL)
		{
			p->next=q->next;
			q->next->prev=p;
			q->next=p;
			p->prev=q;
		}
		else if(q->data==key&&q->next==NULL)
		{
			q->next=p;
			p->prev=q;
			p->next=NULL;
		}
		else
		{
			printf("Value not present.");
		}
	}
}
void del_beg()
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
            head->prev=NULL;

        }
        printf("Deleted data is %d.",p->data);
	}
}
void del_end()
{
	NODE *p=head,*q;
	if(head==NULL)
	printf("Empty list.");
	else if(head->next==NULL)
	{
		head=NULL;
		printf("Deleted data is %d.",p->data);
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		p->prev=NULL;
		printf("Deleted data is %d.",p->data);
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
		if(head->next==NULL&&pos==1)
		{
			printf("Deleted data is %d.",head->data);
			head=NULL;
		}
		else
		{
			i=1;
			q=p;
			while(p->next!=NULL&&i!=pos)
			{
				q=p;
				p=p->next;
				i++;
			}
			if(i==1&&p->next!=NULL)
			{
				head=head->next;
				p->prev=NULL;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(i==pos&&p->next!=NULL)
			{
				q->next=p->next;
				p->next->prev=q;
				p->prev=NULL;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(i==pos&&p->next==NULL)
			{
				q->next=NULL;
				p->prev=NULL;
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
		if(head->next==NULL&&head->data==key)
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
			if(p->data==head->data&&p->next!=NULL)
			{
				head=head->next;
				p->prev=NULL;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(p->data==key&&p->next!=NULL)
			{
				q->next=p->next;
				p->next->prev=q;
				p->prev=NULL;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(p->data==key&&p->next==NULL)
			{
				q->next=NULL;
				p->prev=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else
			printf("Value does not exist.");
		}
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
		while(p!=NULL)
		{
			i++;
			p=p->next;
		}
	}
	printf("Number nodes is %d.",i);
}
void display()
{
	NODE *p=head;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		printf("The list is : ");
		printf("NULL<=>");
		for(p=head;p!=NULL;p=p->next)
		printf("|%d|<=>",p->data);
		printf("NULL");
	}
}
