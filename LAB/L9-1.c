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
struct node* getmin(struct node*root)
{
	struct node*curr=root;
	while(curr&&curr->left)
	{
		curr=curr->left;
	}
	return curr;
}
struct node* delete(int k,struct node*root)
{
	struct node *temp;
	if(k<root->key)
	root->left=delete(k,root->left);
	else if(k>root->key)
	root->right=delete(k,root->right);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			temp=getmin(root->right);
			root->key=temp->key;
			root->right=delete(temp->key,root->right);
		}
	}
	return root;
}
int main()
{
	struct node*root=NULL;
	int n,a,m;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		root=insert(a,root);
	}
	int b=1;
	while(b==1)
    {
		scanf(" %c",&c);
		switch(c)
		{
			case 'a':scanf("%d",&m);
					root=delete(m,root);
                    break;
			case 'b':
                printf("Inorder :");
                inorder(root);
                b=0;
                break;
		}
	}
}