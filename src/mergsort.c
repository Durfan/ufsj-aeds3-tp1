#include "main.h"
 
node_t *MergeSort(node_t **headRef) {
    node_t *head = *headRef;
    node_t *a;
    node_t *b;
    if ((head == NULL) || (head->next == NULL)) return;

    FrontBackSplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a,b);
    return headRef;
}

node_t *SortedMerge(node_t *a, node_t *b) {
    node_t* result = NULL;

    if (a == NULL) return(b);
    else if (b==NULL) return(a);

    if (a->tupla.y >= b->tupla.y) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void FrontBackSplit(node_t *source, node_t **frontRef, node_t **backRef) {
    node_t *fast;
    node_t*slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void sort(conjunto_t *CJT) {
    MergeSort(&CJT->head);
}