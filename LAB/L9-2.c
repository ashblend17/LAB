#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left;
	struct node *right;
};
struct node* insert(int key,struct node*root)
{
	if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else if (root->key > key)
    {
        root->left = insert(key,root->left);
        return root;
    } else if (root->key < key)
    {
        root->right = insert(key,root->right);
        return root;
    }
    return root;
}
void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}
void preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}
int main()
{
	struct node*root=NULL;
	int n,a;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		root=insert(a,root);
	}
		scanf(" %c",&c);
		switch(c)
		{
			case 'a':
                printf("The inorder traversal is : ");
                inorder(root);
                break;
			case 'b':
                printf("The postorder traversal is : ");
                postorder(root);
                break;
			case 'c':
                printf("The preorder traversal is : ");
                preorder(root);
                break;
		}
}