#include<stdio.h>
#include<stdlib.h>

struct myArray {
	int total_size;
	int used_size;
	int * ptr;
};

void createarray(struct myArray * a,int t_Size,int U_size)
{
	/*(*a). = t_Size
	(*a).used_size  = U_size*/
	(*a).ptr = (int *)malloc(t_Size * sizeof (int) );
}

int main()
{
	struct myArray marks;
	int tsize,usize;
	printf("\n enter the total size you want for array : ");
	scanf("%d",&tsize);
	printf("\n Enter the Size for your usages : ");
	scanf("%d",&usize);
	
	createarray(&marks,tsize,usize);
	
	int i;
	int n;
	printf("\n Enter the values in an array : ");
	for(i=0;i<usize;i++)
	{
		printf("\n enter the %d element: ",i);
		scanf("%d",&n);
		marks.ptr[i]=n;
	}
	
	printf("\n Displaying the array : \n");
	for(i=0;i<usize;i++)
	{
		printf("\n %d",marks.ptr[i]);
	}
	
	return 0;
}

