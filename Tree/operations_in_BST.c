/* Operations in a binary search tree */

#include <stdio.h>
#include <malloc.h>

struct bnode
{
    struct bnode *left;
    int data;
    struct bnode *right;
};

void insert(struct bnode **root, int num)
{
    if(*root == NULL)
    {
        *root = (struct bnode *)malloc(sizeof(struct bnode));
        (*root)->left = NULL;
        (*root)->data = num;
        (*root)->right = NULL;
    }
    else
    {
        if((*root)->data > num)
            insert(&(*root)->left,num);
        else
            insert(&(*root)->right,num);
    }
    return;
}

void search(struct bnode **root, int num, struct bnode **parent, struct bnode **x, int *found)
{
    struct bnode *q;
    q = *root;
    *found = 0;
    *parent = NULL;
    while(q != NULL)
    {
        if(q->data == num)
        {
            *found = 1;
            *x = q;
            return;
        }
        *parent = q;
        if(q->data > num)
            q = q->left;
        else
            q = q->right;
    }
}

void del(struct bnode **root, int num)
{
    if(*root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    int found;
    struct bnode *parent, *x, *xsucc;
    search(root,num,&parent,&x,&found);
    if(found == 0)
    {
        printf("Number is not found");
        return;
    }
    if(x->left != NULL && x->right != NULL)
    {
        parent = x;
        xsucc = x->right;
        while(xsucc->left != NULL)
        {
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
    }
    if(x->left == NULL && x->right == NULL)
    {
        if(parent->left == x)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(x);
        return;
    }
    if(x->left == NULL && x->right != NULL)
    {
        if(parent->left == x)
            parent->left = x->right;
        else
            parent->right = x->right;
        free(x);
        return;
    }
    if(x->left != NULL && x->right == NULL)
    {
        if(parent->left == x)
            parent->left = x->left;
        else
            parent->right = x->left;
        free(x);
        return;
    }
}

void inorder(struct bnode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    return;
}

int main()
{
    struct bnode *b;
    b = NULL;
    int i=0, a[] = {11,9,13,8,10,12,14,15,7};
    while(i<=8)
    {
        insert(&b,a[i]);
        i++;
    }
    printf("BST : ");
    inorder(b);
    printf("\n");
    printf("BST after deletion : ");
    del(&b,13);
    inorder(b);
    printf("\n");
    printf("BST after deletion : ");
    del(&b,9);
    inorder(b);
    printf("\n");
    printf("BST after deletion : ");
    del(&b,14);
    inorder(b);
    printf("\n");
    printf("BST after deletion : ");
    del(&b,7);
    inorder(b);
    printf("\n");
    return 0;
}
