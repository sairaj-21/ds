#include <stdio.h>
#include <stdlib.h>

int flag = 0;

typedef struct BST
{
    int data;
    struct BST *lchild, *rchild;
} node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);
node *get_node();

void main()
{
    int choice, ans = 1, key;
    node *new_node, *root = NULL, *tmp, *parent;

    printf("\nProgram For Binary Search Tree ");

    do
    {
        printf("\n1. Create");
        printf("\n2. Search");
        printf("\n3. Recursive Traversals");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                new_node = get_node();
                printf("\nEnter The Element: ");
                scanf("%d", &new_node->data);

                if (root == NULL) // Tree is not created
                    root = new_node;
                else
                    insert(root, new_node);

                printf("\nWant to enter more elements? (1/0): ");
                scanf("%d", &ans);
            } while (ans);
            break;

        case 2:
            printf("\nEnter Element to be searched: ");
            scanf("%d", &key);
            tmp = search(root, key, &parent);

            if (flag == 1)
            {
                printf("\nParent of node %d is %d", tmp->data, parent->data);
            }
            else
            {
                printf("\nThe %d element is not present", key);
            }
            flag = 0;
            break;

        case 3:
            if (root == NULL)
            {
                printf("Tree is not created");
            }
            else
            {
                printf("\nThe Inorder display: ");
                inorder(root);
                printf("\nThe Preorder display: ");
                preorder(root);
                printf("\nThe Postorder display: ");
                postorder(root);
            }
            break;
        }
    } while (choice != 4);
}

node *get_node()
{
    node *temp = (node *)malloc(sizeof(node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(node *root, node *new_node)
{
    if (new_node->data < root->data)
    {
        if (root->lchild == NULL)
        {
            root->lchild = new_node;
        }
        else
        {
            insert(root->lchild, new_node);
        }
    }
    else if (new_node->data > root->data)
    {
        if (root->rchild == NULL)
        {
            root->rchild = new_node;
        }
        else
        {
            insert(root->rchild, new_node);
        }
    }
}

node *search(node *root, int key, node **parent)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\nThe %d element is present", temp->data);
            flag = 1;
            return temp;
        }
        *parent = temp;
        if (temp->data > key)
        {
            temp = temp->lchild;
        }
        else
        {
            temp = temp->rchild;
        }
    }
    return NULL;
}

void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->lchild);
        printf("%d\t", temp->data);
        inorder(temp->rchild);
    }
}

void preorder(node *temp)
{
    if (temp != NULL)
    {
        printf("%d\t", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}

void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf("%d\t", temp->data);
    }
}
