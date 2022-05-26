#include<stdio.h>
#include<stdlib.h>
struct node//structure of NODE
{
int data;
struct node * next;
};
typedef struct node sll;
sll * head=NULL;
void insbeg();//Function for Insertion of a node at the Beginning.
void traversal();//Function for Traversal of List.
void insend();//Function for Insertion of a node at the End.
void inspos();//Function for Insertion of a node after a Specific Position.
void delend();//Function for Deletion of a node from the End.
void delbeg();//Function for Deletion of a node from the Beginning.
void delpos();//Function for Deletion of a node from a Specific Position.
void reverse_sll();//Function for Reversal of a SLL
void sort();
sll *node_create();//Function for Create node
int main()
{
    int n;
    do
    {
        printf("\n1.insbeg\n2.insend\n3.inspos\n4.traversal\n5.delend\n6.delbeg\n7.delpos\n8.reverse_sll\n9.sorting\n10.exit\n");//menu
        printf("enter your choice :");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insbeg();
                    break;
           case 2:  insend();
                    break;
            case 3: inspos();
                    break;
            case 4: traversal();
                    break;
            case 5: delend();
                    break;
            case 6: delbeg();
                    break;
            case 7: delpos();
                    break;
            case 8: reverse_sll();
                    break;
            case 9: sort();
                    break;
            case 10: exit(1);
            default:
                    printf("wrong choice..plz re-enter..! ");
        }

    }while(1);

}
sll *node_create()
{
    sll *n;
    n=(sll*)malloc(sizeof(sll));//dynamical creation of NODE
    printf("enter the data :");
    scanf("%d",&n->data);
    return(n);


}
void insbeg()
{
    sll *new1;
    new1=node_create();
    if(head==NULL)//if no NODE in the list
    {
        head=new1;
        new1->next=NULL;
    }
    else
    {
        new1->next=head;
        head=new1;
    }

}
void insend()
{
    sll *new1,*p;
    new1=node_create();
    if(head==NULL)//if no NODE in the list
    {
        head=new1;
        new1->next=NULL;
    }
    else
    {
        p=head;
        while(p->next!=NULL)//finding last NODE
        {
            p=p->next;
        }
        p->next=new1;
        new1->next=NULL;

    }
}
void inspos()
{
    int pos,i=1;
    sll *new1,*p,*q;
    new1=node_create();
    printf("\nenter the value for position :");
    scanf("%d",&pos);
    if(head==NULL)//if no NODE in the list
    {
        printf("this is the first node..");
        head=new1;
        new1->next=NULL;
    }
    else
    {
        p=head;
        if(pos==1)//if the position is=1
        {
            new1->next=head->next;
            head->next=new1;
        }
        else
        {
            while(i!=pos&&p->next!=NULL)//finding the position
            {
                p=p->next;
                i++;
            }
            if(pos<=0||(i<pos&&p->next==NULL))//if position does not exists
                        printf("this position in this list is not exist.");
            else
            {
            	if(p->next==NULL&&i==pos)//if position is the last position
                {
               		p->next=new1;
               		new1->next=NULL;
            	}
            	else
            	{
                	new1->next=p->next;//if position in between fast and last position
                	p->next=new1;
            	}
            }

    	 }
     }
}
void delbeg()
{
    if(head==NULL)//if no NODE in the list
    {
        printf("\nempty list..");
    }
    else
    {
        if(head->next==NULL)//if only NODE
            head=NULL;
        else
        {
            sll *p=head;
            head=head->next;
            p->next=NULL;
        }
    }

}
void delpos()
{
	sll *p=head,*p1;
	int pos,i=1;
	if(head==NULL)//if no NODE in the list
    		printf("\nempty list..");
	else
	{
            printf("\nenter the position :");
        	scanf("%d",&pos);
    		if(head->next==NULL&&pos==1)//if only NODE and position is 1
                	    head=NULL;
    		else
    		{

                    if(pos==1)//if position is 1
        	    	{
                        head=head->next;
                        p->next=NULL;
                    }
                    else
                    {
                        while(i!=pos&&p->next!=NULL)//finding the position
                        {
                                p1=p;
                    			p=p->next;
                    			i++;
                		}
                		if(i==pos&&p->next==NULL)//if the position is the last position
                		{
                    			p1->next=NULL;
                    			p->next=NULL;
                		}
                		else if(i==pos)//if position is found
                		{
                    			p1->next=p->next;
                    			p->next=NULL;
                		}
                		else if(pos<=0||(i<pos&&p->next==NULL))//if position not found
                    			printf("\nElement of this position is not exist ");
            		}
            }
    	}

}
void delend()
{
	sll *p,*p1;
	p=head;
	if(p==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
	else
	{
	    if(p->next==NULL)//if only exist
            head=NULL;
        else
        {
            while(p->next!=NULL)//finding the last node
            {
                p1=p;
                p=p->next;
            }
            p1->next=NULL;
            p->next=NULL;
        }
	}

}
void traversal()
{
	sll *p;
	p=head;
	if(p==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
	else
    {
        printf("\nthe elements are :-\n");
        while(p!=NULL)//display the elements
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }

}
void reverse_sll()
{
    int i=1;
    sll *p,*q,*r,*l;
    p=head;
    if(p==NULL)//if no NODE in the list
	{
		printf("\nempty list");
	}
    else
    {
        while(p->next!=NULL)//traversal the list
        {
            q=head;
            while(q->next!=NULL)//finding the last node
            {
                r=q;
                q=q->next;
            }
            if(i==1)//changing the link for 1st time
            {
                q->next=head;
                r->next=NULL;
                head=q;
                l=q;
            }
            else if(p->next!=NULL)//changing the link until the first node will be the last node
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
void sort()
{
    sll *p,*q,*r,*k,*m,*k1;
    int max,t;
    p=head;
    k1=NULL;
    while(p->next!=NULL)
    {
        q=head;
        r=q;
        max=head->data;
        while(q!=k1)
        {
            if(q->data>max)
            {
                max=q->data;
                r=q;
            }
            k=q;
            q=q->next;
        }
        if(r!=k)
        {
                t=r->data;
                r->data=k->data;
                k->data=t;
        }
            q=head;
            while(q!=k)
                q=q->next;

            k1=q;
            p=p->next;

    }
    traversal();
}
