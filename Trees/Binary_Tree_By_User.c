#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * CreateNode()
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	if(ptr==NULL)
	{
		printf("\n Memory Allocation Failed !!");
		return NULL;
	}
	ptr->left=NULL;
	ptr->right=NULL;
	
	int data;
	printf("\n Enter the Data for the Node : ");
	scanf("%d",&data);
	ptr->data=data;
	
	return ptr;
}

void LinkingNodes(struct Node **Root , int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		struct Node * NewNode = CreateNode();
		
		if( i == 0)
		{
			*Root = NewNode;
			printf("\n The Root is :  %d",(*Root)->data);
			continue ;
		}
		
		struct Node * Current = *Root;
		
		while(1)		
		{
		
			int ch;
			printf("\n Which Side you want to attach the node ? \n1.Left \n2.Right ");
			scanf("%d",&ch);
		
			if( ch==1 )
			{
				if(Current->left == NULL )
				{
					Current->left=NewNode;
					printf("\n The %d is attached to the left of the %d",NewNode->data,Current->data);
					break;
				}
				else
				{
					Current = Current->left;
				}
			}
		
			else 
			if(ch==2)
			{
				if( Current->right == NULL )
				{
					Current->right=NewNode;
					printf("\n The %d is attached to the right of the %d",NewNode->data,Current->data);
					break;
				}
				else
				{
					Current = Current->right;
				}
			}
			
			else
				printf("\n Invalid Choice ");
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
	
	postOrderTraversal(root->left);
	printf(" %d ",root->data);
	postOrderTraversal(root->right);
	
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
	
	return 0;
}
