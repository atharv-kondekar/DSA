#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
	struct Node * pre;
};

struct Node * CreateNode()
{
	struct Node * tmp;
	tmp=(struct Node *)malloc(sizeof(struct Node));
	return tmp;
}

void initNode(struct Node * ptr)
{
	int data;
	printf("\n Enter the data for the node : ");
	scanf("%d",&data);
	
	ptr->data=data;
	ptr->next=NULL;
	ptr->pre=NULL;
}

void traversal(struct Node * ptr)
{
	struct Node * curnode=ptr;
	
	while(curnode != NULL )
	{
		printf("\n Doubly Linked-List[%p | %d | %p ]",curnode->pre,curnode->data,curnode->next);
		curnode=curnode->next;
	}
	printf("\n ================================================================================\n\n");
}

void reversetraversal(struct Node * ptr)
{
	struct Node * curnode=ptr;
	
	while(curnode != NULL )
	{
		printf("\n Doubly Linked-List[%p | %d | %p ]",curnode->pre,curnode->data,curnode->next);
		curnode=curnode->pre;
	}
	printf("\n ================================================================================\n\n");
}

int main()
{
	struct Node * Head = NULL;
	struct Node * Tail = NULL;
	struct Node * first;
	struct Node * second;
	struct Node * third;
	struct Node * fourth;
	
	first=CreateNode();
	initNode(first);
	second=CreateNode();
	initNode(second);
	third=CreateNode();
	initNode(third);
	fourth=CreateNode();
	initNode(fourth);
	
	first->next=second;
	second->pre=first;
	
	second->next=third;
	third->pre=second;
	
	third->next=fourth;
	fourth->pre=third;
	
	Head=first;
	Tail=fourth;
	
	
	traversal(Head);
	reversetraversal(Tail);
}
