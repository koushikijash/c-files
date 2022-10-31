#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
	int info;
	struct node *lptr;
	struct node *rptr;
};
struct node *first;
int info;
//
//create();
//
//beginsert ();
//endinsert ();
//anyposins();
//
//begdelete();
//enddelete();
//anyposdel();
//
//display();
//getch();

void main()
{
	
	
	int choice;
	while (1) 
		{
		printf("\n*********Main Menu*********\n");
		printf("\nChoose one option from the following list ...\n");
		printf("\n1.Create \n2.Insert in begining \n3.Insert at end \n4.Insert at any pos \n5.Delete from begining \n6.Delete from end \n7.Insert at any pos \n8.Display \n9.Exit\n");
	
		printf("\nEnter your choice:\n");
		scanf("\n%d",&choice);
		switch(choice)
		{
		case 1:
			create();
			break;
			
		case 2: 
			beginsert();
			break;
		case 3: 
			endinsert();
			break;
		case 4:
			anyposins();
			break;
		
		case 5: 
			begdelete();
			break;
		case 6: 
			enddelete();
			break;
		case 7:	
			anyposdel();
			break;
			
		case 8: 
			display();
		break;
		
//		case 9:
//			exit(0);
//		break;
		default: printf("Wrong choice");
		}
		}
		}
//	
//	
//	create();
//	getch();
//}

create()
{
	struct node *ptr, *ptr1;
 	char ch;
 	
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter first node");
	scanf("%d",&ptr->info);
	ptr->lptr=NULL;
	first=ptr;
	do
	{
		ptr1=(struct node *)malloc(sizeof(struct node));
		printf("Enter info for next node");
		scanf("%d",&ptr1->info);
		ptr->rptr=ptr1;
		ptr1->lptr=ptr;
		ptr=ptr1;
		printf("Press Y/N for insert more");
		ch=getch();
	}while(ch=='Y');
	ptr->rptr=NULL;
}



beginsert()
{
   struct node *avail,*ptr;
		avail = (struct node *)malloc(sizeof(struct node));
		
		if(avail == NULL)
		{
		printf("\nOVERFLOW");
		return;
		}
		
		ptr=avail;
		avail=avail->rptr;
			printf("enter info part for new node");
		scanf("%d",&ptr->info);
		
		ptr->lptr=NULL;
	
		
		first->lptr=ptr;
				
		ptr->rptr=first;
		first=ptr;
	
		printf("\nnode inserted\n");
		
    	}
	


 endinsert()
	{
		struct node *avail, *ptr1,*ptr;
		
		avail = (struct node *)malloc(sizeof(struct node));
		
		if(avail == NULL)
		{
		printf("\nOVERFLOW");
		return;
		}
		
		ptr=avail;
		avail=avail->rptr;
		printf("enter info part for new node");
		scanf("%d",&ptr->info);
		
		ptr->rptr=NULL;
		
		ptr1=first;
		
		while(ptr1->rptr != NULL)
		ptr1=ptr1->rptr;
		
		ptr1->rptr=ptr;
		ptr->lptr=ptr1;
	
		printf("\nnode inserted at end\n");
		
    	}
    	
    	
    	////////////



begdelete()
{
	struct node *ptr;
	if(first == NULL)
	{
	printf("\nUNDERFLOW");
	return;
	}
	
    ptr = first;
	
	first=first->rptr;
	first->lptr == NULL;
	free(ptr);
	first = ptr->rptr;
	printf("\nnode deleted\n");
}








enddelete()
	{
	struct node *ptr,*ptr1;
	if(first == NULL)
	{
	printf("\nUNDERFLOW");
	return;
	}
	
    ptr = first;
	while(ptr -> rptr != NULL)
	{
	ptr1 = ptr;
	ptr=ptr->rptr;
	}
	ptr1->rptr=NULL;
	free(ptr);
	
	printf("\nnode deleted\n");
	}
	



display()
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
while(ptr -> rptr != first)
{
printf("%d\n", ptr -> info);
ptr = ptr -> rptr;
}
printf("%d\n", ptr -> info);
}
}

