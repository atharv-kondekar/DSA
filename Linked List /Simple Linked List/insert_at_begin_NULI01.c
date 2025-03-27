
********************* giving this run timr error ***********************



/*
1) Start 
2) Check if list is empty 
3) Yes :-
		1. make the new node as head node 
		2. Make the new node next null
		3. return 
4) No :-
		1. Take the frist node 
		2. Assign frist node as new node next
		3. Make the head node as new node
		4. return 
5) Stop
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data ;
	struct Node * next;
};

struct Node * createNode()
{
	struct Node * t;
	t=(struct Node *)malloc(sizeof(struct Node));
	return t;
}

void initnode(struct Node * t)
{
	int val;
	printf("\n Enter the Value of node : ");
	scanf("%d",&val);
	
	t->data=val;
	t->next=NULL;
}

void traversal(struct Node * head)
{
	struct Node * curnode=head;
	int i=1;
	while(curnode != NULL)
	{
		printf("\n List [ %d | next ] = %d",i,curnode->data);
		printf("\n\t\t | ");
		curnode=curnode->next;
		i++;
	}
}


struct Node * insert(struct Node * nn,struct Node **head )
{
	struct Node * tmp;
	
	if( *head == NULL )
	{
		*head=nn;
		nn->next=NULL;
		return *head;
	}
	
	else
	{
		tmp = *head;
		nn->next=tmp;
		*head=nn;
		return *head;
	}
}

int main()
{
	struct Node * Head = NULL;
	struct Node * temp;
	
	int n;
	printf("\n Enter the Nodes you want : ");
	scanf("%d",&n);
	
	int i;
	int j=1;
	for(i=0;i<n;i++)
	{
		temp=createNode();
		initnode(temp);
		Head=insert(temp,&Head);
	}
	
	Head = temp;
	
	struct Node * nn;
	nn=createNode();
	initnode(nn);
	
	insert(nn,&Head);
	traversal(Head);
	
	return 0;
}
