#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * CreateNode()
{
	struct Node * t;
	t=(struct Node *)malloc(sizeof(struct Node));
	return t;
}

void initNode(struct Node * nn)
{
	int val;
	printf("\n Enter the value : ");
	scanf("%d",&val);
	
	nn->data=val;
	nn->next=NULL;
}

void insert(struct Node ** head,struct Node * nn)
{
	struct Node * temp;
	
	if( *head == NULL )
	{
		*head=nn;
		nn->next=NULL;
	}
	else{
		temp=*head;
		nn->next=temp;
		*head=nn;
	}
}

void traversal(struct Node * ptr)
{
	while(ptr != NULL )
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	struct Node * Head = NULL;
	struct Node * tmp;
	
	tmp=CreateNode();
	initNode(tmp);
	
	insert(&Head,tmp);
	traversal(Head);
	
	return 0;
}
