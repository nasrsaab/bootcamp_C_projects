#include <stdio.h>
#include <stdlib.h>

#define LIFT 0
#define RIGHT 1
#define COUNT 10
#define FOREVER for(;;)

struct node {
    int key;
    struct node* left, * right;
};

// Create a node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
// Print Tree
void printTree(struct node* root,int space) 
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    printTree(root->left, space);
}
// Inorder Traversal
void inorder(struct node* root) {
    if (root != NULL) {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d -> ", root->key);

        // Traverse right
        inorder(root->right);
    }
}
// preorder traversal
void preorder(struct node* root) {
	if (root == NULL) return;
	printf("%d ->", root->key);
	preorder(root->left);
	preorder(root->right);
}
// postorder traversal
void postorder(struct node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ->", root->key);
}
// Search a node
struct node* search(struct node* node, int key) {
    
    if (node == NULL) { printf("not found\n"); return NULL; }

    if (node->key == key) { printf("%d is found\n",node->key); return node; }

    // Traverse to the right place and insert the node
    if (key < node->key)
        node->left = search(node->left, key);
    else
        node->right = search(node->right, key);

    return node;
}           
// Insert a node in the correct place
struct node* insert(struct node* node, int key) {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}
// Find the inorder successor
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node* temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
bool isFullBinaryTree(struct node* root) 
{
        // Checking tree emptiness
        if (root == NULL)
            return true;
    
        // Checking the presence of children
        if (root->left == NULL && root->right == NULL)
            return true;
    
        if ((root->left) && (root->right))
            return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    
        return false;
 }
//Calculate the depth
int depth(struct node* node) {
    int d = 0;
    while (node != NULL) {
        d++;
        node = node->left;
    }
    return d;
}

// Check if the tree is perfect
bool is_perfect(struct node* root, int d, int level) {
    // Check if the tree is empty
    if (root == NULL)
        return true;

    // Check the presence of children
    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return is_perfect(root->left, d, level + 1) &&
        is_perfect(root->right, d, level + 1);
}

// Wrapper function
bool is_Perfect(struct node* root) {
    int d = depth(root);
    return is_perfect(root, d, 0);
}
// Count the number of nodes
int countNumNodes(struct node* root) {
    if (root == NULL)
        return (0);
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
bool checkComplete(struct node* root, int index, int numberNodes) {
    // Check if the tree is complete
    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}
// Driver code
int main() {
    struct node* root = NULL;
    int option;
    
    FOREVER
    { printf("\033[1;33m");
        printf("0: Insert nodes:\n");
        printf("1: In_order traversal:\n");
        printf("2: Pre_order traversal:\n");
        printf("3: Post_order traversal:\n");
        printf("4: Search a node:\n");
        printf("5: Delete a node:\n");
        printf("6: Print a Tree:\n");
        printf("7: Full Tree:\n");
        printf("8: Perfect Tree:\n");
        printf("9: Complete Tree:\n");
        printf("99: exit:\n ");
        scanf_s("%d", & option);
        char c=getchar();
        printf("\033[1;34m");
        switch (option)
        {
        case 0:
        {   int x;
            printf("Please enter the node number: ");
            scanf_s("%d", &x);
            char c=getchar();
            root = insert(root, x);
            break;
        }
        case 1:
            inorder(root);
            printf("\n");
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            postorder(root);
            printf("\n");
            break;
        case 4:
        {int x1;
        printf("Please enter the node number for searching: ");
        scanf_s("%d", &x1);
        char c1 = getchar();
        search(root, x1);
        break;
        }
        case 5:
        { int x2;
        printf("Please enter the node number for deleting: ");
        scanf_s("%d", &x2);
        char c2 = getchar();
        deleteNode(root, x2);
        break;
        }
        case 6:
            printTree(root,0);
            break;
        case 7:
        {
            if (isFullBinaryTree(root))
                 printf("The tree is a full binary tree\n");
             else
               printf("The tree is not a full binary tree\n");
            break;
        }
            
        case 8:
        {if (is_Perfect(root))
                    printf("The tree is a perfect binary tree\n");
                else
                    printf("The tree is not a perfect binary tree\n");
            break;
        }
        case 9:
        {  int node_count = countNumNodes(root);
            int index = 0;
            if (checkComplete(root, index, node_count))
                    printf("the tree is a complete binary tree\n");
                else
                    printf("The tree is not a complete binary tree\n");
            break;
        }
        case 99:return 0;
            break;
        default:
            break;
        }
    }
   
    return 0;
}