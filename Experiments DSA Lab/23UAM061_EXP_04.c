#include<stdio.h>
struct product{
	int   productId;
	char  productName[20];
	float price;
	float gst;
};

int    insert      ( struct product [],int ,int *,int );
void   shiftDown   ( struct product [],int ,int );
void   display     ( struct product [],int );
int    deletion    ( struct product [],int  ,int *,int );
int    linearsearch( struct product [],int ,int );
int    sorted      ( struct product [],int );
int    BinarySearch( struct product [],int , int  );
void   WriteFile   ( struct product [],int *,FILE * );
void   ReadFile    ( struct product [],FILE *,int );

int main()
{
	
	FILE *Product;
	 
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
	printf("\n ..........................................................\n");
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
	
		char choice3;
		do{
				printf("\n You can only perform following operations on list");
				printf("\n\t 1. Add Data in List ");
				printf("\n\t 2. Delete Data in List");
				printf("\n\t 3. Traverse The List ");
				printf("\n\t 4. Search the data");
				printf("\n\t 5. Write the data in HD using FILE");
				printf("\n\t 6. Read File");
			
				
				int ind;  
				int sElement;
				int index;
		
			int choice2;
			printf("\n Which operation you want to perform on list ? :  ");
			scanf("%d",&choice2);
		
			switch( choice2 )
			{
				case 1:{
					printf("\n Enter the index you want to store the data : ");
					scanf("%d",&ind);
					struct product new_product;
					printf("\n Enter the Product id 		: ");
					scanf("%d",&new_product.productId);
					printf("\n Enter the Product Name		: ");
					scanf("%s",new_product.productName);
					printf("\n Enter the Product Price 		: ");
					scanf("%f",&new_product.price);
					new_product.gst=( 0.10 * new_product.price);		
					if( ind> lpos+1 || ind<0 || ind > size  )
						printf("\n ERROR : INVALID INDEX");
					
					else
					if( insert(p,ind,&lpos,size) == 1 ){
						p[ind]=new_product;
						printf("\n The data entered successfully");
						display( p , lpos );
					}
				
					else
						printf("\n We can't insert the data at %d index",ind);
				
					break;
				}
				
				case 2:{
					printf("\n Enter the index you want to delete the data : ");
					scanf("%d",&ind);
				
					if( deletion( p , ind , &lpos, size) == 1 ){
						printf("\n The data deleted successfully");
						display( p , lpos );
					}
					else
						printf("\n We can't delete the data at %d index",ind);
					
				
					break;
				}
			
				case 3:{
					display( p , lpos );
					printf("\n The List is Traversed ");
					break ;
				}
				
				case 4:{
						
					printf("\n Enter the product Id you want to search : ");
					scanf("%d",&sElement);
					
					int isSorted=sorted(p,lpos);
					
					if(  isSorted == -1 ){
				    	index=linearsearch(p,sElement,lpos);
						}
						
					else{
						index=BinarySearch(p,lpos,sElement);
					}
					
					
						
						if( index != -1 ){
							
							printf("\n The product id : %d is found at %d index",sElement,index);
							printf("\n ----------- The Founded Product ----------- ");
							printf("\n The Product Id : %d",p[index].productId);
							printf("\n The Product Name :  %s",p[index].productName);
							printf("\n The product Price : %0.2f",p[index].price);
							printf("\n The GST on the Product : %0.2f\n",p[index].gst);
						}
					
						else	
							printf("\n The Product is not found");
						
						
						break;
					}
				
					case 5:
						{
							 Product = fopen("ProductInfo.txt","w");
							 WriteFile(p,&lpos,Product);
							 fclose(Product);
							 break;
						}
					
					case 6:
						{
							Product=fopen("ProductInfo.txt","r");
							ReadFile(p,Product,lpos);
							fclose(Product);
							break;
						}
						
				
				default:
					printf("\n Invalid Choice");
			}
			printf("\n Do you want to perform anny operation ? (y/n) : ");
			fflush(stdin);
			scanf("%c",&choice3);
		
		}while( choice3 == 'y' || choice3 == 'Y' );
	}
	
	printf("\n Thank you :) ");
	
	return 0;
}	

int insert(struct product p[],int ind,int *lpos,int size)
{
	int i;
	i=ind;
	if( *lpos < size-1 )
	{
			
		if( ind <= *lpos+1 )
		{
			shiftDown( p , ind ,*lpos );
				// p[ind]=p[i];
			(*lpos)++;
			return 1;
		}
			
		else
			return 0;		
	}
	else
		return 0;
}

void shiftDown(struct product p[],int ind,int lpos)
{
	int curpos=lpos;
	while( curpos >= ind)
	{
		p[curpos+1] = p[curpos];
		curpos--;
	}

/*	int i;
	for(i=lpos ;i>=ind ;i--)
	{
		p[i+1]=p[i];
	}
*/
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
int sorted( struct product p[],int lpos)
{
	int i;
	for(i=0;i<lpos;i++)
	{
		if( p[i].productId > p[i+1].productId )
		{
			return -1;
		}
	}
	
	return 1;
}
int linearsearch(struct product p[], int sElement,int lpos)
{
	int i;
	
	for(i=0;i<=lpos;i++)
	{
		if( p[i].productId == sElement)
			return i;
	}
	return -1;
}

int BinarySearch(struct product p[],int lpos, int sElement )
{
	int mid,low,high;
	low=0;
	high=lpos;
	
	while( low<= high)
	{
		mid = ( high + low ) / 2;
		
		if( p[mid].productId == sElement)
			return mid;
			
		else
		if( p[mid].productId > sElement)
			high = mid -1;
		
		else
			low = mid +1 ;
	}
	
	return -1;
}

void WriteFile(struct product p[],int *lpos , FILE *Product )
{
   
    if (!Product)
    {
        printf("\n Unable to open file");
        return;
    }
    
    int i;
    
    for ( i = 0; i <= *lpos; i++)
    {
        fprintf(Product, "Product Id: %d\n", p[i].productId);
        fprintf(Product, "Product Name: %s\n", p[i].productName);
        fprintf(Product, "Product Price: %.2f\n", p[i].price);
        fprintf(Product, "GST: %.2f\n", p[i].gst);
        fprintf(Product, "----------------------------------------\n");
    }
    
    printf("\n The Current Data written to ProductInfo.txt successfully.\n");
    char cho;
    printf("\n Do You want to add new data ? (y/n) : ");
    fflush(stdin);
    scanf("%c",&cho);
    int ele;
    if( cho == 'y' || cho == 'Y')
    {
    	
    	printf("\n How many elements you want to add ? : ");
    	scanf("%d",&ele);
    	
    	for( i=*lpos+1 ; i<=*lpos+ele ; i++)
    	{
    		printf("\n Enter the Product Id : ");
    		scanf("%d",&p[i].productId);
    		printf("\n Enter the Product Name : ");
    		scanf("%s",p[i].productName);
    		printf("\n Enter the product Price : ");
    		scanf("%f",&p[i].price);
    		p[i].gst = ( p[i].price * 0.10 );
    		
    		fprintf(Product,"\n The Product Id : %d",p[i].productId);
    		fprintf(Product,"\n THe Product Name : %s",p[i].productName);
    		fprintf(Product,"\n The Product Price : %0.2f",p[i].price);
    		fprintf(Product,"\n The GST on the Product : %0.2f",p[i].gst);
    		printf("\n --------------------------------------------------------------\n");
    		
		}
		printf("\n\t **** Data written to ProductInfo.txt successfully. ****\n");
	}
	
	*lpos+=ele;
}

void ReadFile(struct product p[],FILE * Product,int lpos)
{
/*	
	char cho;
	int i=0;
	{
		
		//fscanf(Product,"%d %s %0.2f %0.2f",&p[i].productId,p[i].productName,&p[i].price,&p[i].gst);
		fscanf(Product,"\n The Product Id : %d",&p[i].productId);
   		fscanf(Product,"\n THe Product Name : %s",p[i].productName);
    	fscanf(Product,"\n The Product Price : %0.2f",&p[i].price);
    	fscanf(Product,"\n The GST on the Product : %0.2f",&p[i].gst);
    	
    	
		printf("\n Product Id : %d",p[i].productId);
		printf("\n Product Name : %s",p[i].productName);
		printf("\n Product Price : %0.2f",p[i].price);
		printf("\n GST on Product : %0.2f",p[i].gst);
		printf("\n ===============================================\n");	
		i++;
		printf("\n Do want to see next record ? (y/n) : ");
		fflush(stdin);
		scanf("%c",&cho);
		
	}while( (cho=='y' || cho=='Y') && i <= lpos ); //!(feof(Product)));
*/	
	
	char cho;
    int i = 0;
    
    if (!Product)
    {
        printf("\n Unable to open file");
        return;
    }

	for( i=0 ; i<= lpos ;i++)
	{
		fscanf(Product, "Product Id: %d\n", &p[i].productId);
        fscanf(Product, "Product Name: %s\n", p[i].productName);
        fscanf(Product, "Product Price: %f\n", &p[i].price);
        fscanf(Product, "GST: %f\n", &p[i].gst);

        printf("\n Product Id : %d", p[i].productId);
        printf("\n Product Name : %s", p[i].productName);
        printf("\n Product Price : %.2f", p[i].price);
        printf("\n GST on Product : %.2f", p[i].gst);
        printf("\n ================================================= \n");
	}
	
}
