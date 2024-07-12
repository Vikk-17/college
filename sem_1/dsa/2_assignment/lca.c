// C Program to find LCA of n1 and n2 using one traversalof
// Binary Tree
#include <stdio.h>
#include <stdlib.h>

// A Binary Tree Node
struct node {
	struct node *left, *right;
	int key;
};

typedef struct node *NODE;

// Utility function to create a new tree Node
NODE newNode(int key)
{
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function returns pointer to LCA of two given values
// n1 and n2. This function assumes that n1 and n2 are
// present in Binary Tree
NODE findLCA(NODE root, int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with root's key, report
	// the presence by returning root (Note that if a key is
	// ancestor of other, then the ancestor key becomes LCA
	if (root->key == n1 || root->key == n2)
		return root;

	// Look for keys in left and right subtrees
	NODE left_lca = findLCA(root->left, n1, n2);
	NODE right_lca = findLCA(root->right, n1, n2);

	// If both of the above calls return Non-NULL, then one
	// key is present in once subtree and other is present
	// in other, So this node is the LCA
	if (left_lca && right_lca)
		return root;

	// Otherwise check if left subtree or right subtree is
	// LCA
	return (left_lca != NULL) ? left_lca : right_lca;
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
	// Let us create binary tree given in the above example
	
	printf("LCA(4, 5) = %d", findLCA(root, 4, 5)->key);
	printf("\nLCA(1, 3) = %d", findLCA(root, 1, 3)->key);
	printf("\nLCA(3, 4) = %d", findLCA(root, 3, 4)->key);
	printf("\nLCA(3, 6) = %d", findLCA(root, 3, 6)->key);
	printf("\n");
	return 0;
}


