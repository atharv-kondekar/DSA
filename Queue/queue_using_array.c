#include<stdio.h>

int EnQueue(int queue[],int size,int *rear,int data,int front)
{
	if( (*rear+1)%size == front )
	{
		return 0;
	}
	
	else
	{
		queue[*rear]=data;
		*rear=(*rear+1)%size;
		return 1;	
	}	
	
}

int DeQueue(int queue[],int size,int *front,int rear,int *deVal,int rear1)
{
	if( *front == rear )
		return 0;
	
	else
	{
		*deVal=queue[*front];
		*front=(*front+1)%size;
		return 1;
	}
}

int main()
{
	int size;
	printf("\n Enter => \nThe size of Queue : ");
	scanf("%d",&size);
	
	int queue[size];
	int i,ele;
	printf("\n Enter=> \nHow many elements you want to store currently in the queue : ");
	scanf("%d",&ele);
	
	if(ele>size)
	{
		printf("\n Error : The no elements you want to enter is greater than the size of the queue");
		return 1;
	}
	
	if(ele>0)
	{
		printf("\n ~~~~~ Enter=> \n The %d elements in your queue  \n",ele);
	}
	
	for(i=0;i<ele;i++)
	{
		scanf("%d",&queue[i]);
	}
	
	int front=0,rear=ele;
	int status;
	int rear1=ele;
	
	char choice;
	printf("\n Enter => \n Do you want to perform any operations on Queue ? (y/n) : ");
	fflush(stdin);
	scanf("%c",&choice);
	
	if(choice=='y'||choice=='Y')
	{
		char ch;
		
		do
		{
			printf("\n --------- The Operations You can Perform on Queue ------------ ");
			printf("\n\t\t 1. Enqueue");
			printf("\n\t\t 1. Dequeue");
			
			int opChoice;
			printf("\n Enter = > \n Which opeartion you want to perform on Queue  : ");
			scanf("%d",&opChoice);
			
			switch(opChoice)
			{
				case 1:
				{
					int data;
					printf("\n Enter the data you want Enqueue in the Queue : ");
					scanf("%d",&data);
					
					status=EnQueue(queue,size,&rear,data,front);
					
					if(status  == 1 )
					{
						printf("\n\t\t **** SUCCESS ****");
						printf("\n\t\t <- The Data is Successfully  Enqueued in the Queue at rear position ->");
					}
					
				/*	else if(status == 0)
					{
						printf("\n\t\t !!!!! FAIL !!!!!");
						printf("\n\t\t <- The Data is not Enqueued at rear position In Queue ->");
					}
				*/
				
					else if( status == 0 )
					{
						printf("\n\t\t !!!! FAIL !!!! ");
						printf("\n\t\t <- The Queue is full ->");
					}
					
					else
						printf("\n\t\t !! FAIL !! ");
					printf("\n ========================================================================");
					break;
				}
				
				case 2:
				{
					int val;
					status=DeQueue(queue,size,&front,rear,&val,rear1);
					
					if(status  == 1 )
					{
						printf("\n\t\t **** SUCCESS ****");
						printf("\n\t\t <- The Data is Successfully  Dequeued in the Queue from front position ->");
						printf("\n\t\t < = The Dequeued Val  : %d =>",val);
					}
					
					else if(status == 0)
					{
						printf("\n\t\t !!!!! FAIL !!!!!");
						printf("\n\t\t <- The Data is not Dequeued from front position In Queue ->");
					}
	
					else
						printf("\n\t\t !! FAIL !! ");
					printf("\n ========================================================================");	
					break;
				}
				
				default:
					printf("\n \t\t INVALID CHOICE ");
			}
			
			printf("\nEnter => \n Do you want to continue ?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch);
			
		}while(ch=='y' || ch=='Y');
	}
	return 0;
}
