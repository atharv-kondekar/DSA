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
void clearInputBuffer();  // New function to clear input buffer

int main() {
    int size;
    printf("\n Enter the size of your list : ");
    scanf("%d", &size);

    struct product p[size];
    int i, ele;
    printf("\n How many products you want to add in your list? : ");
    scanf("%d", &ele);

    if (ele > size) {
        printf("\n Error: Number of products exceeds the size of the list!\n");
        return -1;
    }

    printf("\n ****** The GST on each Product is 10% ****");
    printf("\n Enter the information on %d products ", ele);
    for (i = 0; i < ele; i++) {
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
    clearInputBuffer();
    scanf("%c", &choice1);

    if (choice1 == 'y' || choice1 == 'Y') {
        char choice2;
        do {
            printf("\n You can only perform the following operations on the list: ");
            printf("\n    1. Add the Data ");
            printf("\n    2. Delete the Data");

            int ind;
            int choice3;
            printf("\n Which operation do you want to perform on the list? ");
            scanf("%d", &choice3);

            switch (choice3) {
                case 1: {
                    printf("\n Enter the index where you want to insert the data: ");
                    scanf("%d", &ind);

                    if (ind < 0 || ind > lpos + 1 || lpos + 1 >= size) {
                        printf("\n Invalid index or list is full!\n");
                        break;
                    }

                    printf("\n Enter the product id: ");
                    scanf("%d", &p[ind].product_id);
                    printf("\n Enter the product name: ");
                    scanf("%s", p[ind].product_name);
                    printf("\n Enter the product price: ");
                    scanf("%f", &p[ind].price);
                    p[ind].gst = (0.10 * p[ind].price);

                    if (insert(p, &lpos, ind, size) == 1)
                        display(p, lpos);
                    else
                        printf("\n We can't store the data at index %d", ind);

                    break;
                }
                default:
                    printf("\n Invalid Choice");
            }
            printf("\n Do you want to perform any other operations? (y/n) : ");
            clearInputBuffer();
            scanf("%c", &choice2);
        } while (choice2 == 'y' || choice2 == 'Y');
    } else {
        printf("\n Thank You :) ");
    }
    return 0;
}

int insert(struct product p[], int *lpos, int ind, int size) {
    if (*lpos < size - 1) {
        if (ind <= *lpos + 1) {
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
    while (curpos >= ind) {
        p[curpos + 1] = p[curpos];
        curpos--;
    }
}

void display(struct product p[], int lpos) {
    int i;
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n \t UPDATED LIST : ");
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for (i = 0; i <= lpos; i++) {
        printf("\n The product Id  : %d", p[i].product_id);
        printf("\n The product name : %s", p[i].product_name);
        printf("\n The product price : %f", p[i].price);
        printf("\n The product gst  : %f", p[i].gst);
    }
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


