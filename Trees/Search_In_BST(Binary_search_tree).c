#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * right;
	struct Node * left;
};

struct Node * CreateNode(int *i)
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	
	if(ptr == NULL )
	{
		printf("\n Memory Allocation Failed !!! ");
		return NULL;
	}
	
	ptr->right=NULL;
	ptr->left=NULL;
	
	int data;
	printf("\n Enter the data for the %d Node : ",*i);
	scanf("%d",&data);
	
	ptr->data=data;
	
	return ptr;
}

void LinkingNodes(struct Node **Root,int n)
{
	if( n <= 0)
	{
		printf("\n No Nodes to Create ");
		return ;
	}
	
	int i;
	
	for(i=1;i<=n;i++)
	{
		struct Node * NewNode=CreateNode(&i);
		
		if(i==1)
		{
			*Root=NewNode;
			printf("\n The Root : %d ",(*Root)->data);
			continue ;
		}
		
		struct Node * current = *Root;
		
		while(1)
		{
			if(NewNode->data < current->data)
			{
				if(current->left == NULL )
				{
					current->left=NewNode;
					break;
				}
				else
					current=current->left;
			}
			
			else
			if(NewNode->data > current->data)
			{
				if(current->right == NULL )
				{
					current->right=NewNode;
					break;
				}
				else
					current=current->right;
			}
			
			else
			{
				printf("\nDuplicate value %d not allowed.\n", NewNode->data);
                free(NewNode);
                break;
            }
		}
	}
}

void printTree(struct Node* root, int space) {
    if (root == NULL) return;

    // Increase space between levels
    space += 5;

	int i;
    // Print right child first (for better visual alignment)
    printTree(root->right, space);

    // Print the current node after spacing
    printf("\n");
    for ( i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Print left child last
    printTree(root->left, space);
}

void InOrder(struct Node * Root )
{
	if(Root== NULL )
		return ;
	
	InOrder(Root->left);
	printf(" %d ",Root->data);
	InOrder(Root->right);
	
}

int Search(struct Node * Root , int target)
{
	if(Root == NULL )
		return -1;
	else
	if(Root->data==target)
		return 1;
	else
	if(Root->data > target )
		return Search(Root->left,target);
	else
	if(Root->data < target )
		return Search(Root->right,target);
}

int main()
{
	int n;
	printf("\n Enter How Many Nodes you Want :  ");
	scanf("%d",&n);
	
	struct Node * Root = NULL;
	LinkingNodes(&Root,n);
	printf("\n");
	
	printf("\n <<<<<===== The Tree ======>>>\n");
	printTree(Root,0);
	printf("\n");
	
	printf("\n The InOrder Traversal : ");
	InOrder(Root);
	printf("\n");
	
	char ch;
	int Nd;
	printf("\n Do You Want to search the data ?(y/n): ");
	fflush(stdin);
	scanf("%c",&ch);
	
	if(ch=='y' || ch=='Y')
	{
		printf("\n\t\t ENter how many elements you want to search : ");
		scanf("%d",&Nd);
		
		int i,target,status;
		
		for(i=1;i<=Nd;i++)
		{
			printf("\n\t\t Enter the %d target Element to Search : ",i);
			scanf("%d",&target);
				
			status=Search(Root,target);
			
			if(status==1)
				printf("\n\t\t\t----->>%d is found \n",target);
			else
				printf("\n\t\t\t----->>%d is not found \n",target);
		}
	}
	
	printf("\n thank You :) ");
	
	return 0;
}
