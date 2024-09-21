#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node * prev;
    struct node * next;
}node;

typedef struct{
    node *head;
    node * tail;
}doublyLinkedlist;

node *createNode(int element){
    node *n= (node*)malloc(sizeof(node));
    if(n){
        n->value = element;
        n->prev=NULL;
        n->next=NULL;
    }
    return n;
}

void append(doublyLinkedlist * list, int element){
    node *n = createNode(element);
    if (n){
        n->prev = list->tail;
        if(list->tail) list->tail->next = n;
        else list->head = n;
        list->tail = n;
    }
}

int main(){
    doublyLinkedlist list;
    list.head=NULL;
    list.tail=NULL;
    int x, counter =0;
    do{
        scanf("%d",&x);
        if(x){
            counter ++;
            append(&list, x);
        }
    }while(x>0);

    node *n=list.head;

    for(int i=0;i<counter/2+1;i++)n=n->next;

    printf("Middle Element: %d",n->prev->value);

    return 0;
}