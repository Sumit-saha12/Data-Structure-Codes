#include<stdio.h>
#include<stdlib.h>
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
void insert_pos();
void del_beg();
void del_end();
void del_any_pos();
void del_any_val();
void del_dupli();
void del_pred();
void count();
void reverse();
void display();
int main()
{
	int ch;
	
	char c;
	while(1)
	{
		printf("\nMENU\n1.Insert at the begining.\n2.Insert at the end.\n3.Insert at any position.\n4.Insert after any value.\n5.Insert at a particular position.\n6.Delete at begining.\n7.Delete at end.\n8.Delete at any position.\n9.Delete any value.\n10.Delete duplicate values.\n11.Delete the predecessor.\n12.Display.\n13.Node count.\n14.List Reverse.\n15.Exit\n");
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
				insert_pos();
				break;	
			case 6:
				del_beg();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_any_pos();
				break;
			case 9:
				del_any_val();
				break;
			case 10:
				del_dupli();
				break;
			case 11:
				del_pred();
				break;	
			case 12:
				display();
				break;
            case 13:
				count();
				break;
			case 14:
				reverse();
				break;
			case 15: exit(1);
			default:
			   printf("Invalid choice.");
		}
		
	}
	
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
	}
	else
	{
		p->next=head;
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
void ins_any_pos()
{
	NODE *p,*q,*r;
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
			q->next=p;
		}
		else if(i==pos&&q->next==NULL)
		{
			q->next=p;
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
	NODE *p,*q,*r;
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
			q->next=p;
		}
		else if(q->data==key&&q->next==NULL)
		{
			q->next=p;
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

        }
        printf("Deleted data is %d.",p->data);
	}
}
void del_end()
{
	NODE *p=head,*q;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		p=head;
        if(head->next==NULL)
            head=NULL;
		else
		{
			while(p->next!=NULL)
			{
				q=p;
				p=p->next;
			}
			q->next=NULL;
		}
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
			if(pos==1&&p->next!=NULL)
			{
				head=head->next;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(i==pos&&p->next!=NULL)
			{
				q->next=p->next;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(i==pos&&p->next==NULL)
			{
				q->next=NULL;
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
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(p->data==key&&p->next!=NULL)
			{
				q->next=p->next;
				p->next=NULL;
				printf("Deleted data is %d.",p->data);
			}
			else if(p->data==key&&p->next==NULL)
			{
				q->next=NULL;
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
		printf("The list is :");
		while(p!=NULL)
		{
			printf("|%d|->",p->data);
			p=p->next;
		}
		printf("NULL");
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
void reverse()
{
	int i=1;
	NODE *p,*q,*r,*l;
	p=head;
	if(head==NULL)
		printf("Empty list.");
	else
	{
		while(p->next!=NULL)
		{
			q=head;
			while(q->next!=NULL)
			{
				r=q;
				q=q->next;
			}
			if(i==1)
			{
				q->next=head;
				r->next=NULL;
				head=q;
				l=q;
			}
			else if(p->next!=NULL)
			{
				q->next=l->next;
				l->next=q;
				l=l->next;
				r->next=NULL;
			}
			i++;
		}
	}   
}
void insert_pos()
{
	NODE *p,*q,*r;
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
	}
	else
	{
		i=1;
		q=head;
		r=head;
		while(q->next!=NULL&&i!=pos)
		{
			r=q;
			q=q->next;
			i++;
		}
		if(i==pos&&q->next!=NULL)
		{
			if(i==1)
			{
				p->next=head;
				head=p;	
			}
			else
			{
				p->next=r->next;
				r->next=p;
			}
		}
		else if(i==pos&&q->next==NULL)
		{
			p->next=r->next;
			r->next=p;
		}
		else
		{
			printf("Position not present.");
		}
	}
}
void del_dupli()
{
	NODE *p,*q,*r;
	r=head;
	for(p=head;p!=NULL;p=p->next)
	{
		r=p;
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data==q->data)
			{
			    if(q->next==NULL)
                
				
				r->next=NULL;
                else
                r->next=q->next;
			}
			else
            r=q;
		}
	}
}
void del_pred()
{
	NODE *p=head,*q,*r;
	int key;
	if(head==NULL)
	printf("Empty list.");
	else
	{
		printf("Enter the value : ");
		scanf("%d",&key);
		while(p->next!=NULL&&p->data!=key)
		{
			r=q;
			q=p;
			p=p->next;
		}
		if(p->data==key)
		{
			if(key==head->data)
			printf("The head has no predecessor.");
			else
			{
				if(key==head->next->data)
				{
					head=head->next;
					q->next=NULL;
				}
				else
				{
					r->next=p;
					q->next=NULL;	
				}
			}
		}
		else
		printf("Value not found.");
	}
}
