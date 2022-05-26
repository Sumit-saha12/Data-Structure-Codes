#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void bubble_sort(int);
void selection_sort(int);
void insertion_sort(int);
void display(int a[],int);
int main()
{
    int a[20],i,n,m;
    char ch='y';
    printf("enter the number m :");
    scanf("%d",&m);
    while(ch=='y')
    {
        printf("\n1.bubble sort\n2.insertion sort\n3.selection sort\n0.exit\n");
        printf("enter your choice :");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : bubble_sort(m);
                        break;
            case 2 : insertion_sort(m);
                        break;
            case 3 : selection_sort(m);
                        break;
            case 0 : exit(0);

            default :
                    printf("wrong choice..try again..");
        }
        printf("\ndo you want to retry??\n");
        printf("press y for (yes) or n for (no) :");
        fflush(stdin);
        scanf("%c",&ch);
    }
    getch();
}
void selection_sort(int n)
{
    int a[20],i,k,c,max=1,j=0,m;
    printf("enter the array element : \n");
    for(i=1;i<=n;i++)
    {
        printf("enter the element for a[%d] :",i);
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n-j;k++)
        {
            if(a[k]>a[max])
                max=k;
        }
        if((k-1)!=max)
        {
            c=a[k-1];
            a[k-1]=a[max];
            a[max]=c;
        }
        j++;
        max=1;
    }
    display(a,n);
}
void insertion_sort(int  n)
{
    int a[20],i,c,t;
    printf("enter the array element : \n");
    for(i=1;i<=n;i++)
    {
        printf("enter the element for a[%d] :",i);
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        t=a[i];
        c=i-1;
        while(t<a[c]&&c>0)
        {
            a[c+1]=a[c];
            c=c-1;
        }
        a[c+1]=t;
    }
    display(a,n);
}
void bubble_sort(int n)
{
    int a[20],i,k,c;
    printf("enter the array element : \n");
    for(i=1;i<=n;i++)
    {
        printf("enter the element for a[%d] :",i);
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)   //sorting of array element using bubble sort
    {
        for(k=1;k<=n-i;k++)
        {
            if(a[k]>a[k+1])
            {
                c=a[k];
                a[k]=a[k+1];
                a[k+1]=c;
            }
        }
    }
    display(a,n);

}
void display(int a[],int n)
{
    int i;
    printf("\nSorted element are :");
    for(i=1;i<=n;i++)
    {
        printf("\t%d",a[i]);
    }
}

