#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tmp = NULL;
Node *spear = NULL;
Node *current = NULL;

void Josep(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        // Create tmp Node
        tmp = (Node *)malloc(sizeof(Node));
        tmp->data = i;
        tmp->next = NULL;
        tmp->prev = NULL;

        if (head == NULL)
        {
            head = tmp;
            current = tmp;
        }
        else
        {
            current->next = tmp;
            tmp->prev = current;
            current = tmp;
        }
    }
    current->next = head;
    head->prev = current;
    printf("<");
    // --------------
    // for loop 6 times
    for (int cnt = 0; cnt < n - 1; cnt++)
    {
        // for loop k - 1 times
        spear = head;
        for (int j = 0; j < k - 1; j++)
        {
            spear = spear->next;
        }
        printf("%d, ", spear->data);
        spear->prev->next = spear->next;
        spear->next->prev = spear->prev;
        head = spear->next;
        free(spear);
    }
    // --------------
    printf("%d", head->data);
    printf(">");
    free(head);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    // (n, k)
    Josep(n, k);
    return 0;
}