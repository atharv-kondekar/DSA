#include<stdio.h>

int EnQueue(int queue[],int data,int *rear ,int front , int size )
{
	if( front == -1 || *rear == -1 )
	{
		*rear = 0;
		front = 0;
		
		queue[*rear]=data;
		return 1;
	}
	
	else
	if ( (*rear+1)%size == front )
	{
		return 0;
	}
	
	else
	{
		*rear=(*rear+1)%size;
		
		queue[*rear]=data;
		
		return 1;
	}
}


int dequeue(int queue[],int *val,int *front , int rear ,int size )
{
	if( *front == -1 && rear == -1)
	{
		return 0;
	}
	
	else
	if( *front == rear )
	{
		*val=queue[*front];
		rear   = 0;
		*front = 0;
	}
	
	else
	{
		*val=queue[*front];
		*front=(*front +1 )%size;
		return 1;
	}
}

int main()
{
	int size;
	printf("\n Enter the size of an array : ");
	scanf("%d",&size);
	
	int queue[size];
	int i,ele;
	
	for(i=0;i<ele;i++)
	{
		printf("\n enter the %d Elment : ",i+1);
		scanf("%d",&queue[i]);
	}
	
	int front;
	int rear;
	
	if(ele <= -1 ){
	 	front=-1;
		rear=-1;
	}
	
	else
	{
		front = 0;
		rear = ele-1;
	}
	int data;
	printf("\n Enter the data for the Enqueue : ");
	scanf("%d",&data);
	
	int val ; 
	
	EnQueue(queue,data,&rear ,front , size );
	dequeue(queue,&val,&front , rear ,size );
	printf("\n The Dequed value : %d",val);
	
}
