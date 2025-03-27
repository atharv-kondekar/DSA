#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

int push(int *top,int size,int data,int stack[])
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

int pop(int stack[],int *top,int *val)
{
	if( *top == -1)
		return 0;
	
	else
	{
		*val=stack[*top];
		(*top)--;
		return 1;
	}
}

int peek(int stack[],int top,int index,int *val)
{
	if( index<0 || index > top )
		return 0;
		
	else{
		*val=stack[top-index];
		return 1;
	}
}

struct Node * CreateNodes(struct Node * Head , int Nodes )
{
	struct Node * head =Head;
	struct Node * tail;
	int i;
	int data;
	
	for(i=0;i<Nodes;i++)
	{
		struct Node * NewNode;
		NewNode=(struct Node *)malloc(sizeof(struct Node ));
		
		if(NewNode == NULL)
		{
			printf("\n !!!!!!! .... Memory allocation is failed ");
			return NULL;
		}
		
		printf("\n Enter the data for the %d Node : ",i+1);
		scanf("%d",&data);
		
		NewNode->data=data;
		NewNode->next=NULL;
		
		if(head == NULL )
		{
			head=NewNode;
		}
		
		else
		{
			NewNode->next=head;
			head=NewNode;
		}
	}
	
	return head;
}

int pushNode(struct Node **top)
{
	struct Node* NN;
	NN = (struct Node *)malloc(sizeof(struct Node));
	if(NN== NULL)
		return 0;
	
	else{
		
		int data;
		printf("\n Enter the data for the Node : ");
		scanf("%d",&data);
		NN->data=data;
		NN->next=NULL;
		
		NN->next=*top;
		*top=NN;
		return 1;
	}
}

int popNode(struct Node **top,int * val)
{
	if(*top==NULL)
		return  0;
	
	else
	{
		struct Node * tmp=*top;
		*top=tmp->next;
		*val=tmp->data;
		free(tmp);
		return 1;
	}
}

int peekData(struct Node * top,int *val,int index)
{
	int count=0;
	struct Node * curnode=top;
	
	while(curnode!=NULL)
	{
		if( count == index)
		{
			*val=curnode->data;
			return 1;
		}
		
		count++;
		curnode=curnode->next;
	}
	
	return -1;
}

int main()
{
	char mainCh;
	do
	{
		
	int mainChoice;
	printf("\n ################# You Are implementing the stack  ################# ");
	printf("\n 1. Stack using Array list ");
	printf("\n 2. Stack Using Linked-List\n");
	printf("\n Enter => \n What you want to use : ");
	scanf("%d",&mainChoice);
	
	switch(mainChoice)
	{
		case 1:{
			
			printf("\n <<< --------  You Are Implementing the Stack Uisng the Array List ------ >>>\n");
			int size;
			printf("\n Enter=>\n Size of Stack : ");
			scanf("%d",&size);
			
			int stack[size];
			int ele,i;
			
			printf("\n Enter => \n How many elements you want store currently in the linked list ? : ");
			scanf("%d",&ele);
			
			if(ele>size)
			{
				printf("\n Error : The No of elements is greater thean the size of the stack ");
				return 1;
			}
			
			if(ele>0)
				printf("\n Enter the %d elements in the stack : \n",ele);
			
			for(i=0;i<ele;i++)
			{
				scanf("%d",&stack[i]);
			}
			
			int top=ele-1;
			
			char ch1;
			printf("\n Do you want to perform any Operation on Stack ? (y/n) : ");
			fflush(stdin);
			scanf("%c",&ch1);
			
			int data,index,status,val;
			
			if(ch1=='y' || ch1=='Y')
			{
				char ch2;
				do
				{
					printf("\n~~~~~~~ You can perform following opeartions ~~~~~~~");
					printf("\n\t 1.Push");
					printf("\n\t 2.Pop");
					printf("\n\t 3.Peek");
					
					char choice;
					printf("\n Enter => \n Which opeartion you want to perform : ");
					scanf("%d",&choice);
					
					switch(choice)
					{
						case 1:
							printf("\n Enter => The Data you want to push : ");
							scanf("%d",&data);
							
							status=push(&top, size, data,stack);
							
							if(status==1){
								printf("\n\t\t *** SUCCESS ***");
								printf("\n\t\t The Data in Pushed in stack at Top position Successfully ");
							}
							else if(status == 0)
							{
								printf("\n\t\t !!! Fail !!!");
								printf("\n\t\t The Stack is Full We can't push ");
							}
							else
								printf("\n\t\t !!! Fail !!! ");
						printf("\n ================================================================================== ");
						break;
						
						case 2:
							status=pop(stack,&top,&val);
							
							if(status==1){
								printf("\n\t\t *** Success *** ");
								printf("\n\t\t The data is Retirved From Top Position of stack ");
								printf("\n\n\t <-- Retrived Data : %d -->",val);
							}
							
							else if(status == 0){
								printf("\n\t\t !!! Fail !!!");
								printf("\n\t\t The Stack is Empty , We can't Retirve the data");
							}
							
							else
								printf("\n \t\t !!! Fail !!! ");
								
						printf("\n ================================================================================== ");
						break;
						
						case 3:
							printf("\n\n Enter => \nThe Index you want to read the data : ");
							scanf("%d",&index);
							status=peek( stack, top, index,&val);
							
							if(status == 1)
							{
								printf("\n *** SUCCESS *** ");
								printf("\n The Data at Index %d is %d",index,val);
							}
							
							else
								printf("\n You Entered Invalid Index");
						
						printf("\n ================================================================================== ");
						break;
						
						default:
							printf("\n Invalid Choice ");
					}
					
					printf("\n Do you want to continue ?(y/n) : ");
					fflush(stdin);
					scanf("%c",&ch2);
					
				}while(ch2=='y'||ch2=='Y');
				
			}
			
		break;
		}
		
		case 2:
		{
			printf("\n <<< --------  You Are Implementing the Stack Uisng the Linked-List ------ >>>\n");
			
			struct Node * Top = NULL;
						
			int Nodes;
			printf("\n Enter => \nHow many nodes you want to ceate currently ? : ");
			scanf("%d",&Nodes);
			
			
			if(Nodes >0 )
			{
				printf("\n -------- Enter the data for the %d Nodes -----------",Nodes);
				Top=CreateNodes(Top,Nodes);
			}
			
			char choice;
			printf("\n Do you want to perform Any operations on Stack ? (y/n) : ");
			fflush(stdin);
			scanf("%c",&choice);
			
			int ch,status;
			char ch2;
			int val;
			int index;
			
			if(choice=='y' || choice=='Y')
			{
				do
				{
					printf("\n~~~~~~~ You can perform following opeartions ~~~~~~~");
					printf("\n\t 1.Push");
					printf("\n\t 2.Pop");
					printf("\n\t 3.Peek");
					
					printf("\n Enter =>\n which operation you want to perform ? : ");
					scanf("%d",&ch);
					
					switch(ch)
					{
						case 1:
						{
							status=pushNode(&Top);
							
							if(status == 1 )
							{
								printf("\n\t\t *** SUCCESS ***");
								printf("\n\t\t The Node is pushed Suceesfully in the stack ");
							}
							
							else if(status == 0)
							{
								printf("\n\t\t !!! FAIL !!! ");
								printf("\n\t\t The Memory allocation is failed for the Node");
							}
							
							else
								printf("\n FAIL ");
							
							printf("\n ==============================================================================================\n");
							
							break;
						}
						
						case 2:
						{
							
							status=popNode(&Top,&val);
							
							if(status == 1 )
							{
								printf("\n\t\t *** SUCCESS ***");
								printf("\n\t\t The Node is Retrived Suceesfully from  the stack ");
								printf("\n\t\t <<<---- The retrived data = %d --->>> ",val);
							}
							
							else if(status == 0)
							{
								printf("\n\t\t !!! FAIL !!! ");
								printf("\n\t\t The stack is empty we can't retirve the data form stack at top position ");
							}
							
							else
								printf("\n FAIL ");
							
							printf("\n ==============================================================================================\n");
							
							break;
						}
						
						case 3:
						{
							printf("\n Eneter => \n Index at which you want to read the data ");
							scanf("%d",&index);
							
							status=peekData(Top,&val,index);
							
							if(status == 1 )
							{
								printf("\n\t\t *** SUCCESS ***");
								printf("\n\t\t <<<---- The  data at %d index = %d --->>> ",index,val);
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
							
					}
					
					printf("\n Do you want to continue ? (y/n) : ");
					fflush(stdin);
					scanf("%c",&ch2);
				}while(ch2=='Y' || ch2=='y');
			}
			break;
		}
		
		default:
			printf("\n invalid Choice for Choosing the List type ");
	}
	
	printf("\n You Want to To Quit ?(y/n) : ");
	fflush(stdin);
	scanf("%c",&mainCh);
	
	}while(mainCh=='N'||mainCh=='n');
	
	printf("\n Thank You :) ");
	
	return 0;
}
