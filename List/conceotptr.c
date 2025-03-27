int array[3] = {1, 2, 3};
int *lpos = &array[0];
printf("%d\n", *lpos++); // Output: 1
printf("%d\n", *lpos);   // Output: 2 (pointer incremented, now points to array[1])

