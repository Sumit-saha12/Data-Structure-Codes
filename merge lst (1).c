#include<stdio.h>
#include<stdlib.h>
struct node//structure of NODE
{
int data;
struct node * next;
};
typedef struct node sll,sll1,sll2;
sll *head3=NULL;
sll1 *head1=NULL;
sll2 *head2=NULL;
void insend(sll *);
void sort();
void marge();
void display();
sll *node_create();
int main()
{
   int n,m,i;
   sll *new1,*p;
   printf("Enter the number of node in 1st list:\n");
   scanf("%d",&n);
   printf("Enter the data for 1st list:\n");
    for(i=0;i<n;i++)
    {
    new1=node_create();
    if(head1==NULL)//if no NODE in the list
    {
        head1=new1;
        new1->next=NULL;
    }
    else
    {
        p=head1;
        while(p->next!=NULL)//finding last NODE
        {
            p=p->next;
        }
        p->next=new1;
        new1->next=NULL;
    }

    }
    printf("\nEnter the number of node in 2nd list:\n");
   scanf("%d",&m);
   printf("Enter the data for 2nd list:\n");
    for(i=0;i<m;i++)
    {
    new1=node_create();
    if(head2==NULL)//if no NODE in the list
    {
        head2=new1;
        new1->next=NULL;
    }
    else
    {
        p=head2;
        while(p->next!=NULL)//finding last NODE
        {
            p=p->next;
        }
        p->next=new1;
        new1->next=NULL;
    }
    }
    display();
    merge();


}
sll *node_create()
{
    sll *n;
    n=(sll*)malloc(sizeof(sll));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&n->data);
    return(n);
}
void display()
{
	sll *p,*q;
	p=head1;
	if(p==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
	else
    {
        printf("\n 1slist the elements are :-\n");
        while(p!=NULL)//display the elements
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n 2nd list  elements are :-\n");
        q=head2;
        while(q!=NULL)//display the elements
        {
            printf("%d ",q->data);
            q=q->next;
        }
    }
}
void merge()
{
    sll *p,*q,*r,*new1;
    int x;
    p=head1;
    q=head2;
    r=head3;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data>q->data)
        {
            x=q->data;
            q=q->next;
        }
        else
        {
            x=p->data;
            p=p->next;
        }
        new1=(sll*)malloc(sizeof(sll));
        new1->data=x;
        if(head3==NULL)//if no NODE in the list
        {
            head3=new1;
            new1->next=NULL;
        }
        else
        {
            r=head3;
            while(r->next!=NULL)//finding last NODE
            {
                r=r->next;
            }
            r->next=new1;
            new1->next=NULL;
        }

    }
    while(p!=NULL)
    {

        new1=(sll*)malloc(sizeof(sll));
        new1->data=p->data;
        r=head3;
        while(r->next!=NULL)//finding last NODE
            r=r->next;
        r->next=new1;
        new1->next=NULL;
        p=p->next;

    }
    while(q!=NULL)
    {

        new1=(sll*)malloc(sizeof(sll));
        new1->data=q->data;
        r=head3;
        while(r->next!=NULL)//finding last NODE
            r=r->next;
        r->next=new1;
        new1->next=NULL;
        q=q->next;
    }
    printf("\n merge list  elements are :-\n");
    r=head3;
    while(r!=NULL)//display the elements
    {
            printf("%d ",r->data);
            r=r->next;
    }
}
