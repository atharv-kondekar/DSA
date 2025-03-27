#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * CreateNode(int *i)
{
	struct Node * ptr;
	ptr=(struct Node *)malloc(sizeof(struct Node));
	if(ptr==NULL)
	{
		printf("\n Memory allocation failed !!!! ");
		return NULL;
	}
	
	ptr->left=NULL;
	ptr->right=NULL;
	
	int data;
	printf("\n Enter the data for the %d Node ",(*i));
	scanf("%d",&data);
	
	ptr->data=data;
	
	return ptr;
}

void LinkingNodes(struct Node **Root,int n)
{
	if(n==0)
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
			printf("\n The Root of the tree is %d",(*Root)->data);
			continue ;
		}
		
		struct Node * current = *Root;
		
		while(1)
		{
			if(NewNode->data < current->data)
			{
				if(current->left  == NULL )
				{
					current->left=NewNode;
					break;
				}
				
				else
					current=current->left;
			}
			
			else
			if(NewNode->data > current->data )
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
				printf("\n No Duplicate values Allowed ");
				free(NewNode);
				break ;
			}
		}
	}
}

int findMin(struct Node * Root )
{
	if(Root!=NULL)	
	{
		if(Root->left != NULL )
			return findMin(Root->left);
			
		else
			return Root->data;
	}
	
	else
		return 0;
}

int findMax(struct Node * Root )
{
	if(Root != NULL )
	{
		if(Root->right != NULL)
			return findMax(Root->right);
		else
			return Root->data;
	}
	
	else
		return 0;
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
	
	
	printf("\n\n\n\n The Minimum value in the Tree : %d ",findMin(Root));
	printf("\n The Maximum Value in the Tree : %d",findMax(Root));
	
	
	return 0;
}
