#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int no_key;
	char leaf,key[9];
	struct node* child[10];
}node;

typedef struct search_node{		//will be used to return key and pointer in the search function
	node* pointer;
	int index;
}search_node;
void split_node(node* parent_node,int i,node* child_node,int order);
node* insert(node* root);
void insert_nonfull(node* root,int order,char k);
node* create_BTree();
void print_BTree(node* );
void inorder_BTree(node*);
search_node* search(node*,char );
void search_fn(node* root);
int main()
{
	int choice;
	char cont;//used to ask the user whether he wants to continue or not
	printf("enter the values in the root \n");
	node *root;
	root=create_BTree();
	do
	{
		printf("\nenter operation : 1.Print tree node by node 2. Inorder Traversal 3. Search a key 4. Insert \
		\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				print_BTree(root);
				break;
			case 2:
				printf("\n inorder traversal is\n");
				inorder_BTree(root);
				break;
			case 3:
				search_fn(root);
				break;
			case 4:
				root=insert(root);
			break;
			default:
				printf("wrong choice\n");
		}
		printf("Do you want to continue:y or n\n");
		fflush(stdin);
		scanf("%c",&cont);
	}while(cont=='y'||cont=='Y');
	return 0;
}

node* insert(node* root)
{
	char k;
	int order;
	printf("enter the key to insert\n");
	fflush(stdin);
	scanf("%c",&k);
	printf("enter the order of the tree  must be<=5    -----this must be valid with the current no of keys in any node\n");
	scanf("%d",&order);
	if((root->no_key)==(2*order-1))
	{
		node *newnode=(node*)malloc(sizeof(node));
		newnode->no_key=0;
		newnode->leaf='n';
		newnode->child[0]=root;
		split_node(newnode,0,root,order);
		root=newnode;
		insert_nonfull(root,order,k);
	}
	else 
		insert_nonfull(root,order,k);
		return root;
}
void insert_nonfull(node* root,int order,char k)
{
	int i,j;
	for(i=0;i<(root->no_key);i++)
	{
		if(k<=(root->key[i]))
		break;
	}
	
	if((root->leaf=='y')||(root->leaf=='Y'))
	{
		for(j=(root->no_key)-1;j>=i;j--)
		root->key[j+1]=root->key[j];
		root->key[j+1]=k;
		root->no_key=root->no_key+1;
	}
	else
	{
		if((root->child[i])->no_key==(2*order-1))
		{
			split_node(root,i,root->child[i],order);
		}
		if(k>root->key[i])
		i++;
		insert_nonfull(root->child[i],order,k);
	}
}
void split_node(node* parent_node,int i,node* child_node,int order)
{
	node* newnode=(node*)malloc(sizeof(node));
	int j;
	for(j=0;j<order-1;j++)
	newnode->key[j]=child_node->key[order+j];
	newnode->no_key=order-1;
	newnode->leaf=child_node->leaf;
	if((child_node->leaf)!='y'&&(child_node->leaf)!='Y')
	{
		for(j=0;j<order;j++)
		newnode->child[j]=child_node->child[order+j];
	}
	child_node->no_key=order-1;
	for(j=(parent_node->no_key);j>=i+1;j--)
	parent_node->child[j+1]=parent_node->child[j];
	parent_node->child[i+1]=newnode;
	for(j=(parent_node->no_key-1);j>=i;j--)
	parent_node->key[j+1]=parent_node->key[j];
	parent_node->key[i]=child_node->key[order-1];
	parent_node->no_key++;
	
}
void search_fn(node* root)
{
	search_node* found;
	char search_key;
	printf("enter the key to search\n");
	fflush(stdin);
	scanf("%c",&search_key);
	found=search(root,search_key);
	if(found!=NULL)
	printf("key found in node with initial key:  %c and at index:  %d\n",(found->pointer)->key[0],(found->index));
	else 
	printf("key not found\n");
}

search_node* search(node* root,char search_key)
{
	int i;
	search_node* temp;
	for(i=0;i<(root->no_key);)
	{
		if(search_key>(root->key[i]))
		i++;
		else break;
	}
	if(i<(root->no_key)&&search_key==(root->key[i]))
	{
		temp=(search_node*)malloc(sizeof(search_node));
		temp->pointer=root;
		temp->index=i+1;
		return temp;
	}
	else if((root->leaf)!='y'&&(root->leaf)!='Y')
	return search(root->child[i],search_key);
	return NULL;
}
void print_BTree(node* root)
{
	int i;
	for(i=0;i<(root->no_key);i++)
	{
		printf("%c ",root->key[i]);
	}
	printf("\n");
	if((root->leaf)!='y'&&(root->leaf)!='Y')
	{
		for(i=0;i<=(root->no_key);i++)
		print_BTree(root->child[i]);
	}
}

void inorder_BTree(node* root)
{
	int i;
	if((root->leaf)=='y'||(root->leaf)=='Y')
	{
		for(i=0;i<(root->no_key);i++)
		{
			printf("%c ",(root->key[i]));
		}
	}
	else
	{
		for(i=0;i<(root->no_key);i++)
		{
			inorder_BTree(root->child[i]);
			printf(" | ");
			printf("%c ",(root->key[i]));
			printf(" | ");
		}
		inorder_BTree(root->child[i]);
	}
}
node* create_BTree()
{
	int i;
	node* temp=(node*)malloc(sizeof(node));
	printf ("enter the no of keys in the node\n");
	scanf("%d",&(temp->no_key));
	if(temp->no_key)
	{
		printf("enter the keys in the node\n");
		for(i=0;i<(temp->no_key);i++)
		{
			fflush(stdin);
			scanf("%c",&(temp->key[i]));
		}
		printf("is it a leaf node?? y or n\n");
		fflush(stdin);
		scanf("%c",&(temp->leaf));
		if((temp->leaf)!='y'&&(temp->leaf)!='Y')
		{
			
			printf("enter the values in the child nodes\n");
			printf("enter for child <%c\n",(temp->key[0]));
			temp->child[0]=create_BTree();
			for(i=1;i<(temp->no_key);i++)
			{
				printf("enter for child between %c and %c\n",(temp->key[i-1]),(temp->key[i]));
				temp->child[i]=create_BTree();
			}
			printf("enter for child >%c\n",(temp->key[(temp->no_key)-1]));
			temp->child[(temp->no_key)]=create_BTree();
		}
	}
	return temp;
}
