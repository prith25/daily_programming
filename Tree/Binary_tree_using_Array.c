/* Binary tree implementation using array */

#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *left;
    char data;
    struct node *right;
};

char a[] = {'A','B','C','D','E','F','G','\0','\0','H'};
int lc[] = {1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[] = {2,4,6,-1,-1,-1,-1,-1,-1,-1};

struct node *builtree(int index)
{
    struct node *temp;
    if(index != -1)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->left = builtree(lc[index]);
        temp->data = a[index];
        temp->right = builtree(rc[index]);
    }
    return temp;
}

void inorder(struct node *r)
{
    if(r != NULL)
    {
        inorder(r->left);
        printf("%c ",r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r)
{
    if(r != NULL)
    {
        printf("%c ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r)
{
    if(r != NULL)
    {
        postorder(r->left);
        inorder(r->right);
        printf("%c ",r->data);
    }
}

int main()
{
    struct node *root;
    root = builtree(0);
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Postorder : ");
    postorder(root);
    return 0;
}
