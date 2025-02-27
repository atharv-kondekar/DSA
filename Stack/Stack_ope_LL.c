#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * createNode()
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	return ptr;
}

void initNode(struct Node *ptr)
{
	int data;
	printf("\n Enter the data for the Node : ");
	scanf("%d",&data);
	
	ptr->data=data;
	ptr->next=NULL;
}

int push(struct Node **top)
{
	struct Node * NN;
	NN=createNode();
	initNode(NN);
	
	if(NN==NULL)
		return 0;
	else
	{
		NN->next=*top;
		*top=NN;
		return 1;
	}
}

int pop(struct Node **top,int *val)
{
	if( *top == NULL)
		return 0;
	else
	{
		struct Node * ptr = *top;
		*top=ptr->next;
		*val=ptr->data;
		free(ptr);
		return 1;
	}
}

int peek(struct Node *top , int *val ,int index )
{
	int count=0;
	struct Node * curnode = top;
	
	while(curnode!=NULL)
	{
		if(count==index)
		{
			*val=curnode->data;
			return 1;
		}
		count++;
		curnode=curnode->next;
	}
	return 0;
}
int main()
{
	struct Node * top=NULL;
	struct Node * first;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	first=createNode();
	initNode(first);
	second=createNode();
	initNode(second);
	third=createNode();
	initNode(third);
	fourth=createNode();
	initNode(fourth);
	
	fourth->next=third;
	third->next=second;
	second->next=first;
	
	top=fourth;
	
	char ch;
	printf("\n Do you want to perform any operations on Stack ?(y/n): ");
	fflush(stdin);
	scanf("%c",&ch);
	
	if(ch=='y'||ch=='Y')
	{
		char ch1;
		int choice;
		int status;
		int val;
						
		do
		{
			printf("\n\t --- The following operations you can perform on stack ---");
			printf("\n\t\t 1.Push the Node ");
			printf("\n\t\t 2.Pop the Node ");
			
			printf("\n Enter ->\n\twhich operation you want to perform ? : ");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
					status=push(&top);
					
					if(status == 1 )
					{
						printf("\n\t ******** SUCCESS ******* ");
						printf("\n\t  The Node is Pushed Successfully ");
					}
					else
					if(status == 0)
						printf("\n\t !!!!! FAIL :-The stack is full we can't push ");
					else
						printf("\n !!!! FAIL !!!! ");
				printf("\n ========================================================================");
				break;
				
				case 2:
					status=pop(&top,&val);
					
					if(status==1)
					{
						printf("\n\t\t ****** SUCCESS ****** ");
						printf("\n\t\t The Node is Retrived Successfully ");
						printf("\n\t\t << The Retrived Node = [ %d | NULL ] >>",val);
					}
					
					else if(status == 0)
					{
						printf("\n \t\t !!! Fail !!!");
						printf("\n\t\t  The Linked List is Empty we can't retrive ");
					}
					
					else
						printf("\n FAIL ");
				printf("\n ========================================================================");
				break;
				
				case 3:
				{
					int ind;
					printf("\n Enetr the index you want to read the data : ")	;
					scanf("%d",&ind);
					
					status=peek(top , &val ,ind );
					
					if(status == 1 )
							{
								printf("\n\t\t *** SUCCESS ***");
								printf("\n\t\t <<<---- The  data at %d index = %d --->>> ",ind,val);
							}
							
							else 
							{
								printf("\n\t\t !!! FAIL !!! ");
								printf("\n\t\t You Entered Invalid Index");
							}
							
							printf("\n ==============================================================================================\n");
							
							break;
				}	
				default:
					printf("\n INVALID CHOICE ");
					printf("\n ========================================================================");
			}
			printf("\n Do you want to continue ? (y/n) : ");
			fflush(stdin);
			scanf("%c",&ch1);
			
		}while(ch1=='y' || ch1 == 'Y');
	}
	
	printf("\n Thank You :) ");
	
	return 0;
}
