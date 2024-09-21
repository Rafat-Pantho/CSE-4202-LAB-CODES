#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
} node;

node* list=NULL;

void prepend(int element){
    node* n = (node*)malloc(sizeof(node));
    n->value = element;
    n->next = NULL;
    n->next = list;
    list = n;
}

void append(int element){
    node* n = (node*)malloc(sizeof(node));
    n->value = element;
    n->next = NULL;
    if(list == NULL){
        list = n;
        return;
    }
    node* temp = list;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void insert_sorted(int element){
    node* n = (node*)malloc(sizeof(node));
    n->value = element;
    n->next = NULL;
    if(list == NULL){
        list = n;
        return;
    }
    else if(n->value < list->value){
        n->next = list;
        list = n;
    }
    else{
        for(node* curr = list; curr != NULL; curr = curr->next){
            if(curr->next == NULL){
                curr->next = n;
                break;
            }
            if(n->value < curr->next->value){
                n->next = curr->next;
                curr->next = n;
                break;
            }
        }
    }
}

void insert_after(int element, int pred){
    node *n = (node*)malloc(sizeof(node));
    n->value = element;
    n->next = NULL;
    node* curr = list;
    while(curr->value != pred) curr = curr->next;
    n->next = curr->next;
    curr->next = n;
}

void destroy(node* n){
    if(n == NULL) return;
    destroy(n->next);
    free(n);
}

void delete_node(int element){
    if(list == NULL){
        printf("List is empty!\n");
        return;
    }
    node* curr = list;
    node* prev = NULL;
    while(curr->value != element){
        prev = curr;
        curr = curr->next;
    }
    if(prev != NULL) prev->next = curr->next;
    free(curr);
}

void delete_front(){
    if(list == NULL){
        printf("List is empty!\n");
        return;
    }
    node* temp;
    temp = list;
    list = list->next;
    free(temp);
}

void delete_back(){
    if(list == NULL){
        printf("List is empty!\n");
        return;
    }
    node* curr = list;
    node* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    if(prev != NULL) prev->next = curr->next;
    free(curr);
}

void print_list(){
    if(list == NULL){
        printf("List is empty!\n");
        return;
    }
    for(node* ptr = list; ptr != NULL; ptr = ptr->next) printf("%d ", ptr->value);
    printf("\n");
}

bool find(int element){
    for(node* trav = list; trav != NULL; trav = trav->next) if(trav->value == element) return true;
    return false;
}

int main(){
    int x;
    while(scanf("%d", &x) != EOF) prepend(x);
    print_list();
    int k = 3, new_element = 13;
    insert_after(new_element, k);
    printf("%d has been inserted after %d.\n", new_element, k);
    print_list();
    if(find(k)) printf("%d is present!\n", k);
    else printf("%d is NOT present!\n", k); 
    delete_node(k);
    printf("%d has been deleted.\n", k);
    print_list();
    delete_front();
    printf("The first element has been deleted.\n");
    print_list();
    delete_back();
    printf("The last element has been deleted.\n");
    print_list();
    destroy(list);
    return 0;
}