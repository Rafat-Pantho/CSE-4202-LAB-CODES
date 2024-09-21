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
}doubullyCircularLinkedList;

node * createnode(int element){
    node * n = (node*)malloc(sizeof(node));
    if(n){
        n->value = element;
        n->prev = NULL;
        n->next = NULL;
    }
    return n;
}

void prepend(doubullyCircularLinkedList *list, int element){
    node * n = createnode(element);
    if(n){
        if(!list->head)n->next=n->prev=n;
        else{
            n->next = list->head;
            n->prev = list->head->prev;
            list->head->prev->next=n;
            list->head->prev=n;
        }
        list->head = n;
    }
}

void append(doubullyCircularLinkedList *list, int element){
    node * n = createnode(element);
    if(n){
        if(!list->head){
            n->next = n->prev = n;
            list->head = n;
        }
        else{
            n->next = list->head;
            n->prev = list->head->prev;
            list->head->prev->next=n;
            list->head->prev=n;
        }
    }
}

void insertSorted(doubullyCircularLinkedList *list, int element){
    node * n = createnode(element);
    if(n){
        if(!list->head || list->head->value >= element){
            prepend(list, element);
            return;
        }
        node *iterator = list->head->next;
        while(iterator!=list->head && iterator->value < element) iterator = iterator->next;
        n->next = iterator;
        n->prev = iterator->prev;
        iterator->prev->next = n;
        iterator->prev = n;
    }
}

void insertAfter(doubullyCircularLinkedList *list, int element, int after){
    node * n = createnode(element);
    if(n){
        node *iterator = list->head;
        do{
            if(iterator->value == after){
                n->next = iterator->next;
                n->prev = iterator;
                iterator->next->prev = n;
                iterator->next = n;
                return;
            }
            iterator = iterator->next;
        } while (iterator != list->head);
    }
}

void destroy(doubullyCircularLinkedList *list, node *n){
    if(n->next==n)list->head=NULL;
    else{
        n->prev->next=n->next;
        n->next->prev=n->prev;
        if(list->head==n) list->head=n->next;
    }
    free(n);
}

void delNode(doubullyCircularLinkedList *list, int element){
    if(list->head){
        if(list->head->value == element){
            destroy(list, list->head);
            return;
        }
        node *iterator;
        for(iterator = list->head->next; iterator!=list->head && iterator->value != element; iterator = iterator->next);
        if(iterator){
            destroy(list,iterator);
            return;
        }
    }
}

void delFront(doubullyCircularLinkedList *list){
    if(list->head)destroy(list, list->head);
}

void delBack(doubullyCircularLinkedList *list){
    if(list->head)destroy(list, list->head->prev);
}

void printList(doubullyCircularLinkedList *list){
    if(list->head){
        node *iterator = list->head;
        do{
            printf("%d ", iterator->value);
            iterator = iterator->next;
        }while (iterator!=list->head);
        printf("\n");
    }
    else printf("List is empty!\n");
}

bool find(doubullyCircularLinkedList *list, int element){
    if(list->head){
        node *iterator = list->head;
        do{
            if(iterator->value == element) return true;
            iterator = iterator->next;
        } while (iterator != list->head);
        return false;
    }
    return false;
}

int main(){
    doubullyCircularLinkedList list;
    list.head = NULL;

    prepend(&list, 10);
    prepend(&list, 45);
    append(&list, 5);
    append(&list, 7);
    insertAfter(&list, 3, 10);
    insertAfter(&list, 2, 5);
    insertSorted(&list, 65);
    insertSorted(&list, 37);
    printList(&list);
    printf("%d\n", find(&list, 5));
    printf("%d\n", find(&list, 1));
    delNode(&list, 10);
    printList(&list);
    delNode(&list, 5);
    printList(&list);
    delFront(&list);
    printList(&list);
    delBack(&list);
    printList(&list);

    return 0;
}