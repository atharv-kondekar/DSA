#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
		printf("\n Memory Allocation failed ");
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

void LinkingNodes(struct Node **Root,int n)
{
	if(n==1)	
	{
		printf("\n No Nodes to Create");
		return ;
	}
	
	int j=1;
	int i;
	
	for(i=0;i<n;i++)
	{
		struct Node * NewNode=CreateNode(&j);
		
		if(i==0)
		{
			*Root=NewNode;
			printf("\n The ROOT = %d \n",(*Root)->data);
			continue ;
		}
		
		struct Node * current = *Root;
		int ch;
		
		while(1)
		{
			printf("\n Enter which side you attach the Node 1.Left ,\n2.Right  : ");
			scanf("%d",&ch);
			
			if(ch==1)
			{
				if(current->left==NULL)
				{
					current->left=NewNode;
					printf("\n <<<<<<<<<<<<<------- The %d is attach left side of the %d ",NewNode->data,current->data);
					break;
				}
				
				else
					current=current->left;
			}
			
			else
			if(ch==2)
			{
				if(current->right==NULL)
				{
					current->right=NewNode;
					printf("\n <<<<<<<<<<<<<------- The %d is attach right side of the %d ",NewNode->data,current->data);
					break;
				}
				
				else
					current=current->right;
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

int Height(struct Node *Root,int *L,int *R)
{
	if(Root == NULL )
		return 0;
	
	int LeftHeight=Height(Root->left,L,R);
	int RightHeight=Height(Root->right,L,R);
	
	*L=LeftHeight;
	*R=RightHeight;
	
	return 1+( LeftHeight > RightHeight ?LeftHeight : RightHeight );
}

int main()
{
	int n;
	printf("\n Enter How many Ndoes yoou want ? : ");
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
	
	int height,L,R;
	
	height=Height(Root,&L,&R);
	
	printf("\n The Height Of the Tree is : %d ",height);
	
	int balanced = abs(L-R);
	
	if(balanced<=1)
	{
		printf("\n <<<<<<<<<<<< ======= The tree is balanced ====== >>>>>>>>>>>>>>");
	}
	else
		printf("\n<<<<<<<<<<<< ======= The tree is not balanced ====== >>>>>>>>>>>>>>");
		
	
	return 0;
}
