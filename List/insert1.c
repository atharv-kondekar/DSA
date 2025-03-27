/*
#include<stdio.h>
int insert(int list[],int size,int data,int pos, int *lpos)
{
	if(*lpos==-1)
	{
		if(pos==0)
		{
			list[pos]=data;
			*lpos++;
		}
		
		else
		{
			return 0;
		}
	}
	
	else
	{
		if(*lpos<size-1)
		{
			if(*lpos+1==pos)
			{
				list[pos]=data;
				*lpos++;
			}
			
			else
			{
				shiftDown(list,pos,*lpos);
				list[pos]=data;
				*lpos++;
			}
		}
		
		else
		{
			return 0;
		}
	}
}

void shiftDown(int list[],int pos,int *lpos)
{
	int curpos=*lpos;
	
	while(curpos>=pos)
	{
		list[curpos+1]=list[curpos];
		curpos--;
	}
}
int main()
{
	int list[100]={10,20,30,40};
	int size=100;
	int lpos=3;
	
	int data;
	printf("\n Enter the data : ");
	scanf("%d",&data);
	
	int pos;
	printf("\n Enter the position Do want to store the data : ");
	scanf("%d",&pos);
	
	int in=insert(list,size,data,pos,&lpos);
	
	if(in==0)
	{
		printf("\n We can't store the data at %d position",pos);
	}
	
	else
	{
		int i;
		
		printf("\n The Updated list : ");
		for(i=0;i<=lpos;i++)
		{
			printf("\n List[%d]=%d",i,list[i]);
		}
		
		printf("\n The data at %d position stored successfully",pos);
	}
	
	return 0;
}*/

#include<stdio.h>

void shiftDown(int lis[], int pos, int lpos) {
    int curpos = lpos;
    
    // Shift elements to the right
    while (curpos >= pos) {
        lis[curpos + 1] = lis[curpos];
        curpos--;
    }
}

int insert(int lis[], int pos, int data, int *lpos, int size) {
    if (*lpos == -1) {
        if (pos == 0) {
            lis[pos] = data;
            *lpos = 0;
            return 1;
        } else {
            return 0;
        }
    } else {
        if (*lpos < size - 1)
		 {
        	
            if (pos == *lpos + 1) 
			{
                lis[pos] = data;
                *lpos += 1;
                return 1;
            } 
			else if (pos <= *lpos)
			 {
                shiftDown(lis, pos, *lpos);
                lis[pos] = data;
                *lpos += 1;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0; // No space to insert
        }
    }
}

int main() {
    int list[100] = {10, 20, 30, 40}; // Initial array
    int pos;
    int lpos = 3; // Last position filled (3 because we have 4 elements: 0, 1, 2, 3)
    int size = 100;

    printf("\nEnter the position where you want to store the data: ");
    scanf("%d", &pos);

    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);

    int in;
    in = insert(list, pos, data, &lpos, size);

    if (in == 0) {
        printf("\nWe can't store the data at position %d", pos);
        
    } else {
        printf("\nData inserted successfully at position %d", pos);
        printf("\nUpdated list: ");
        int i;
        for ( i = 0; i <= lpos; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }

    return 0;
}

