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
	if(ptr== NULL)
	{
		printf("\n Memory Allocation Failed");
		return NULL;
	}
	ptr->left=NULL;
	ptr->right=NULL;
	
	int data;
	printf("\n Enter the data for the %d Node : ",*i);
	scanf("%d",&data);
	(*i)++;
	
	ptr->data=data;
	return ptr;
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
	int i=1;
	struct Node * Root   = CreateNode(&i);
	struct Node * Second = CreateNode(&i);
	struct Node * Third  = CreateNode(&i);
	struct Node * Fourth = CreateNode(&i);
	struct Node * Fifth  = CreateNode(&i);
	struct Node * Sixth  = CreateNode(&i);
	struct Node * Seventh= CreateNode(&i);
	
	Root->left=Second;
	Root->right=Third;
	
	Second->left=Fourth;
	Second->right=Fifth;
	
	Third->left=Sixth;
	Third->right=Seventh;
	
	
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



