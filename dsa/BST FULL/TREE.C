
//COMPLETE PROGRAM ON BINARY SEARCH TREE
//BY LAVISH KOTHARI
// 8 JANUARY 2013  00:25:53
//YAHOO........
#include<stdio.h>
#include<conio.h>

struct Tree
{
	int val;
	struct Tree* left,* right;
};

typedef struct Tree tree;


void inorder(tree*);
void preorder(tree*);
void postorder(tree*);
tree*makenode(int);
tree*add(tree*,tree*);
int countheight(tree*);
int countleaf(tree*);
int countnode(tree*);
void expandlevel(tree*,int,int);
tree*deletenode(tree*,int);



static int s=0;

int main()
{
	tree*root,*nn;
	//int level;
	int tmp,ch;
	root=NULL;
	clrscr();
	while(1)
	{
		printf("ENTER THE VALUE OF NODE");
		scanf("%d",&tmp);

		if(tmp==0)
			break;

		nn=makenode(tmp);

		root=add(root,nn);

	}

	while(1)
	{
		clrscr();
		printf("YOU HAVE FOLLOWING CHOICES:\n");
		printf("1.PRINT PREORDER\n");
		printf("2.PRINT INORDER\n");
		printf("3.PRINT POSTORDER\n");
		printf("4.ADD A NODE\n");
		printf("5.COUNT THE NUMBER OF LEVELS OF TREE\n");
		printf("6.COUNT THE HEIGHT\n");
		printf("7.COUNT THE NUMBER OF LEAF NODES\n");
		printf("8.COUNT THE TOTAL NUMBER OF NODES\n");
		printf("9.PRINT ALL THE ELEMENTS OF A PARTICULAR LEVEL\n");
		printf("10.DELETE A NODE FROM THE TREE\n");
		printf("11.EXIT\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				preorder(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				printf("ENTER THE DATA PART OF THE NODE THAT YOU WANT TO ADD");
				scanf("%d",&tmp);
				nn=makenode(tmp);
				root=add(root,nn);
				break;
			case 5:
				//level=countlevel(root);
				printf("\n%d",countheight(root)-1);
				break;
			case 6:
				printf("%d",countheight(root));
				break;
			case 7:
				s=0;
				printf("%d",countleaf(root));
				break;
			case 8:
				s=0;
				printf("%d",countnode(root));
				break;
			case 9:
				printf("ENTER THE LEVEL NUMBER THAT YOU WANT TO EXPAND: ");
				scanf("%d",&tmp);
				if(countheight(root)<tmp)
					printf("THE LEVEL YOU ENTERED DOES NOT EXIST");
				else
					expandlevel(root,tmp,0);
				break;
			case 10:
				printf("ENTER THE DATA PART OF THE NODE THAT YOU WANT TO DELETE");
				scanf("%d",&tmp);
				root=deletenode(root,tmp);
				break;
			case 11:
				exit(1);
				break;
			default:
				printf("YOU HAVE ENTERED A WRONG CHOICE");
		}
		printf("\nPRESS ANY KEY TO CONTINUE...");
		getch();
	}

	getch();
	return 1;
}

tree*deletenode(tree*root,int sval)
{
	int dir;
	tree*ptr,*prev,*temp;
	prev=NULL;
	ptr=root;
	if(!root)
		return root;

	while(ptr)
	{
		if(ptr->val==sval)
			break;
		prev=ptr;
		if(ptr->val>sval)
		{
			ptr=ptr->left;
			dir=0;
		}
		else
		{
			ptr=ptr->right;
			dir=1;
		}
	}

	if(ptr)
	{
		if(ptr->left==NULL&&ptr->right==NULL)  //FOR LEAF NODE
		{
			if(ptr==root)           //LEAF NODE THAT IS ROOT
				root=NULL;
			else
				if(dir==0)            //LEAF NODE THAT IS LEFT CHILD
					prev->left=NULL;
				else
					prev->right=NULL;   //LEAF NODE THAT IS RIGHT CHILD

		}
		else                          //NODE THAT IS NOT A LEAF NODE
		{
			if(ptr->left&&ptr->right==NULL)
			{
				if(ptr==root)
					root=root->left;
				else
					if(dir==0)
						prev->left=ptr->left;
					else
						prev->right=ptr->left;
			}
			else
			{
				if(ptr==root)
					root=root->right;
				else
					if(dir==0)
						prev->left=ptr->right;
					else
						prev->right=ptr->right;
			}

			temp=ptr->right;
			while(temp->left)
				temp=temp->left;
			temp->left=ptr->left;
		}
		free(ptr);
	}
	return root;
}


void expandlevel(tree*root,int level,int clevel)
{
	if(!root&&clevel>level)
		return;
	if(clevel==level&&root)
	{
		printf("%d\t",root->val);
		return;
	}
	if(clevel==level)
		return;

	expandlevel(root->left,level,clevel+1);
	expandlevel(root->right,level,clevel+1);
}



int countnode(tree*root)
{
	if(root)
	{
		countnode(root->left);
		countnode(root->right);
		s++;
	}
	return s;
}

int countleaf(tree*root)
{
	if(root)
	{
		countleaf(root->left);
		countleaf(root->right);
		if((!(root->left))&&((!root->right)))
			s++;
	}
	return s;
}


int countheight(tree*root)
{
	int l,r;
	if(!root)
		return 0;
	l=1+countheight(root->left);
	r=1+countheight(root->right);

	if(l>r)
		return l;
	return r;
}




void inorder(tree*root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t",root->val);
		inorder(root->right);
	}
}

void postorder(tree*root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->val);
	}
}

void preorder(tree*root)
{
	if(root)
	{
		printf("%d\t",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}



tree*makenode(int tmp)
{
	tree*nn;
	nn=(tree*)malloc(sizeof(tree));
	nn->val=tmp;
	nn->left=nn->right=NULL;
	return nn;
}

tree*add(tree*root,tree*nn)
{
	int dir;
	tree*ptr,*prev;

	if(!root)
		return nn;
	ptr=root;

	while(ptr)
	{
		prev=ptr;
		if(ptr->val>nn->val)
		{
			dir=0;
			ptr=ptr->left;
		}
		else
		{
			dir=1;
			ptr=ptr->right;
		}
	}

	if(dir)
		prev->right=nn;
	else
		prev->left=nn;

	return root;
}

