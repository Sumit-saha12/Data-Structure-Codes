#include<stdio.h>
#include<malloc.h>
struct node //structure of node
{
    int cof,exp;
    struct node *next;
};
typedef struct node pol;
void main()
{
    pol *head1=NULL;	// initialize the header node of 1st polynomial with NULL
    pol *head2=NULL;  	 // initialize the header node of 2nd polynomial with NULL
    pol *head3=NULL;	// initialize the header node of resultant polynomial with NULL
    pol *p=head1,*nw1;
    pol *q=head2,*nw2;
    pol *r=head3,*nw3;
    int i=1,j=1,k=1,n,m,f,t,c,e;
    printf("enter the number of term of 1st polynomial : ");
    scanf("%d",&n);
    printf("enter the number of term of 2nd polynomial : ");
    scanf("%d",&m);
    printf("enter the coefficient and exponent of the term for pol1:\n");
    while(i<=n) //entering the 1st polynomial expression
    {
        p=head1;
        nw1=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        if(head1==NULL)//checking for 1st NODE
        {
            head1=nw1;
            head1->next=NULL;
        }
        else
        {
        	while(p->next!=NULL)//finding the last NODE
        	{
				 p=p->next;
            }
            p->next=nw1;
            nw1->next=NULL;
        }
        i++;

    }
   
    printf("eneter the coefficient and exponent of the term for pol2:\n");
    while(j<=m)	// //entering the 2nd polynomial expression
    {
        p=head2;
        nw1=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        printf("enter the coefficient value : ");
        scanf("%d",&nw1->cof);
        printf("enter the exponent value : ");
        scanf("%d",&nw1->exp);
        if(head2==NULL)//checking for 1st NODE
        {
            head2=nw1;
            head2->next=NULL;
        }
        else
        {
        	while(p->next!=NULL)//finding the last NODE
        	{
				 p=p->next;
            }
            p->next=nw1;
            nw1->next=NULL;
        }
        j++;

    }
    printf("\n1st polynomial is : ");
    for(p=head1;p!=NULL;p=p->next)	//displaying the 1st polynomial expression
    {
		if(p->exp!=0)
	        	printf(" %dX^%d +",p->cof,p->exp);
		else
			printf(" %d",p->cof);
    }
    printf("\n2nd polynomial is : ");
    for(q=head2;q!=NULL;q=q->next)	//displaying the 2nd polynomial expression
    {
        if(q->exp!=0)
        	printf(" %dX^%d +",q->cof,q->exp);
	else
		printf(" %d",q->cof);
    }
    printf("\n");
    p=head1;
    q=head2;
    while(p!=NULL&&q!=NULL)	// perform the addition between two given polynomial
    {
        r=head3;
        if(p->exp==q->exp) //if the exponent values of two polynomial expression is same
        {
            c=p->cof+q->cof;
            e=p->exp;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)//if the exponent values of 1st polynomial expression greater than 2nd polynomial expression
        {
            c=p->cof;
            e=p->exp;
            p=p->next;
        }
        else if(p->exp<q->exp)//if the exponent values of 2nd polynomial expression greater than 1st polynomial expression
        {
            c=q->cof;
            e=q->exp;
            q=q->next;
        }
        nw3=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        nw3->cof=c;
        nw3->exp=e;
        if(head3==NULL)//checking for 1st NODE
        {
            head3=nw3;
            head3->next=NULL;
        }
        else
        {
        	while(r->next!=NULL)//finding the last NODE
        	{
				 r=r->next;
            }
            
            r->next=nw3;
            nw3->next=NULL;
        }
       
    }
    while(p!=NULL&&q==NULL) //if number of term in 1st expression remains and the number of term in the 2nd expression finished
    {
        r=head3;
        p=p->next;
        nw3=(pol*)malloc(sizeof(pol));
        nw3->cof=p->cof;
        nw3->exp=p->exp;
        if(head3==NULL)
        {
            head3=nw3;
            head3->next=NULL;
        }
        else
        {
			while(r->next!=NULL)//finding the last NODE
        	{
				 r=r->next;
            }
            
            r->next=nw3;
            nw3->next=NULL;
        }
        
    }
    while(p==NULL&&q!=NULL) //if number of term in 2nd expression remains and the number of term in the 1st expression finished
    {
        r=head3;
        q=q->next;
        nw3=(pol*)malloc(sizeof(pol));//dynamically creation of NODE
        nw3->cof=q->cof;
        nw3->exp=q->exp;
        if(head3==NULL)//checking for 1st NODE
        {
            head3=nw3;
            head3->next=NULL;
        }
        else
        {
           while(r->next!=NULL)//finding the last NODE
        	{
				 r=r->next;
            }
            
            r->next=nw3;
            nw3->next=NULL;
        }
      
    }
    printf("\nthe addition of two polynomial is : ");
    for(r=head3;r!=NULL;r=r->next)	// displaying the resultant expression
    {
	if(r->exp!=0)
        	printf(" %dX^%d +",r->cof,r->exp);
	else
		printf(" %d",r->cof);
    }
    printf("\n");
}
