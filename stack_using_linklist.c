#include<stdio.h>
#include<stdlib.h>
struct node//structure of node
{
    int data;
    struct node * next;
};
typedef struct node stack;
void push(int);//for pushing elements in the stack
void pop();//for poping elements in the stack
void display();//displaying the stack's elements
stack *top=NULL;//top position of the stack
int main()
{
    int ch,t=-1,max,data;
    printf("Enter the maxsize :");
    scanf("%d",&max);
    while(1)
    {
       printf("1.for push\n");
       printf("2.for pop\n");
       printf("3.for display\n");
       printf("4.exit\n");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1: if(t==max-1)//if stack is full
                    printf("\nStack is Full\n");
                else
                {
                    printf("Enter the data :");
                    scanf("%d",&data);
                    t++;
                    push(data);
                }
                break;
        case 2: if(t==-1)//if stack is empty
                    printf("\nStack is Empty\n");
                else
                {
                    pop();
                    t--;
                }
                break;
        case 3: display();
                break;
        case 4: exit(1);
                break;
        default: printf("wrong choice\n");
        }
}
    getch();
}
stack *node_create(int data)
{
    stack *n;
    n=(stack*)malloc(sizeof(stack));//dynamical creation of NODE
    n->data=data;
    return(n);
}
void push(int data)
{
    stack *new1;
    new1=node_create(data);
    if(top==NULL)//if no elements in the list
    {
        top=new1;
        new1->next=NULL;
    }
    else
    {
        new1->next=top;
        top=new1;
    }

}
void pop()
{
    stack *p=top;
    int data;
    if(top->next==NULL)//if only element in the list
    {
            data=top->data;
            top=NULL;
    }
    else
    {
            top=top->next;
            data=p->data;
            p->next=NULL;
    }
    printf("the deleted element is=%d\n",data);

}
void display()
{
    stack *p;
    p=top;
    if(top==NULL)//if no elements in the list
        printf("\nstack is Empty\n");
    else
    {
        printf("\nElements in the stack is\n");
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
    }

}

