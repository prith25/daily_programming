/* Sort the array based on number of factors */

#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct bnode
{
    struct bnode *left;
    int num;
    int weight;
    struct bnode *right;
};

void insert(struct bnode **root, int n, int w)
{
    if(*root == NULL)
    {
        *root = (struct bnode *)malloc(sizeof(struct bnode));
        (*root)->left = NULL;
        (*root)->num = n;
        (*root)->weight = w;
        (*root)->right = NULL;
    }
    else
    {
        if((*root)->weight < w)
            insert(&(*root)->left,n,w);
        else    
            insert(&(*root)->right,n,w);
    }
}

void inorder(struct bnode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->num);
        inorder(root->right);
    }
}

int calc_weight(int num)
{
    int i, count;
    for(i=1, count=0; i<=num; i++)
    {
        if(num%i == 0)
            count++;
    }
    return count;
}

int main()
{
    struct bnode *b;
    b = NULL;
    int i, num, weight, a[5] = {8, 2, 3, 12, 16};
    for(i=0; i<5; i++)
    {
        weight = calc_weight(a[i]);
        insert(&b,a[i],weight);
    }
    printf("Output : ");
    inorder(b);
    return 0;
}

