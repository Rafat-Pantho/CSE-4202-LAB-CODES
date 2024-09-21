#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *prev;
    struct node *next;
} node;

typedef struct{
    node *head;
    node *tail;
}doubullyLinkedList;

node* createnode(int element){
    node * n = (node*)malloc(sizeof(node));
    if(n){
        n->value = element;
        n->prev = NULL;
        n->next = NULL;
    }
    return n;
}

void prepend(doubullyLinkedList *list, int element){
    node* n = createnode(element);
    if(n){
        n->next= list->head;
        if(list->head)list->head->prev = n;
        else list->tail = n;
        list->head = n;
    }
}

void append(doubullyLinkedList *list, int element){
    node* n = createnode(element);
    if(n){
        n->prev = list->tail;
        if(list->tail) list->tail->next = n;
        else list->head = n;
        list->tail = n;
    }
}

void insertSorted(doubullyLinkedList *list, int element){
    node* n = createnode(element);
    if(n){
        node *iterator = list->head;
        while(iterator && iterator->value < element) iterator = iterator->next;
        if(iterator == NULL)append(list, element);
        else if (iterator == list->head) prepend(list, element);
        else{
            n->next = iterator;
            n->prev = iterator->prev;
            iterator->prev->next = n;
            iterator->prev = n;
        }
    }
}

void insertAfter(doubullyLinkedList *list, int element, int after){
    node* n = createnode(element);
    node *iterator = list->head;
    while(iterator && iterator->value != after) iterator = iterator->next;
    if(iterator){
        n->next = iterator->next;
        if(iterator->next)iterator->next->prev = n;
        else list->tail = n;
        iterator->next = n;
        n->prev = iterator;
    }
}

void destroy(doubullyLinkedList *list, node *n){
    if(n->prev) n->prev->next = n->next;
    else list->head = n->next;
    if(n->next) n->next->prev = n->prev;
    else list->tail= n->prev;
    free(n);
}

void delNode(doubullyLinkedList *list, int element){
    node *iterator = list->head;
    while(iterator && iterator->value != element) iterator = iterator->next;
    if(iterator) destroy(list, iterator);
}

void delFront(doubullyLinkedList *list){
    if(list->head)destroy(list, list->head);
}

void delBack(doubullyLinkedList *list){
    if(list->tail)destroy(list, list->tail);
}

void printList(doubullyLinkedList *list){
    if(list == NULL){
        printf("List is empty!\n");
        return;
    }
    for(node* ptr = list->head; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->value);
    printf("\n");
}

bool find(doubullyLinkedList *list, int element){
    for(node* iterator = list->head; iterator; iterator = iterator->next) if(iterator->value == element) return true;
    return false;
}

int main(){
    doubullyLinkedList list;
    list.head=list.tail=NULL;

    prepend(&list, 3);
    prepend(&list, 37);
    append(&list, 5);
    insertSorted(&list, 4);
    insertAfter(&list, 2, 3);
    insertAfter(&list, 6, 7);
    insertSorted(&list, 56);
    printList(&list);
    printf("Is 4 in the list? %s\n", find(&list, 4) ? "FOUND" : "NOT FOUND");
    printf("Is 6 in the list? %s\n", find(&list, 6) ? "FOUND" : "NOT FOUND");
    delNode(&list, 3);
    printList(&list);
    delFront(&list);
    printList(&list);
    delBack(&list);
    printList(&list);

    return 0;
}