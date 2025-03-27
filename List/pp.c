/*#include<stdio.h>
struct product{
	int   productId;
	char  productName[20];
	float price;
	float gst;
};

int insert(struct product[],int ind,int *lpos,int size);
void shiftDown(struct product p[],int ind,int lpos);
void display( struct product p[],int lpos);
int deletion( struct product[],int ind ,int *lpos,int size);
int main()
{
	int size;
	printf("\n Enter the size of your product list : ");
	scanf("%d",&size);
	
	struct product p[size];
	int ele,i;
	printf("\n Enter the products you want to store in the list : ");
	scanf("%d",&ele);
	
	if( ele > size )
		printf("\n ERROR :  The Size of list is small for %d products ",ele);
		
	int lpos=ele-1;
	printf("\n Enter the %d elements in your list ",ele);
	printf("\n The GST on each rpoduct is 10%");
	for(i=0;i<ele;i++)
	{
		printf("\n Enter the Product id : ");
		scanf("%d",&p[i].productId);
		printf("\n Enter the Product Name : ");
		scanf("%s",p[i].productName);
		printf("\n Enter the Product Price : ");
		scanf("%f",&p[i].price);
		p[i].gst=( 0.10 * p[i].price);
		printf("\n----------------------------------------");
	}
	
	char choice1;
	printf("\n Do you want to perform any operations on product list ? (y/n):  ");
	fflush(stdin);
	scanf("%c",&choice1);
	
	if(choice1 == 'y' || choice1 == 'Y')
	{
		printf("\n Ypu can only perform following operations on list");
		printf("\n 1. Add Data in List ");
		printf("\n 2. Delete Data in List");
		int ind;
		
		int choice2;
		printf("\n Which operation you want to perform on list ?");
		scanf("%d",&choice2);
		
		switch( choice2 )
		{
			case 1:
				printf("\n Enter the index you want to store the data : ");
				scanf("%d",&ind);
				printf("\n Enter the Product id 		: ");
				scanf("%d",&p[ind].productId);
				printf("\n Enter the Product Name		: ");
				scanf("%s",p[ind].productName);
				printf("\n Enter the Product Price 		: ");
				scanf("%f",&p[ind].price);
				p[ind].gst=( 0.10 * p[ind].price);		
				
				if( insert(p,ind,&lpos,size) == 1 ){
					printf("\n The data entered successfully");
					display( p , lpos );
				}
				
				else
					printf("\n We can't insert the data at %d index",ind);
				
				break;
				
			case 2:
				printf("\n Enter the index you want to delete the data : ");
				scanf("%d",&ind);
				
				if( deletion( p , ind , &lpos, size) == 1 ){
					printf("\n The data deleted successfully");
					display( p , lpos );
				}
				else
					printf("\n We can't delete the data at %d index",ind);
				
				break;
			
			default:
				printf("\n Invalid Choice");
		}
	}
	
	else
		printf("\n Thank you :) ");
	
	return 0;
}	

int insert(struct product p[],int ind,int *lpos,int size)
{
	int i;
	i=ind;
	if(*lpos == -1)
	{
		if( ind == 0 )
		{
			p[ind]=p[i];
			(*lpos)++;
			return 1;
		}
		else
			return 0;
	}
	
	else 
	{
		if( *lpos < size-1 )
		{
			if( ind == *lpos+1 )
			{
				p[ind]=p[i];
				(*lpos)++;
				return 1;
			}
			
			else
			if( ind <= *lpos )
			{
				shiftDown( p , ind ,*lpos );
				//p[ind]=p[i];
				(*lpos)++;
				return 1;
			}
			
			else
				return 0;
		}
		
	}
}

void shiftDown(struct product p[],int ind,int lpos)
{
	int curpos=lpos;
	while( curpos >= ind)
	{
		p[curpos+1] = p[curpos];
		curpos--;
	}
	
	int i;
	for(i=lpos ;i>=ind ;i--)
	{
		p[i+1]=p[i];
	}

}

void display( struct product p[],int lpos)
{
	int i;
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t  The Updated Product List : ");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<=lpos;i++)
	{
		printf("\n  The Product id 		: %d",p[i].productId);
		printf("\n  The Product Name		: %s",p[i].productName);
		printf("\n  The Product Price 		 : %0.2f",p[i].price);
		printf("\n  The GST on[%d] Product is : %0.2f",i,p[i].gst);
		printf("\n ===================================================\n");
	}
}

int deletion( struct product p[],int ind ,int *lpos,int size)
{
	int i;
	
	if( *lpos == -1 || ind <0 || ind > *lpos)
		return 0;
		
	else if( *lpos < size )
	{
		for( i=ind ; i<=*lpos ; i++)
		{
			p[i] = p[i+1];
		}
		
		(*lpos)--;
		return 1;
	}
	
	else
		return 0;
}*/

/*
#include<stdio.h>

struct product {
    int   productId;
    char  productName[20];
    float price;
    float gst;
};

int insert(struct product[], int ind, int *lpos, int size);
void shiftDown(struct product p[], int ind, int lpos);
void display(struct product p[], int lpos);
int deletion(struct product[], int ind, int *lpos, int size);

int main() {
    int size;
    printf("\n Enter the size of your product list: ");
    scanf("%d", &size);

    struct product p[size];
    int ele, i;
    printf("\n Enter the products you want to store in the list: ");
    scanf("%d", &ele);

    if (ele > size)
        printf("\n ERROR: The Size of the list is too small for %d products.", ele);

    int lpos = ele - 1;
    printf("\n Enter the %d elements in your list ", ele);
    printf("\n The GST on each product is 10%%");
    for (i = 0; i < ele; i++) {
        printf("\n Enter the Product id: ");
        scanf("%d", &p[i].productId);
        printf("\n Enter the Product Name: ");
        scanf("%s", p[i].productName);
        printf("\n Enter the Product Price: ");
        scanf("%f", &p[i].price);
        p[i].gst = (0.10 * p[i].price);
        printf("\n----------------------------------------");
    }

    char choice1;
    printf("\n Do you want to perform any operations on the product list? (y/n):  ");
    fflush(stdin);
    scanf("%c", &choice1);

    if (choice1 == 'y' || choice1 == 'Y') {
        printf("\n You can only perform the following operations on the list");
        printf("\n 1. Add Data in List ");
        printf("\n 2. Delete Data from List");
        int ind;

        int choice2;
        printf("\n Which operation do you want to perform on the list?");
        scanf("%d", &choice2);

        switch (choice2) {
            case 1:
                printf("\n Enter the index where you want to store the data: ");
                scanf("%d", &ind);
                
                if (ind < 0 || ind > lpos + 1) {
                    printf("\n Invalid index for insertion.");
                    break;
                }

                struct product new_product;
                printf("\n Enter the Product id: ");
                scanf("%d", &new_product.productId);
                printf("\n Enter the Product Name: ");
                scanf("%s", new_product.productName);
                printf("\n Enter the Product Price: ");
                scanf("%f", &new_product.price);
                new_product.gst = (0.10 * new_product.price);

                if (insert(p, ind, &lpos, size) == 1) {
                    p[ind] = new_product;  // Assign new data after shifting
                    printf("\n The data was entered successfully");
                    display(p, lpos);
                } else {
                    printf("\n We can't insert the data at index %d", ind);
                }
                break;

            case 2:
                printf("\n Enter the index from which you want to delete the data: ");
                scanf("%d", &ind);

                if (deletion(p, ind, &lpos, size) == 1) {
                    printf("\n The data was deleted successfully");
                    display(p, lpos);
                } else {
                    printf("\n We can't delete the data at index %d", ind);
                }
                break;

            default:
                printf("\n Invalid Choice");
        }
    } else {
        printf("\n Thank you :) ");
    }

    return 0;
}

int insert(struct product p[], int ind, int *lpos, int size) {
    if (*lpos >= size - 1) {
        return 0;  // List is full
    }

    if (ind <= *lpos) {
        shiftDown(p, ind, *lpos);  // Shift elements to make space for the new one
    }

    (*lpos)++;  // Update last position
    return 1;
}

void shiftDown(struct product p[], int ind, int lpos) {
	int i;
    for ( i = lpos; i >= ind; i--) {
        p[i + 1] = p[i];  // Shift elements to the right
    }
}

void display(struct product p[], int lpos) {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t  The Updated Product List: ");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int i;
    for ( i = 0; i <= lpos; i++) {
        printf("\n  The Product id: %d", p[i].productId);
        printf("\n  The Product Name: %s", p[i].productName);
        printf("\n  The Product Price: %0.2f", p[i].price);
        printf("\n  The GST on [%d] Product is: %0.2f", i, p[i].gst);
        printf("\n ===================================================\n");
    }
}

int deletion(struct product p[], int ind, int *lpos, int size) {
    if (*lpos == -1 || ind < 0 || ind > *lpos) {
        return 0;  // Invalid index or empty list
    }

	int i;
    for ( i = ind; i < *lpos; i++) {
        p[i] = p[i + 1];  // Shift elements to the left
    }

    (*lpos)--;  // Update last position
    return 1;
}
*/
/*
#include<stdio.h>
struct product{
	int product_id;
	char product_name[20];
	float price;
	float gst;
};

int main()
{
	int size;
	printf("\n Enter the size of your list : ");
	scanf("%d",&size);
	
	struct product p[size];
	int i,ele;
	printf("\n How many products you want to add in your list ? : ");
	scanf("%d",&ele);
	
	printf("\n ****** The GST on each Product is 10% ****");
	printf("\n Enter the information on %d products ",ele);
	for(i=0;i<ele;i++)
	{
		printf("\n Enter the Product id 		: ");
		scanf("%d",&p[i].product_id);
		printf("\n Enter the product name 		: ");
		scanf("%s",p[i].product_name);
		printf("\n Enter the product price 		: ");
		scanf("%f",&p[i].price);
		p[i].gst=( 0.10 * p[i].price);
	}
	
	int lpos=ele-1;
	
	char choice1;
	printf("\n Do you want to perform any opearions on list ? (y/n) : ");
	fflush(stdin);
	scanf("%c",&choice1);
	
	if( choice1 == 'y' || choice1 == 'Y')
	{
		char choice2;
		do
		{
			printf("\n You can olny perform the following operations on list : ");
			printf(" \n    1. Add the Data ");
			printf(" \n    2. Delete the Data");
			
			int ind;
			int choice3;
			printf("\n Which opearation you want to perform on list ?");
			scanf("%d",&choice3);
			
			switch( choice3 )
			{
				case 1:
					{
						printf("\n Enter the index you want to insert the data  : ");
						scanf("%d",&ind);
						
						printf("\n Enter the product id 		: ");
						scanf("%d",&p[ind].product_id);
						printf("\n Enter the product name 		: ");
						scanf("%s",p[ind].product_name);
						printf("\n Enter the product price		: ");
						scanf("%f",&p[ind].price);
						p[ind].gst=( 0.10 * p[ind].price);
						
						if( insert( p , &lpos, ind , size) == 1)
							display( p , lpos);
						
						else
							printf("\n We can't store the at %d index",ele);
							
						break;
					}
				
				default:
					printf("\n Invalid Choice");
					
			}
			printf("\n Do want to perform any operation (y/n) : ");
			fflush(stdin);
			scanf("%c",&choice2);
		}while(choice2 == 'y' || choice2 == 'Y');
	}
	
	else
	{
		printf("\n Thank You :) ");
	}
}

int insert(struct product p[],int *lpos,int ind,int size)
{
	int i=ind;
	if( *lpos == -1)
	{
		if( ind == 0 )
		{
			p[ind]	= p[i];
			(*lpos)++;
			return 1;
		}
		else
			return 0;
	}
	
	if( *lpos < size-1 )
	{
		if( ind <= *lpos+1 )
		{
			shiftdown( p , *lpos , ind);
			(*lpos++);
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
	
}

void shiftdown(struct product p[],int lpos ,int ind)
{
	int curpos=lpos;
	while( curpos >= ind)
	{
		p[curpos+1]=p[curpos];
		curpos--;
	}
}

void display(struct product p[],int lpos)
{
	int i;
	printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n \t UPDATED LIST : ");
	printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	for(i=0;i<=lpos;i++)
	{
		printf("\n The product Id 	: %d",p[i].product_id);
		printf("\n The product name : %s",p[i].product_name);
		printf("\n The product price	: %f",p[i].price);
		printf("\n The product gst 	: %f",p[i].gst);
	}
}*/
/*
#include<stdio.h>

struct product {
    int product_id;
    char product_name[20];
    float price;
    float gst;
};

void shiftdown(struct product p[], int lpos, int ind);
int insert(struct product p[], int *lpos, int ind, int size);
void display(struct product p[], int lpos);

int main() {
    int size;
    printf("\n Enter the size of your list : ");
    scanf("%d", &size);

    struct product p[size];
    int i, ele;
    printf("\n How many products you want to add in your list? : ");
    scanf("%d", &ele);

    printf("\n ****** The GST on each Product is 10% ****");
    printf("\n Enter the information on %d products ", ele);
    for(i = 0; i < ele; i++) {
        printf("\n Enter the Product id: ");
        scanf("%d", &p[i].product_id);
        printf("\n Enter the product name: ");
        scanf("%s", p[i].product_name);
        printf("\n Enter the product price: ");
        scanf("%f", &p[i].price);
        p[i].gst = (0.10 * p[i].price);
    }

    int lpos = ele - 1;

    char choice1;
    printf("\n Do you want to perform any operations on the list? (y/n) : ");
    fflush(stdin);
    scanf("%c", &choice1);

    if(choice1 == 'y' || choice1 == 'Y') {
        char choice2;
        do {
            printf("\n You can only perform the following operations on the list: ");
            printf("\n    1. Add the Data ");
            printf("\n    2. Delete the Data");

            int ind;
            int choice3;
            printf("\n Which operation do you want to perform on the list? ");
            scanf("%d", &choice3);

            switch(choice3) {
                case 1: {
                    printf("\n Enter the index you want to insert the data at: ");
                    scanf("%d", &ind);

                    printf("\n Enter the product id: ");
                    scanf("%d", &p[ind].product_id);
                    printf("\n Enter the product name: ");
                    scanf("%s", p[ind].product_name);
                    printf("\n Enter the product price: ");
                    scanf("%f", &p[ind].price);
                    p[ind].gst = (0.10 * p[ind].price);

                    if(insert(p, &lpos, ind, size) == 1)
                        display(p, lpos);
                    else
                        printf("\n We can't store the data at index %d", ind);

                    break;
                }
                default:
                    printf("\n Invalid Choice");
            }
            printf("\n Do you want to perform any other operations? (y/n) : ");
            fflush(stdin);
            scanf("%c", &choice2);
        } while(choice2 == 'y' || choice2 == 'Y');
    } else {
        printf("\n Thank You :) ");
    }
    return 0;
}

int insert(struct product p[], int *lpos, int ind, int size) {
    if(*lpos < size - 1) {
        if(ind <= *lpos + 1) {
            shiftdown(p, *lpos, ind);
            (*lpos)++;
            return 1;
        } else
            return 0;
    } else
        return 0;
}

void shiftdown(struct product p[], int lpos, int ind) {
    int curpos = lpos;
    while(curpos >= ind) {
        p[curpos + 1] = p[curpos];
        curpos--;
    }
}

void display(struct product p[], int lpos) {
    int i;
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n \t UPDATED LIST : ");
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(i = 0; i <= lpos; i++) {
        printf("\n The product Id  : %d", p[i].product_id);
        printf("\n The product name : %s", p[i].product_name);
        printf("\n The product price : %f", p[i].price);
        printf("\n The product gst  : %f", p[i].gst);
    }
}
*/

#include<stdio.h>
struct product{
	int   productId;
	char  productName[20];
	float price;
	float gst;
};

int insert(struct product[],int ind,int *lpos,int size);
void shiftDown(struct product p[],int ind,int lpos);
void display( struct product p[],int lpos);
int deletion( struct product[],int ind ,int *lpos,int size);
int main()
{
	int size;
	printf("\n Enter the size of your product list : ");
	scanf("%d",&size);
	
	struct product p[size];
	int ele,i;
	printf("\n How many products you want to store in your list ?  : ");
	scanf("%d",&ele);
	
	if( ele > size )
		printf("\n ERROR :  The Size of list is small for %d products ",ele);
		
	int lpos=ele-1;
	printf("\n Enter the %d elements in your list ",ele);
	printf("\n The GST on each rpoduct is 10%");
	for(i=0;i<ele;i++)
	{
		printf("\n Enter the Product id : ");
		scanf("%d",&p[i].productId);
		printf("\n Enter the Product Name : ");
		scanf("%s",p[i].productName);
		printf("\n Enter the Product Price : ");
		scanf("%f",&p[i].price);
		p[i].gst=( 0.10 * p[i].price);
		printf("\n----------------------------------------");
	}
	
	char choice1;
	printf("\n Do you want to perform any operations on product list ? (y/n):  ");
	fflush(stdin);
	scanf("%c",&choice1);
	
	if(choice1 == 'y' || choice1 == 'Y')
	{
		printf("\n Ypu can only perform following operations on list");
		printf("\n 1. Add Data in List ");
		printf("\n 2. Delete Data in List");
		int ind;
		
		int choice2;
		printf("\n Which operation you want to perform on list ? :  ");
		scanf("%d",&choice2);
		
		switch( choice2 )
		{
			case 1:
				printf("\n Enter the index you want to store the data : ");
				scanf("%d",&ind);
				printf("\n Enter the Product id 		: ");
				scanf("%d",&p[ind].productId);
				printf("\n Enter the Product Name		: ");
				scanf("%s",p[ind].productName);
				printf("\n Enter the Product Price 		: ");
				scanf("%f",&p[ind].price);
				p[ind].gst=( 0.10 * p[ind].price);		
				
				if( insert(p,ind,&lpos,size) == 1 ){
					printf("\n The data entered successfully");
					display( p , lpos );
				}
				
				else
					printf("\n We can't insert the data at %d index",ind);
				
				break;
				
			case 2:
				printf("\n Enter the index you want to delete the data : ");
				scanf("%d",&ind);
				
				if( deletion( p , ind , &lpos, size) == 1 ){
					printf("\n The data deleted successfully");
					display( p , lpos );
				}
				else
					printf("\n We can't delete the data at %d index",ind);
				
				break;
			
			default:
				printf("\n Invalid Choice");
		}
	}
	
	else
		printf("\n Thank you :) ");
	
	return 0;
}	

int insert(struct product p[],int ind,int *lpos,int size)
{
	int i;
	i=ind;
	if(*lpos == -1)
	{
		if( ind == 0 )
		{
			p[ind]=p[i];
			(*lpos)++;
			return 1;
		}
		else
			return 0;
	}
	
	else 
	{
		if( *lpos < size-1 )
		{
			if( ind == *lpos+1 )
			{
				p[ind]=p[i];
				(*lpos)++;
				return 1;
			}
			
			else
			if( ind <= *lpos )
			{
				shiftDown( p , ind ,*lpos );
				// p[ind]=p[i];
				(*lpos)++;
				return 1;
			}
			
			else
				return 0;
		}
		
	}
}

void shiftDown(struct product p[],int ind,int lpos)
{
	int curpos=lpos;
	while( curpos >= ind)
	{
		p[curpos+1] = p[curpos];
		curpos--;
	}
	
	int i;
	for(i=lpos ;i>=ind ;i--)
	{
		p[i+1]=p[i];
	}

}

void display( struct product p[],int lpos)
{
	int i;
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t  The Updated Product List : ");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<=lpos;i++)
	{
		printf("\n  The Product id 		: %d",p[i].productId);
		printf("\n  The Product Name		: %s",p[i].productName);
		printf("\n  The Product Price 		 : %0.2f",p[i].price);
		printf("\n  The GST on[%d] Product is : %0.2f",i,p[i].gst);
		printf("\n ===================================================\n");
	}
}

int deletion( struct product p[],int ind ,int *lpos,int size)
{
	int i;
	
	if( *lpos == -1 || ind <0 || ind > *lpos)
		return 0;
		
	else if( *lpos < size )
	{
		for( i=ind ; i<=*lpos ; i++)
		{
			p[i] = p[i+1];
		}
		
		(*lpos)--;
		return 1;
	}
	
	else
		return 0;
}
