#include "main.h"

void MergeSort(conjunto_t *CJT) {
    node_t *head = CJT->head;
    node_t *a;
    node_t *b;
    if ((head == NULL) || (head->next == NULL)) return;

    FrontBackSplit(head,a,b); 
    MergeSort(a);
    MergeSort(b);
    
    CJT = mergeSRT(a,b);
}

node_t *mergeSRT(node_t *a, node_t *b) {
    node_t *result = NULL;
 
    if (a == NULL) return(b);
    else if (b==NULL) return(a);
    
    if (a->tupla.y <= b->tupla.y) {
        result = a;
        result->next = mergeSRT(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSRT(a, b->next);
    }
    return(result);
}
 
void FrontBackSplit(conjunto_t *CJT, node_t **frontRef, node_t **backRef) {
    node_t *fast;
    node_t *slow;
    slow = CJT->head;
    fast = CJT->head->next;
 
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *frontRef = CJT->head;
    *backRef = slow->next;
    slow->next = NULL;
}