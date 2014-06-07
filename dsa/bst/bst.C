
//binary search tree
//traversing using preorder, inorder, and postorder
//without recursion

#include<stdio.h>
#include<conio.h>

struct Tree
{
	int val;
	int *right,*left;
};

typedef struct Tree tree;

tree*makenode(int);
tree*add(tree*,tree*);
void preorder();
void inorder();
void postorder();


int main()
{
	tree*root,*nn;
	int tmp;
	clrscr();

	root=NULL;

	while(1)
	{
		printf("enter the value of node ");
		scanf("%d",&tmp);

		if(tmp==0)
			break;
		else
		{
			nn=makenode(tmp);
			root=add(root,nn);
		}
	}
	printf("\n\ninorder\n");
	inorder(root);
	printf("\n\npreorder\n");
	preorder(root);
	printf("\n\npostorder\n");
	postorder(root);

	getch();
	return 1;
}


tree*makenode(int tmp)
{
	tree*nn;
	nn=(tree*)malloc(sizeof(tree));
	nn->right=nn->left=NULL;
	nn->val=tmp;
	return nn;
}

tree*add(tree*root,tree*nn)
{
	tree*ptr,*prev;
	int dir;
	if(!root)
		return nn;
	ptr=root;
	while(ptr)
	{
		prev=ptr;
		if(nn->val>ptr->val)
		{
			dir=1;
			ptr=ptr->right;
		}
		else
		{
			dir=0;
			ptr=ptr->left;
		}
	}

	if(dir==0)
		prev->left=nn;
	else
		prev->right=nn;

	return root;
}

void preorder(tree*root)
{

	if(!root)
		return;
	printf("%d\t",root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(tree*root)
{

	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->val);
}

void inorder(tree*root)
{

	if(!root)
		return;
	inorder(root->left);
	printf("%d\t",root->val);
	inorder(root->right);
}