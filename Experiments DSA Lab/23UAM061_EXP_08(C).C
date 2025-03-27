#include <stdio.h>

int LinearSearchRecursive(int arr[], int Size, int Ele, int index) {
    if (index >= Size) 
        return -1;
    if (arr[index] == Ele) 
        return index;
    return LinearSearchRecursive(arr, Size, Ele, index + 1);
}

int main() {
    int Size;
    printf("\n Enter the size of an array: ");
    scanf("%d", &Size);

    int Num[Size], i, Ele;
    printf("\n Enter the elements in an array: ");
    for (i = 0; i < Size; i++) {
        scanf("%d", &Num[i]);
    }

    printf("\n Enter the element you want to search: ");
    scanf("%d", &Ele);

    int check = LinearSearchRecursive(Num, Size, Ele, 0);

    if (check != -1) 
        printf("\n The element %d is found at %d index", Ele, check);
    else 
        printf("\n The element is not found");

    return 0;
}

