// == DATA STRUCTURE MINI PROJECT == //

// --- TITLE: CONVERT BINARY TREE TO ITS MIRROR --- //
// --- NAME: ANURAG KANDALKAR --- //
// --- REG NO: 189302059 --- //

#include <stdio.h>
#include <stdlib.h>

// Defining the structure of Binary Tree

struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree TREE;

// Creating a node in Binary Tree

TREE *createNode(int temp)
{
    TREE *node = (TREE *)malloc(sizeof(TREE));
    node->left = NULL;
    node->right = NULL;
    node->info = temp;
    return node;
}

//Creating Normal Binary Tree

TREE *createBinaryTree(TREE *root, int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        int temp = arr[i];
        if (root == NULL)
        {
            root = createNode(temp);
        }
        else
        {
            TREE *parent = root, *child = root;
            while (child != NULL)
            {
                parent = child;
                if (parent->info < temp)
                    child = child->right;
                else
                    child = child->left;
            }
            if (parent->info < temp)
            {
                parent->right = createNode(temp);
            }
            else
            {
                parent->left = createNode(temp);
            }
        }
    }
    return root;
}

// Printing Binary Tree in Preorder

void Preorder(TREE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        Preorder(root->left);
        Preorder(root->right);
    }
}

// Printing Binary Tree in Inorder

void Inorder(TREE *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->info);
        Inorder(root->right);
    }
}

// Printing Binary Tree in Postorder

void Postorder(TREE *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->info);
    }
}
TREE *search(TREE *root, int x)
{
    printf("Inside Search");
    TREE *temp = root;
    while (temp->left->info != x || temp->right->info != x || temp != NULL)
    {
        if (temp->info < x)
            temp = temp->right;
        else
            temp = temp->left;
    }
    if (temp == NULL)
        return NULL;
    else
        return temp;
}
TREE *inordersucessor(TREE *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
TREE *delete (TREE *root, int x)
{
    TREE *p = search(root, x);
    if (p == NULL)
    {
        printf("The info entered is not present in tree");
    }
    else
    {
        TREE *temp, *parent;
        if (p->right->info == x)
        {
            temp = p->right;
            parent = p->right;
        }
        else
        {
            temp = p->left;
            parent = p->left;
        }
        if (temp->right == NULL && temp->left == NULL)
        {
            parent = NULL;
            free(temp);
            printf("Deleted Sucessfully");
        }
        else if (temp->right != NULL && temp->left == NULL)
        {
            parent = temp->right;
            free(temp);
            printf("Deleted Sucessfully");
        }
        else if (temp->right == NULL && temp->left != NULL)
        {
            parent = temp->left;
            free(temp);
            printf("Deleted Sucessfully");
        }
        else
        {
            TREE *is = inordersucessor(temp);
            parent = is;
            free(temp);
            printf("Deleted Sucessfully");
        }
    }
    return root;
}
// Print function to print Inorder,Preorder,postOrder

void printBST(TREE *root)
{
    printf("The Binary Tree in Inorder \n");
    Inorder(root);
    printf("\n");
    printf("The Binary Tree in Preorder\n");
    Preorder(root);
    printf("\n");
    printf("The Binary Tree in Postorder\n");
    Postorder(root);
    printf("\n");
}

// Main Function

int main()
{
    int n, i;
    TREE *root = NULL;
    printf("Enter the number of elements to be added in Binary tree \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter all elements in sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("\n");
    root = createBinaryTree(root, arr, n);
    // printf("The  Binary Search Tree:-\n");
    // printBST(root);
    // root = delete (root, 13);
    // printBST(root);
    // root = delete (root, 6);
    // printBST(root);
    // root = delete (root, 10);
    // printBST(root);
    return 1;
}
//8 3 10 1 6 14  4 7 13