#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * right;
	struct Node * left;
};

struct Node * CreateNode(int i)
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	if( ptr == NULL )
	{
		printf("\n The Memomory allocation Failed !!! ");
		return NULL;
	}
	ptr->right=NULL;
	ptr->left=NULL;
	
	int data;
	printf("\n Enter the data for the %d Node : ",i);
	scanf("%d",&data);
	
	ptr->data=data;
	
	return ptr;
}

void LinkingNodes(struct Node **Root,int n)
{
	if(n==0)
	{
		printf("\n No Nodes to create ");
		return ;
	}
	
	int i;
	for(i=1;i<=n;i++)
	{
		struct Node * NewNode = CreateNode(i);
		
		if( i == 1 )
		{
			*Root=NewNode;
			printf("\n The Root : = %d \n",(*Root)->data);
			continue ;
		}
		
		struct Node * current =*Root;
		
		while(1)
		{
			if(NewNode->data < current->data )
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
					current->right = NewNode;
					break;
				}
				else
					current=current->right;
			}
			
			else
			{
				printf("\n The Duplicate Values Not Allowed ");
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

void preOrderTraversal(struct Node * Root)
{
	
	if( Root == NULL )
		return ;
	
	printf(" %d ",Root->data);
	preOrderTraversal(Root->left);
	preOrderTraversal(Root->right);
}

void postOrderTraversal(struct Node * root )
{
	if( root == NULL )
		return ;
	
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf(" %d ",root->data);
}

void inOrderTraversal(struct Node * root )
{
	if( root == NULL )
		return ;
	
	inOrderTraversal(root->left);
	printf(" %d ",root->data);
	inOrderTraversal(root->right);
	
}

struct Node * BSTInsert(struct Node *Root,struct Node * NewNode)
{
	struct Node  * current = Root ;
	
	if( current == NULL )
	{
		return ;
	}
	
	else
	{
		if( current->data > NewNode->data )
		{
			if(current->left == NULL )
			{
				current->left=NewNode;
				return ;
			}
			
			else
				return BSTInsert(current->left,NewNode);
		}
		else
		if( current->data < NewNode->data  )
		{
			if(current->right == NULL )
			{
				current->right=NewNode;
				return ;
			}
			
			else
				return BSTInsert(current->right,NewNode);
		}
		
		else
		{
			printf("\n Duplicate values not allowed ");
			free(NewNode);
			return NULL;
		}
	}
}

void insert(struct Node ** Root )
{
	int Nodes;
	printf("\n Enter how mnay Nodes you want to Insert : ");
	scanf("%d",&Nodes);
	
	if( Nodes <= 0 )
	{
		printf("\n No Nodes to insert  ");
		return ;
	}
	
	
	printf("\n Enter the data for the Nodes for the Insertion \n ");
	int i;
	for(i=1;i<=Nodes;i++)
	{
		
		struct Node * NewNode = CreateNode(i);
		*Root= BSTInsert( *Root,NewNode);
	}
}


int main()
{
	int n;
	printf("\n ENter How many Nodes you want ? : ")	;
	scanf("%d",&n);
	
	struct Node * Root = NULL;
	
	LinkingNodes(&Root,n);
	printf("\n\n<<<<<<<<============ The Tree  =========== >>>>>>>>> \n");
	
	printTree(Root,0);
	printf("\n ");
	
	printf("\n The Preorder Traversal   : ");
	preOrderTraversal(Root);
	
	printf("\n ");
	
	printf("\n The Post order Traversal : ");
	postOrderTraversal(Root);
	
	printf("\n ");

	printf("\n The  In order Traversal  : ");
	inOrderTraversal(Root);
	
	
	insert(&Root);
	printf("\n\n<<<<<<<<============ The Tree After Insertion  =========== >>>>>>>>> \n");
	
	printTree(Root,0);
	printf("\n ");
	
	
	return 0;
}
