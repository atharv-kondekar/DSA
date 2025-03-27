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
	ptr=(struct Node *)malloc(sizeof(struct Node ));
	
	if( ptr == NULL )
	{
		printf("\n Memory Allocation Failed ");
		return NULL;
	}
	ptr->left=NULL;
	ptr->right=NULL;
	
	int data;
	printf("\n Enter the data for the node ");
	scanf("%d",&data);
	
	ptr->data=data;
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
/*	struct Node * Root = CreateNode();
	struct Node * Second = CreateNode();
	struct Node * Third = CerateNode();
	struct Node * Fourth =  CreateNode();
	struct Node * Fifth = CreateNode();
	struct Node * Sixth = CreatenNode();
	struct Node * Seventh = Createnode
*/
	int n;
	printf("\n Enter how many nodes you want : ");
	scanf("%d",&n);
	
	struct Node * Root;
	int i;
	for(i=0;i<n;i++)
	{
		struct Node * NewNode = CreateNode();
		
		if( i == 0 )
		{
			printf("\n Root is : %d\n",NewNode->data);
			Root = NewNode;
			continue ;
		}
		
		struct Node * current = Root;
		while(1)
		{
			if(i>0)
			{
		
				int ch;
				printf("\n Where to insert %d ?  1.Left , 2.Right ",NewNode->data);
				scanf("%d",&ch);
		
				if(ch == 1 )
				{
					if( current->left  == NULL )
					{
						current->left=NewNode;
						printf("  ============= >>>>>>> Inserted %d to the left of %d.\n", NewNode->data, current->data);
						break ;
					}
				
					else
					{
						current=current->left;
					}
				}
				
				else if( ch == 2)
				{
					if( current->right == NULL )
					{
						current->right=NewNode;
						printf("  ============= >>>>>>>  Inserted %d to the right of %d.\n", NewNode->data, current->data);
						break ;
					}
					
					else
					{
						current = current->right;
					}
				}
				
				else
				{
					printf("\n Invalid Choice ");
				}
			}
		}
	}
		
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
