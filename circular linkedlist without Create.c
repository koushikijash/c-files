#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
// #include<alloc.h>
struct node
{
int info;
struct node *link;
};
struct node *first;

void beginsert ();
void endinsert ();
void begdelete();
void enddelete();
void display();
void create();
void main ()
{
	int choice;
	while (1) 
		{
		printf("\n*********Main Menu*********\n");
		printf("\nChoose one option from the following list ...\n");
		printf("\n1.Insert in begining\n2.Insert at end\n3.Delete from begining\n4.Delete from end\n5.Display\n6.Create\n7.Exit\n");
	
		printf("\nEnter your choice:\n");
		scanf("\n%d",&choice);
		switch(choice)
		{
		case 1: 
		beginsert();
		break;
		case 2: 
		endinsert();
		break;
		case 3: 
		begdelete();
		break;
		case 4: 
		enddelete();
		break;
		case 5: 
		display();
		break;
		case 6:
		create();
		case 7:
		exit(0);
		break;
		default: printf("Wrong choice");
		}
		}
		}

void beginsert()
		{
		struct node *avail,*ptr1 ,*ptr;
		
		avail = (struct node *)malloc(sizeof(struct node));
		
		if(avail == NULL)
		{
		printf("\nOVERFLOW");
		return;
		}
		
		ptr=avail;
		avail=avail->link;
		printf("enter info part for new node");
		scanf("%d",&ptr->info);
		
		ptr1=first;
		
		while(ptr1->link != first)
		ptr1=ptr1->link;
		
		ptr->link=first;
		first=ptr;
		ptr1->link=first;

		printf("\nnode inserted\n");
		
    	}






void endinsert()
	{
		struct node *avail, *ptr1,*ptr;
		
		avail = (struct node *)malloc(sizeof(struct node));
		
		if(avail == NULL)
		{
		printf("\nOVERFLOW");
		return;
		}
		
		ptr=avail;
		avail=avail->link;
		printf("enter info part for new node");
		scanf("%d",&ptr->info);
		
		ptr1=first;
		
		while(ptr1->link != first)
		ptr1=ptr1->link;
		
		ptr1->link=ptr;
		first=ptr;
		ptr1->link=first;
	
		printf("\nnode inserted at end\n");
		
    	}





void begdelete()
{
	struct node *ptr;
	if(first == NULL)
	{
	printf("\nUNDERFLOW");
	return;
	}
	
    ptr = first;
	while(ptr -> link != first)
	ptr = ptr -> link;
	
	ptr->link = first->link;
	free(first);
	first = ptr->link;
	printf("\nnode deleted\n");
}






void enddelete()
	{
	struct node *ptr,*ptr1;
	if(first == NULL)
	{
	printf("\nUNDERFLOW");
	return;
	}
	
    ptr = first;
	while(ptr -> link != first)
	{
	ptr1 = ptr;
	ptr=ptr->link;
	}
	ptr1->link=first;
	free(first);
	
	printf("\nnode deleted\n");
	}
	


void create()
{
    struct node *ptr, *ptr1;
    char ch;
   ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter 1st node");
		scanf("%d",&ptr->info);
	
	first=ptr;
	do{
	    ptr1=(struct node *)malloc(sizeof(struct node));
	   printf("enter info for next node");
	   scanf("%d",&ptr1->info);
	   ptr->link=ptr1;
	   ptr=ptr1;
	   printf("press Y for more node");
	   ch=getch();
	   
	}while(ch=='Y'||'y');
	
	ptr->link=first;
	
}








void display()
{
struct node *ptr;
ptr=first;
if(first == NULL)
{
printf("\nnothing to print");
}
else
{
printf("\n printing values ... \n");
while(ptr -> link != first)
{
printf("%d\n", ptr -> info);
ptr = ptr -> link;
}
printf("%d\n", ptr -> info);
}
}
