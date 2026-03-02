#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rotateRight(struct Node* head, int k) 
{
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) 
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;

    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) 
    {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() 
{
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}