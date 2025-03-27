#include<stdio.h>

int push(int stack[],int size,int *top,int data)
{
	if(*top == size-1)
		return 0;
	
	else
	{
		(*top)++;
		stack[*top]=data;
		return 1;
	}
}

int pop(int stack[],int *top,int *retval)
{
	if( *top == -1)
		return 0;
	
	else
	{
		*retval=stack[*top];
		(*top)--;
		return 1;
	}
}

int peek(int top,int stack[],int index,int *retval)
{
	if( index > top || index < 0)
		return 0;
	else{
		*retval= stack[index];
		return 1;
	}
}

int main()
{
	int size;
	printf("\n Enter the Size of Stack : ");
	scanf("%d",&size);
	
	int stack[size];
	int i,ele;
	
	printf("\n Enter How many Elements you want to store in the Stack Currently ?:");
	scanf("%d",&ele);
	
	if(ele>size)
	{
		printf("\n ERROR :- The no of elements is greater than the size of a Stack ");
		return 1;
	}
	
	if(ele>0){
		printf("\n => Enter the %d elements in your stack \n",ele);
	}
	
	for(i=0;i<ele;i++)
	{
		scanf("%d",&stack[i]);
	}
	
	int top=ele-1;
		
	char ch;
	printf("\n -- Do you want to perform Operations on Stack(y/n) : ");
	fflush(stdin);
	scanf("%c",&ch);
	
	if(ch=='y' || ch=='Y')
	{
		char ch1;
		do{
	
			printf("\n\t ~~~~~~ Operations of Stack ~~~~~~");
			printf("\n\t 1. Push ");
			printf("\n\t 2. POP ");
			printf("\n\t 3. PEEK");
			
			int choice;
			printf("\n Enter -> Which Opeartion you want to perform ?: ");
			scanf("%d",&choice);
			
			int index;
			int status,data;
			int retval;
			switch(choice)
			{
				case 1:
					printf("\n Enter the data you want to store in the Stack : ");
					scanf("%d",&data);
					
					status = push(stack,size,&top,data);
					
					if(status == 1 ){
						printf("\n \t ----- SUCCESS ----- ");
						printf("\n \t The Data is Successfully stored at Top Position in  Stack");
					}
					else
					if( status == 0){
						printf("\n \t !!!! FAIL !!!! ");
						printf("\n \t  Stack is full , we can't store data at Top position");
					}
					
					else
						printf("\n Failed to store ");
						
				printf("\n =====================================================================");
				break;
				
				case 2:
					status=pop(stack,&top,&retval);
					
					if(status == 1 ){
						printf("\n \t ----- SUCCESS ----- ");
						printf("\n \t The Data is Successfully RETERIVED at Top Position in  Stack");
					}
					else
					if( status == 0){
						printf("\n \t !!!! FAIL !!!! ");
						printf("\n \t  Stack is EMPTY, we can't RETRIVE data at Top position");
					}
					
					else
						printf("\n Failed to RETRIVE ");
				printf("\n =====================================================================");
				break;
				
				case 3:
					printf("\n Enter the index at which you want the data : ");
					scanf("%d",&index);
					
					status=peek(top,stack,index,&retval);
					if(status==1)
					{
						printf("\n\t\t *****Success ****** ");
						printf("\n\t\t => The data at %d index : %d",index,retval);
					}
					else
					if(status == 0)
						printf("\n\t FAIL !!! - Enterred the Wrong Index");
					
					else
						printf("\n FAIL ");
				printf("\n =====================================================================");
				break;
				
				default:
					printf("\n Invalid Choice ");
					
			}
			
			printf("\n\n\n Do you want to Exit ?(y/n) : ");
			fflush(stdin);
			scanf("%c",&ch1);
		}while(ch1=='n'||ch1=='N');
	}
	
	
	printf("\n Thank You :) ");
	
	return 0;
}
