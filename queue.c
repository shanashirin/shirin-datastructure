#include<stdio.h>
#include<stdlib.h>
void menu();
void enqueue();
void dequeue();
void display();
void peek();
int queue[50],i,n,choice,item,front=-1,rear=-1;
void main()
{
printf("Enter the size of the queue:");
scanf("%d",&n);
menu();
}
void menu()
{
int choice;
printf("\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.Exit");
printf("\t\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:enqueue();
break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:peek();
break;
case 5:exit(1);
}
}
void enqueue()
{
if(rear!=n-1)
{
printf("\tEnter the element to be inserted:");
scanf("%d",&item);
front=0;
rear=rear+1;
queue[rear]=item;
printf("inserted successfully:");
}
else
{
printf("queue is full,can't insert data");
}
menu();
}
void dequeue()
{
if(front==-1 || front>rear)
{
printf("Queue is empty");
}
else
{
item=queue[front];
printf("Deleted element:\t%d",item);
if(front==rear)
{
front=rear=-1;
}
else
{

front=front+1;
}
}
menu();
}
void display()
{
int i=0;
if(rear==-1)
{
printf("Queue is empty");
}
else
{
printf("queue elements are:");
for(i=front;i<=rear;i++)
printf("%d\t",queue[i]);
}
menu();
}
void peek()
{
if(front==-1)
{
printf("no element in queue\n");
}
else
{
printf("peek element:%d",queue[front]);
}
menu();
}
