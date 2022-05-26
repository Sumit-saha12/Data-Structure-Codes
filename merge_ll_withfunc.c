#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node* insert(node *,int);
void display(node*);
int main()
{
	int i,n,m,x;
	node *head1,*head2,*head3,*p,*q,*r,*k;
	head1=NULL;
	head2=NULL;
	head3=NULL;
	printf("Enter the number of nodes in the first list:");
	scanf("%d",&n);
	printf("\nEnter the data in sorted order :\n\n");
	head1=insert(head1,n);
	printf("\nThe first list is:\n");
	display(head1);
	printf("\n\nEnter the number of nodes in the second list:");
	scanf("%d",&m);
	printf("\nEnter the data in sorted order :\n\n");
	head2=insert(head2,m);
	printf("\nThe second list is:\n");
	display(head2);
	p=head1;
	q=head2;
	while(p!=NULL&&q!=NULL)
	{
	    r=(node*)malloc(sizeof(node));
		if(p->data<q->data)
		{
			r->data=p->data;
			p=p->next;
		}
		else
		{
			r->data=q->data;
			q=q->next;
		}
		if(head3==NULL)
		{
			head3=r;
			head3->next=NULL;
		}
		else
		{
			k=head3;
			while(k->next!=NULL)
			{
				k=k->next;
			}
			k->next=r;
			r->next=NULL;
		}


	}
	while(p!=NULL)
	{
	    r=(node*)malloc(sizeof(node));
		r->data=p->data;
		k=head3;
        while(k->next!=NULL)
        {
				k=k->next;
        }
        k->next=r;
        r->next=NULL;
		p=p->next;
	}
	while(q!=NULL)
	{
		r=(node*)malloc(sizeof(node));
		r->data=q->data;
		k=head3;
        while(k->next!=NULL)
        {
				k=k->next;
        }
        k->next=r;
        r->next=NULL;
		q=q->next;
	}
	printf("\n\nThe merged list is:\n");
	display(head3);
}

node * insert(node * head1,int n)
{
    int i,m,x;
	node *p,*q,*r,*k;
	for(i=1;i<=n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the data:");
		scanf("%d",&p->data);
		if(head1==NULL)
		{
			head1=p;
			head1->next=NULL;
		}
		else
		{
			q=head1;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=p;
			p->next=NULL;
		}
	}
	return head1;
}
void display(node *head)
{
	node *q;	
	for(q=head;q!=NULL;q=q->next)
	{
		printf("|%d|->",q->data);
	}
	printf("NULL");
	
}