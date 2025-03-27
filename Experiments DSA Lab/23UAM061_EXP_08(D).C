#include <stdio.h>


int sorted(int list[], int ele) {
    for (int i = 0; i < ele - 1; i++) {
        if (list[i] > list[i + 1]) {
            return -1;
        }
    }
    return 1;
}

int BinarySearchRecursive(int list[], int low, int high, int SearchElement) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (list[mid] == SearchElement) {
        return mid;
    } 
	else if (list[mid] > SearchElement) 
	{
        return BinarySearchRecursive(list, low, mid - 1, SearchElement); 
    }
	else
	{
        return BinarySearchRecursive(list, mid + 1, high, SearchElement); 
    }
}

int main() {
    int size;
    printf("\n Enter the size of the list: ");
    scanf("%d", &size);

    int list[size], ele;
    printf("\n Enter the number of elements you want to enter CURRENTLY : ");
    scanf("%d", &ele);

    printf("\n Enter the elements in the list: ");
    for (int i = 0; i < ele; i++) {
        scanf("%d", &list[i]);
    }

    if (sorted(list, ele) == 1) {
        printf("\n The list is sorted :)");
        int SearchElement;
        printf("\n Enter the element you want to search: ");
        scanf("%d", &SearchElement);

        int index = BinarySearchRecursive(list, 0, ele - 1, SearchElement);
        if (index != -1) {
            printf("\n The data %d is found at index %d", SearchElement, index);
        } 
		else {
            printf("\n The data is not found in the list");
        }
        
    } 
	
	else {
        printf("\n The list is not sorted");
    }

    return 0;
}

