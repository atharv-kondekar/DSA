/*

Comparison of Code 1 vs. Code 2
1. User Input Handling and Flexibility
Code 1:

Requires users to input node data in a rigid sequence (predefined nodes created in main()).
Limited flexibility: It constructs only a fixed, 7-node tree manually.
Code 2:

Provides more dynamic input handling, allowing users to create any number of nodes.
The LinkingNodes() function gives the user control over where to attach nodes (left or right), making it more interactive and adaptable.
Advantage: Code 2 is better for real-world scenarios since it offers more flexibility.

2. Reusability and Scalability
Code 1:
The structure is hard-coded, so expanding the tree requires writing additional CreateNode() calls in main() and setting up connections manually.
Code 2:
The LinkingNodes() function provides a modular way to build any size of tree without changing much in the code.
More scalable: If placement interviews ask you to create large or complex trees, Code 2 will adapt more easily.
Advantage: Code 2 offers reusability and scalability.

3. Code Modularity and Design
Code 1:
Less modular: The node creation and linking logic are embedded directly in main(). Modifying tree connections later would require manual changes.
Code 2:
More modular design: The CreateNode() and LinkingNodes() functions separate concerns well (creation vs. linking), adhering to good coding practices.
Advantage: Code 2 aligns better with modular design principles.

4. Placement-Oriented Usability
In placement scenarios, the ability to explain concepts like dynamic node insertion, modularity, and user input handling is often valued more than hardcoding examples.

Code 2 demonstrates:

User-driven tree creation (which shows flexibility).
Modularity and separation of concerns (good software design).
Better handling of dynamic data structures.
Advantage: Code 2 shows practical thinking and adaptability—qualities interviewers look for in placements.

5. Error Handling and Code Robustness
Both codes have basic memory allocation checks, but Code 2 handles dynamic input better by looping through the number of nodes and linking them interactively.
Conclusion
For placement purposes, Code 2 is better because it:

Demonstrates more flexibility, modularity, and scalable design.
Allows for dynamic user input, which reflects real-world coding practices.
Shows better separation of concerns, which is crucial in interviews to convey good coding principles.
If asked to present or explain one of the codes in an interview, Code 2 will reflect better problem-solving skills and adaptability—qualities that interviewers often look for.


*/






// code 1:
	
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
/*
code 2:
	
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
}*/
