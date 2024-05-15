/* C Program to remove duplicates in an unsorted
   linked list */
#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct node {
    int info;
    struct node *link;
};
typedef struct node *NODE;

// Utility function to create a new Node
NODE newNode(int info)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = info;
    temp->link = NULL;
    return temp;
}

/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(NODE start)
{
    NODE ptr1, ptr2, dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->link != NULL) {
            /* If duplicate then delete it */
            if (ptr1->info == ptr2->link->info) {
                /* sequence of steps is important here */
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}

/* Function to print nodes in a given linked list */
void printList(NODE node)
{
    while (node != NULL) {
        printf("%d ", node->info);
        node = node->link;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    NODE start = newNode(10);
    start->link = newNode(10);
    start->link->link = newNode(8);
    start->link->link->link = newNode(4);
    start->link->link->link->link = newNode(7);
    start->link->link->link->link->link = newNode(2);
    start->link->link->link->link->link->link = newNode(7);

    printf("Linked list before removing duplicates ");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates ");
    printList(start);

    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)

