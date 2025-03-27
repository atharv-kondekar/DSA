#include<stdio.h>

// Function to shift elements up after deletion
void shiftUp(int list[], int *ele, int d_ind) {
	int i;
    for ( i = d_ind; i < *ele - 1; i++) {
        list[i] = list[i + 1];
    }
    (*ele)--;  // Decrease the number of elements after shifting
}

// Function to handle deletion of an element
int deletion(int list[], int d_ind, int size, int *ele, int *lpos) {
    if (*lpos == -1 || d_ind < 0 || d_ind >= *ele) {
        return 0; // Invalid index or empty list
    }

    if (*lpos < size) {
        shiftUp(list, ele, d_ind);
        (*lpos)--;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    printf("\n Enter the size of an array: ");
    scanf("%d", &n);

    int list[n], i, ele;
    printf("\n How many elements do you want to store in the list: ");
    scanf("%d", &ele);

    if (ele > n) {
        printf("\n Error: Number of elements cannot exceed array size.\n");
        return 1;
    }

    printf("\n Enter the %d elements: ", ele);
    for (i = 0; i < ele; i++) {
        scanf("%d", &list[i]);
    }

    char ch;
    printf("\n Do you want to delete something? (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        int d_ind;
        printf("\n Enter the index of the element you want to delete: ");
        scanf("%d", &d_ind);

        int lpos = ele - 1;
        int size = n;

        int check = deletion(list, d_ind, size, &ele, &lpos);

        if (check == 1) {
            printf("\n Deleted Successfully");
            printf("\n The updated list: ");
            for (i = 0; i < ele; i++) {
                printf("\n List[%d] = %d", i, list[i]);
            }
        } else {
            printf("\n We can't delete the data. Invalid index or operation.");
        }
    } else {
        printf("\n No Operations on the list");
    }

    return 0;
}

// Code 2

#include<stdio.h>
void shiftUp(int list[],int *ele,int d_ind)
{
	int i;
	
	for(i=d_ind ; i < *ele-1 ; i++)
	{
		list[i]	= list[i+1];
	}
	(*ele)--;
}

int deletion(int list[],int d_ind,int size,int *ele,int *lpos)
{
	if( *lpos == -1 || d_ind < 0 || d_ind >= *ele )
	{
		return 0;
	}
	
	if( *lpos < size )
	{
			shiftUp(list,ele,d_ind);
			(*lpos)--;
			return 1;
	}
		
	else
	{
		return 0;
	}
	
}
int main()
{
	int n;
	printf("\n Enter the size of an array : ");
	scanf("%d",&n);
	
	int list[n],i,ele;
	printf("\n How many elements you want to store in list : ");
	scanf("%d",&ele);
	
	printf("\n Enter the %d elements : ",ele);
	for(i=0;i<ele;i++)
	{
		scanf("%d",&list[i]);
	}
	
	char ch;
	printf("\n Do you want to delete something ? (y/n) : ");
	scanf(" %c",&ch);
	
	if(ch == 'y' || ch == 'Y')
	{
		int d_ind;
		printf("\n Enter the index do you want to delete : ")	;
		scanf("%d",&d_ind);
		
		int lpos=ele-1;
		int size=n;
		
		int check;
		check=deletion(list,d_ind,size,&ele,&lpos);
		
		if( check == 1)
		{
			printf("\n Deleted Successfully  ");
			printf("\n The updated list : ");
			for(i=0;i< ele ;i++)
			{
				printf("\n List [%d] = %d",i,list[i]);
			}
		}
		
		else
		{
			printf("\n We can't delete the data");
		}
	}
	
	else
	{
		printf("\n No Operations on list ");
	}
	
	return 0;
}
