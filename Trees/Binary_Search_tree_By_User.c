#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * right;
	struct Node * left;
};

struct Node * CreateNode()
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	
	if(ptr == NULL )
	{
		printf("\n Memory Allocation Failed !!!! ");
		return NULL;
	}
	
	ptr->left=NULL;
	ptr->right=NULL;
	
	int data;
	printf("\n Enter the data for the Node : ");
	scanf("%d",&data);
	
	ptr->data=data;
	
	return ptr;
}

void LinkingNodes(struct Node **Root , int N )
{
	
	if (N <= 0) 
	{
        printf("\nNo nodes to create.\n");
        return;
    }
    
	int i;
	for(i=0;i<N;i++)
	{
		struct Node * NewNode = CreateNode();
		
		if( i == 0 )
		{
			*Root = NewNode;
			printf("\n The Root is : %d",(*Root)->data);
			continue ;
		}
		
		struct Node * Current = *Root;
	
		while(1)
		{
			if(NewNode->data < Current->data )		
			{
				if(Current->left == NULL )
				{
					Current->left=NewNode;
					break;
				}
				
				else
					Current=Current->left;
			}
			
			else
			if( NewNode->data > Current->data )
			{
				if(Current->right == NULL )
				{
					Current->right=NewNode;
					break ;
				}
				else
					Current= Current->right;
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

void PreOrderTraversal(struct Node * Root )
{
	if(Root == NULL )
		return ;
	
	printf(" %d ",Root->data);
	PreOrderTraversal(Root->left);
	PreOrderTraversal(Root->right);
}

void PostOrder(struct Node * Root )
{
	if(Root == NULL )
		return ;
	
	PostOrder(Root->left);
	PostOrder(Root->right);
	printf(" %d ",Root->data);
}

void InOrder(struct Node * Root )
{
	if(Root== NULL )
		return ;
	
	InOrder(Root->left);
	printf(" %d ",Root->data);
	InOrder(Root->right);
	
}

int  main()
{
	struct Node * Root = NULL ;
	
	int N;
	printf("\nEnter =>  How Many Nodes you want ? : ");
	scanf("%d",&N);
	
	LinkingNodes(&Root,N);
	
	if (Root == NULL) 
	{
        printf("\nTree is empty. Exiting.\n");
        return 0;
    }
    
	printf("\n");
	printTree(Root,0);
	printf("\n");
	
	printf("\n The Preorder Traversal   : ");
	PreOrderTraversal( Root );
	
	printf("\n");
	
	printf("\n The Post order Traversal : ");
	PostOrder( Root );
	
	printf("\n");
	
	printf("\n The  In order Traversal  : ");
	InOrder( Root );
	
	
	return 0;
	
}
