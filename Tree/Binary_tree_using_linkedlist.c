/* Binary tree implementation using linked list */

#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *left;
    char data;
    struct node *right;
};

char a[] = {'A','B','C','D','E','F','G','\0','\0','H','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

struct node *builtree(int i)
{
    struct node *temp=NULL;
    if(a[i] != '\0')
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->left = builtree(2*i+1);
        temp->data = a[i];
        temp->right = builtree(2*i+2);
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

