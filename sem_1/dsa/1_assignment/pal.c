#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure represents a node in a linked list
typedef struct Node {
    int data;
    Node* next;
}Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    // Create an empty stack to store values
    int stack[1000]; // Assuming a maximum of 1000 elements
    int top = -1; // Initialize top of stack

    // Traverse the linked list and push values onto the stack
    Node* temp = head;
    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    // Reset temp to head of linked list
    temp = head;

    // Compare values by popping from the stack
    while (temp != NULL) {
        if (temp->data != stack[top--]) {
            // If values don't match, it's not a palindrome
            return false;
        }
        temp = temp->next;
    }

    // If all values match, it's a palindrome
    return true;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = createNode(1);
    head->next = createNode(5);
    head->next->next = createNode(2);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(1);

    // Print the original linked list
    printf("Original Linked List: ");
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}

