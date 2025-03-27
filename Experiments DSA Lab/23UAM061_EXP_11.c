#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int stack[MAX];
int top = -1;

void push(int v)
{
    if (top < MAX - 1)
    {
        stack[++top] = v;
    }
}

int pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return -1;
}

int isEmpty()
{
    return top == -1;
}

void DFS(int A[MAX][MAX], int STR, int N)
{
    int visited[MAX];
    int I, J;

    for (I = 0; I < N; I++)
    {
        visited[I] = 0;
    }

    push(STR);
    visited[STR] = 1;

    while (!isEmpty())
    {
        int V = pop();

        printf("%d ", V);

        for (J = 0; J < N; J++)
        {
            if (V != J && A[V][J] != 0 && visited[J] == 0)
            {
                visited[J] = 1;
                push(J);
            }
        }
    }
}

int main()
{
    int A[MAX][MAX], N, STR;
    int I, J;

    printf("Enter the number of nodes: ");
    scanf("%d", &N);

    printf("Enter the adjacency matrix:\n");
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            scanf("%d", &A[I][J]);
        }
    }

    printf("Enter the start node: ");
    scanf("%d", &STR);

    printf("DFS traversal starting from node %d:\n", STR);
    DFS(A, STR, N);

    return 0;
}

