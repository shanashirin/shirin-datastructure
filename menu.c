#include<stdio.h>
#include<stdlib.h>
int choice,j,i=0,a[50],b[10],s;
void menu();
void insert();
void delete();
void sort();
void search();
void display();
void main()
{
printf("\nEnter the size of array:");
scanf("%d",&s);
printf("Enter the elements of the array:");

for(i=0;i<s;i++)
{
scanf("%d",&a[i]);
}
menu();
}
void menu()
{
printf("\n1.Insert");
printf("\n2.Delete");
printf("\n3.sort");
printf("\n4.search");
printf("\n5.Display");
printf("\n6.Exit");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:insert();
	break;
case 2:delete();
	break;
case 3:sort();
	break;
case 4:search();
	break;
case 5:display();
	break;
case 6:
	exit(1);
}
}
void insert(){
int loc,ele;
printf("\nEnter the location:");
scanf("%d",&loc);
printf("Enter the element to be inserted:");
scanf("%d",&ele);
for(i=s;i>loc-1;i--)
a[i]=a[i-1];
a[loc-1]=ele;
printf("\nElement inserted");
printf("\nNew array after insertion:");
s++;
for(i=0;i<s;i++)
printf("\t%d",a[i]);
menu();
}
void delete(){
int loc;
printf("\nEnter location:");
scanf("%d",&loc);
for(i=loc-1;i<s-1;i++)
{
a[i]=a[i+1];
}
a[s-1]=NULL;
printf("\nElement deleted");
printf("\nNew array after deletion:");
s--;
for(i=0;i<s;i++)
printf("\t%d",a[i]);
menu();
}
void sort(){
printf("\nCurrent Array:");
for(i=0;i<s;i++)
printf("\t%d",a[i]);
for(i=0;i<s;i++)
{
for(j=i+1;j<s;j++)
if(a[i]>a[j])
{
a[i]=a[i]+a[j];
a[j]=a[i]-a[j];
a[i]=a[i]-a[j];
}
}
printf("\nSorted array:");
for(i=0;i<s;i++)
printf("\t%d",a[i]);
menu();
}
void search(){
int ele,loc;
printf("\nEnter element to be searched:");
scanf("%d",&ele);
printf("Element found at:");
for(i=0;i<s;i++)
{
if(ele==a[i])
printf("%d",i+1);
}
menu();
}
void display()
{
int i;
if(s==0)
{
printf("No elements to display!");
return;
}
printf("Array elements are:");
for(i=0;i<s;i++)
{
printf("%d\t",a[i]);
}
menu();
}
	

