/*
Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
    1. 5 if a perfect square
    2. 4 if multiple of 4 and divisible by 6
    3. 3 if even number

And sort the numbers based on the weight and print it as follows

<10,its_weight>,<36,its weight><89,its weight>
Should display the numbers based on increasing order.
*/

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
        if((*root)->weight > w)
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
        printf("<%d, ",root->num);
        printf("%d> ",root->weight);
        inorder(root->right);
    }
}

int calc_weight(int num)
{
    int total = 0, sq;
    sq = floor(sqrt(num));
    if(num == (sq*sq))
        total += 5;
    if((num%4==0) && (num%6==0))
        total += 4;
    if(num%2==0)
        total += 3;
    return total;
}

int main()
{
    struct bnode *b;
    b = NULL;
    int i, num, weight;
    for(i=0; i<5; i++)
    {
        scanf("%d",&num);
        weight = calc_weight(num);
        insert(&b,num,weight);
    }
    printf("Output : ");
    inorder(b);
    return 0;
}
