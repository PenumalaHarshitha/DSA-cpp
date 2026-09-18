#include<stdio.h>
#include<stdlib.h>

 typedef struct node
{
    int data;
    struct node *link;
}node;


node *arraytoLL(int a[],int n)
{
    node *head= (struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->link=NULL;
    node *temp=head;
    for(int i=1;i<n;i++)
        {
            node *newnode=(struct node*)malloc(sizeof( struct node));
            newnode->data=a[i];
            temp->link=newnode;
            temp=newnode;
        }
    return head;
}


void printLL(node *head)
{
    node *temp=head;
    printf("\nDisplay: ");
    while(temp!=NULL)
        {
            printf("\t%d", temp->data);
            temp=temp->link;
        }
}


int search(node *head, int val)
{ 
    int cnt=0;
    node *temp = head;
    while(temp!=NULL)
        {
            cnt++;
            if(temp->data ==val)
            {
                return cnt;
            }
            temp=temp->link;
        }
    return -1;
}


int length(node *head)
{
 int cnt=0;
    node *temp=head;
    while(temp!=NULL)
        {
            cnt++;
            temp=temp->link;
        }
    return cnt;
}


int main()
{
  int a[]={23,5,67,8,90,2};
    int n =(sizeof(a)/sizeof(a[0]));
    node *head=NULL;
    head= arraytoLL(a,n);
     printLL(head);
    int k=search(head,23);
    if(k==-1)
       {
        printf("\nElement not found");
       }
    else
    {
        printf("\nElement is found at position : %d",k);
    }
    int l=length(head);
    printf("\nLength of the Linkedlist is %d", l);
return 0;
}
