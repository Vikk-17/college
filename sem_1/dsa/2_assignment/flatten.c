// C Program to flatten a given Binary Tree into linked
// list
#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

typedef struct node *NODE;

// utility that allocates a new Node with the given key
NODE newNode(int key)
{
	NODE node = (NODE)malloc(sizeof(struct node));
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to convert binary tree into linked list by
// altering the right node and making left node point to
// NULL
void flatten(NODE root)
{
	// base condition- return if root is NULL or if it is a
	// leaf node
	if (root == NULL || root->left == NULL && root->right == NULL)
		return;

	// if root->left exists then we have to make it
	// root->right
	if (root->left != NULL) {
		// move left recursively
		flatten(root->left);
		// store the node root->right
		NODE tmpRight = root->right;
		root->right = root->left;
		root->left = NULL;
		// find the position to insert the stored value
		NODE t = root->right;
		while (t->right != NULL)
			t = t->right;
		// insert the stored value
		t->right = tmpRight;
	}

	// now call the same function for root->right
	flatten(root->right);
}

// To find the inorder traversal
void preorder(NODE root)
{
	// base condition
	if (root == NULL)
		return;
	preorder(root->left);
	printf("%d ", root->key);
	preorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
  NODE root = newNode(2);
  root -> left = newNode(1);
  root -> right = newNode(3);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(5);
  root -> right -> right -> left = newNode(6);

	flatten(root);

	printf("The Pre-order traversal after flattening binary tree ");
	preorder(root);
  printf("\n");
	return 0;
}

// This code is contributed by aditykumar129.

