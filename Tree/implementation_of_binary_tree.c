/* Implementation of binary tree */

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
    insert(&b,20);
    insert(&b,17);
    insert(&b,6);
    insert(&b,8);
    insert(&b,10);
    insert(&b,7);
    insert(&b,18);
    insert(&b,13);
    insert(&b,12);
    insert(&b,5);
    inorder(b);
    return 0;
}
