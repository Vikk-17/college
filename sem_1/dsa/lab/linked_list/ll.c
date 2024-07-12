#include<stdio.h>
#include<stdlib.h>
#include<alloca.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode(){
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    if(x == NULL){
        printf("No memory in heap\n");
        exit(0);
    }
    return x;
}

NODE insert_front(int data, NODE start){
    NODE temp;
    temp = getnode();
    temp->data = data;
    temp->link = start;
    return temp;
}

NODE insert_rear(int data, NODE start){
    NODE cur, temp;
    temp = getnode();
    temp->data = data;
    temp->link = NULL;
    if(start == NULL) return temp;
    cur = start;
    while(cur->link != NULL) cur = cur->link;
    cur->link = temp;
    return start;
}

NODE delete_front(NODE start){
    NODE cur;
    if(start == NULL){
        printf("No item to delete\n");
        return start;
    }
    cur = start;
    printf("Deleted element is: %d\n", cur->data);
    start = start->link;
    free(cur);
    return start;
}

NODE delete_rear(NODE start){
    NODE prev, cur;
    if(start == NULL){
        printf("No element to delete\n");
        return start;
    }
    // only single node
    if(start->link == NULL){
        printf("Deleted element is %d\n", start->data);
        free(start);
        return NULL;
    }
    prev = NULL;
    cur = start;
    while(cur->link != NULL){
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted element is: %d\n", cur->data);
    prev->link = NULL;
    free(cur);
    return start;
}

NODE delete_element(int data, NODE start){
    NODE prev, cur;
    if(start == NULL){
        printf("No element to delete\n");
        return start;
    }

    prev = NULL;
    cur = start;
    while(cur!=NULL && data!=cur->data){
        prev = cur;
        cur = cur->link;
    }

    if(cur==NULL){
        printf("Element not found\n");
        return start;
    }
    printf("Element to delete is: %d", cur->data);
    prev->link = cur->link;
    free(cur);
    return start;
}

void display(NODE start){
    NODE cur;
    if(start == NULL){
        printf("No elements to show\n");
        return ;
    }
    cur = start;
    printf("The contents of list\n");
    while(cur!=NULL){
        printf("%d\n", cur->data);
        cur = cur->link;
    }
}

int main(){
    int opt, data;
    NODE start = NULL;
    while(1){
        printf("\n1. Insert front\n2. Insert rear\n");
        printf("3. Delete front\n4. Delete rear\n5. Delete element\n");
        printf("6. Display\n7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Enter element to add at front: ");
                scanf("%d", &data);
                start = insert_front(data, start);
                break;
            case 2:
                printf("Enter element to add at end: ");
                scanf("%d", &data);
                start = insert_rear(data, start);
                break;
            case 3:
                start = delete_front(start);
                break;
            case 4:
                start = delete_rear(start);
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                start = delete_element(data, start);
                break;
            case 6:
                display(start);
                break;
            case 7:
                exit(0);
            default: 
                printf("Enter valid choice\n");
                break;
        }
    }
}