#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

void traversal(struct Node * Head)
{
	int i=0;

	while(Head != NULL)
	{
		printf("\n Node[ %d | next] = %d\n",i,Head->data);
		printf(" \t     | ");
		Head=Head->next;
		i++;
	}
	printf("\n \t    NULL");
	printf("\n =========================================== \n");
}

struct Node * InsertatFrist(struct Node * Head,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	
	ptr->next=Head;
	ptr->data=data;
	
	return ptr;
}

int main()
{
	int n;
	printf("\n Enter the Nodes you want : ");
	scanf("%d",&n);
	
	struct Node * ptr[n];
	ptr[0]=NULL;
	int i;
	
	for(i=0;i<n;i++)
	{
		ptr[i]=(struct Node *)malloc( sizeof(struct Node) );
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n Enter the data of the %d Node : ",i+1);
		scanf("%d",&ptr[i]->data);
		
		if( i == n-1 )
			ptr[i]->next=NULL;
		else
			ptr[i]->next=ptr[i+1];
	}
	
	char choice;
	printf("\n Do you want to insert the data ? : ");
	fflush(stdin);
	scanf("%c",&choice);
	
	if( choice == 'Y' || choice== 'y')
	{
		int data,index;
		//printf("\n Enter the index you want to insert : ");
		//scanf("%d",&index);
		printf("\n Enter the data you want to insert : ");
		scanf("%d",&data);
		
		struct Node * temp = ptr[0];
		temp = InsertatFrist( temp  , data );
		traversal(temp);
	}
	
	return 0;
}
