#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
int val;
struct node *next;
};
struct node *start;
void main()
{
int choice=0;
printf("\nStack operation using linked list\n");
while(choice!=4)
{
printf("\n---MENU---\n");
printf("\n1.push\n2.pop\n3.Display\n4.Exit");
printf("\nEnter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
push(); 
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
printf("Exstinf..");
break;
}
default:
{
printf("Please Enter valid choice");
}
};
}
}
void push()
{
int val;
struct node*ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("not able to push the element");
}
else
{
printf("Enter the value:");
scanf("%d",&val);
if(start==NULL)
{
ptr->val=val;
ptr->next=NULL;
start=ptr;
}
else
{
ptr->val=val;
ptr->next=start;
start=ptr;
}
printf("item pushed");
}
}
void pop()
{
int item;
struct node*ptr;
if(start==NULL)
{
printf("underflow");
}
else
{
item=start->val;
ptr=start;
start=start->next;
free(ptr);
printf("item popped:%d",item);
}
}
void display()
{
int i;
struct node *ptr;
ptr=start;
if(ptr==NULL)
{
printf("stack is empty\n");
}
else
{
printf("printing stack elements\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->val);
ptr=ptr->next;
}
}
}


