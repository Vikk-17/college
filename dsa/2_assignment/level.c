// Recursive C program for level
// order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node *NODE;

void printLevelOrder(NODE root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

// Print nodes at a current level
void printCurrentLevel(NODE root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node
int height(NODE node)
{
    if (node == NULL)
        return 0;
    else {
        
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
NODE newNode(int data)
{
    NODE node = (NODE)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Driver program to test above functions
int main()
{
    NODE root = newNode(2);
    root -> left = newNode(1);
    root -> right = newNode(3);
    
    root -> right -> left = newNode(4);
    root -> right -> right = newNode(5);
    root -> right -> right -> left = newNode(6);


    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
