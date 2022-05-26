#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *lchild,*rchild;
};
typedef struct node bst;
bst *creat(int);
bst *insert(bst*,int);
void in(struct node*);
void pre(struct node*);
void post(struct node*);
void maximum(bst *);
void minimum(bst *);
int search(bst *,int);
bst* Delete( bst*,int );
bst* findMin(bst *root);
void non_in(bst *);
void non_pre(bst *);
void non_post(bst *);
struct node* insert1(struct node* , int );


int main()
{
int x,c,item;
bst *root=NULL;
do
{
printf("\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.maximum\n7.minimum\n8.exit\n9.dispaly\n");
printf("\nenter the choice :");
scanf("%d",&c);
	switch(c)
	{
		case	1:	printf("\nenter the element :");
                    scanf("%d",&x);
                    root=insert1(root,x);
                    break;
		case	2:	in(root);
                    break;
		case	3:	pre(root);
                    break;
		case	4:	post(root);
                    break;

        case    5:  printf("Enter data: ");
                    scanf("%d",&item);
                    x=search(root,item);
                    if(x==1)
                        printf("\ndata is found\n");
                    else
                        printf("\ndata is not found\n");
                    break;
        case    6:  maximum(root);
                    break;
        case    7:  minimum(root);
                    break;
        case    9:  printf("\nenter the element :");
                    scanf("%d",&x);
                    root=Delete(root,x);
                    break;
        case 10 :   non_in(root);
                    break;
        case 11 :   non_pre(root);
                    break;
      //  case 12 :   non_post(root);
                    break;
		default	 :	printf("enter the right ");
				break;
	}
}while(c!=8);
}
void non_in(bst *r)
 {
 int top=0;
 bst *s[20],*pt=r;
 s[0]=NULL;
 while(pt != NULL)
  {
  s[++top] = pt;
  pt = pt->lchild;
  }
 pt = s[top--];
 while(pt != NULL)
  {
  printf("%d ",pt->data);
  if(pt->rchild != NULL)
   {
   pt = pt->rchild;
   while(pt != NULL)
    {
    s[++top] = pt;
    pt = pt->lchild;
    }
   }
   pt = s[top--];
  }
 }
 void non_pre(bst *r)
 {
 int top=0;
 bst *s[20],*pt=r;
 s[0]=NULL;
 while(pt != NULL)
  {
  printf("%d ",pt->data);
  if(pt->rchild != NULL)
   s[++top] = pt->rchild;
  if(pt->lchild != NULL)
   pt = pt->lchild;
  else
   pt = s[top--];
  }
 }
bst *creat(int x)
{
 struct node *new1;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->data=x;
 new1->lchild=NULL;
 new1->rchild=NULL;
 return(new1);
 }
bst *insert(struct node *root,int x)
{

  struct node *ptr=root;
  if(ptr==NULL)
  {
	ptr=creat(x);
	return(ptr);
  }
  while(1)
  {
	if(ptr->data>x)
	{
		if(ptr->lchild==NULL)
		{
			ptr->lchild=creat(x);
			break;
		}
		else
		ptr=ptr->lchild;
	}
	else
	{
		if(ptr->rchild==NULL)
		{
			ptr->rchild=creat(x);
			break;
		}
		else
		ptr=ptr->rchild;
	}
  }
  return(root);
}

void in(bst *root)
{
	if(root->lchild!=NULL)
		in(root->lchild);
	printf("%d ",root->data);
	if(root->rchild!=NULL)
		in(root->rchild);
}
void pre(bst *root)
{
	printf("%d ",root->data);
	if(root->lchild!=NULL)
		pre(root->lchild);
	if(root->rchild!=NULL)
		pre(root->rchild);
}
void post(bst *root)
{
	if(root->lchild!=NULL)
		post(root->lchild);
	if(root->rchild!=NULL)
		post(root->rchild);
	printf("%d ",root->data);
}
void maximum(bst *t)
{
	bst *ptr=t;
	if(ptr!=NULL)
	{
		while(ptr->rchild!=NULL)
			ptr=ptr->rchild;
	}
	printf("maximum value is :%d",ptr->data);
}
void minimum(bst *t)
{
	bst *ptr=t;
	if(ptr!=NULL)
	{
		while(ptr->lchild!=NULL)
			ptr=ptr->lchild;
	}
	printf("minimum value is :%d",ptr->data);
	//return
}

int search(bst *t,int item)
{
	bst *ptr=t;
	int flag=0;
	//printf("Enter data: ");
	//scanf("%d",&item);
	while(ptr!=NULL&&flag==0)
	{
		if(ptr->data==item)
		{
			flag=1;
			return 1;
		}
		else if(ptr->data<item)
			ptr=ptr->rchild;
		else
			ptr=ptr->lchild;
	}
	if(flag==0)
        return 0;
}
bst* Delete( bst* root,int value)
{
    bst *temp;
    int c;
	c=search(root,value);
	if(c==0)
    {
        printf("\ndata not exist");
        return root;
    }
	if(root==NULL)
    {
        printf("\nempty tree");
        return root;
		//return root;
    }
	else if(value< root->data)
	{
		root->lchild= Delete(root->lchild,value);
	}
	else if(value> root->data)
	{
		root->rchild= Delete(root->rchild,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			//delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->lchild==NULL)
		{
			temp=root;
			root=root->rchild;
			//delete temp;
			return root;
		}
		else if(root->rchild==NULL)
		{
			temp=root;
			root=root->lchild;
			//delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			temp=findMin(root->rchild);
			root->data=temp->data;
			root->rchild=Delete(root->rchild,temp->data);
		}
	}
	return root;
}
bst* findMin(bst *root)
{
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
    return root;
}
struct node* insert1(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return creat(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->lchild  = insert1(node->lchild, key);
    else if (key > node->data)
        node->rchild = insert1(node->rchild, key);

    /* return the (unchanged) node pointer */
    return node;
}
