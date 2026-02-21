#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void Traverse(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    int n, value, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    Traverse(head);

    return 0;
}