/*
	Write a recursive function to calculate the power of a number. 
	Given two integers x and n, compute x^n.
*/
/*
#include<stdio.h>

float power_of_num(int n,int x)
{
	if(n==0)
		return 1;
	
		
	else
	if(n<0){
		n=-(n);
		return 1/(x*power_of_num(n-1,x));
	}
	
	else
	if(n==1)
		return x;
				
	else
		return x*power_of_num(n-1,x);
}

int main()
{
	int number,power;
	printf("\n Enter the number : ");
	scanf("%d",&number);
	printf("\n Enter the power : ");
	scanf("%d",&power);
	
	printf("\n The %d^%d = %0.2f",number,power,power_of_num(power,number));
	
	return 0;
}*/

#include<stdio.h>

float power_of_num(int n, int x)
{
    if(n == 0)
        return 1;  // Base case: x^0 = 1
    else if(n > 0)
        return x * power_of_num(n - 1, x); // Recursive case for positive n
    else
        return 1.0 / power_of_num(-n, x); // Recursive case for negative n
}

int main()
{
    int number, power;
    printf("\nEnter the number: ");
    scanf("%d", &number);
    printf("\nEnter the power: ");
    scanf("%d", &power);
    
    printf("\n%d^%d = %0.2f\n", number, power, power_of_num(power, number));
    
    return 0;
}

