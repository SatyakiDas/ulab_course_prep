#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode
{
    int data;
    struct SLLNode* next;
} SLLNode;

void print_list(SLLNode* head)
{   
    SLLNode* curr = head;
    
    printf("[");
    if(curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    
    while(curr != NULL)
    {
        printf(", %d", curr->data);
        curr = curr->next;
    }

    printf("]");
}

SLLNode* createSLLNode(int data)
{
    SLLNode* new_node = malloc(sizeof(SLLNode));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

SLLNode* insert_back(SLLNode* head, int data)
{
    SLLNode* curr = head;

    while(curr != NULL && curr->next != NULL) curr = curr->next;
    if(curr == NULL) head = createSLLNode(data);
    else curr->next = createSLLNode(data);

    return head;
}

void deleteSLLNode(SLLNode* node)
{
    free(node);
}

int main()
{
    SLLNode* head = NULL;

    while(1)
    {
        int action;
        scanf("%d", &action);
        if(action == 0) break;
        else if(action == 1)
        {
            int data;
            scanf("%d", &data);
            head = insert_back(head, data);
        }
        else if(action == 2)
        {

        }
        else if(action == 3)
        {
            print_list(head);
            printf("\n");
        }
    }

    return 0;
}