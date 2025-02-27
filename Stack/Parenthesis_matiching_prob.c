#include<stdio.h>
#include<string.h>

void push(char stack[],int *top,char c,int size)
{
	if(*top == size-1 )
	{	
		printf("\n The Stack is Overflow");
		return ;
	}
	
	else
	{
		(*top)++;
		stack[*top]=c;
		return ;
	}
}

char pop(char stack[],int *top)
{
	if( *top == -1)	
	{
		printf("\n The stack is underflow ");
		return  '\0';
	}
	
	else
	{
		char tmp;
		tmp=stack[*top];
		(*top)--;
		return tmp;
	}
}

int parenthesisMathcing(char stg[],int size)
{
	char stack[size];
	int top=-1;
	
	int i;
	
	for(i=0;stg[i]!='\0';i++)
	{
		if(stg[i] == '(' )
		{
			push(stg,&top,'(',size);
		}
		
		else
		if(stg[i]==')')
		{
			if( top == -1 )
			{
				return 0;
			}
			
			pop(stack,&top);
		}
	}
	
	if( top == -1 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char stg[100];
	printf("\n Enter your Expression : ");
	gets(stg);
	
	int size=strlen(stg);
	
	int status=parenthesisMathcing(stg,size);
	
	if(status==1)
	{
		printf("\n BALANCED EXPRESSION ");
	}
	
	else
	{
		printf("\n UN-BALANCED EXPRESSION");
	}
	
	return 0;
}
