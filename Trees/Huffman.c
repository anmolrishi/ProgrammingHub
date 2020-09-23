#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char ch;
	int freq;
	struct node *left;
	struct node *right;
}node;
typedef struct data
{
	char c;
	char c_code[100];
}data;

void Get_code(node *,data [],char [],int *);
node* Create_Huffman_Tree(node* [],int );

void copy(node **,node **);
void swap(node **,node **);

void Create_Min_Heap(node* [],int );
node* Extract_Min(node* [],int );
void Insert(node* [],node *,int );
void Adjust_key(node* [],int);
void Min_Heapify(node* [],int,int);

int main()
{
	data arr[100];
	node* code[100];
	char huff_code[100];
	node* root;
	int n,i;

	printf("enter the no of the characters\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		code[i]=(node*)malloc(sizeof(node));
	}

	printf("enter the characters\n");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		scanf("%c",&(code[i]->ch));
	}

	printf("enter the frequency\n");
	for(i=0;i<n;i++)
	scanf("%d",&(code[i]->freq));
	
	for(i=0;i<n;i++)
	{
		code[i]->left=NULL;
		code[i]->right=NULL;
	}
	
	root=Create_Huffman_Tree(code,n);
	
	huff_code[0]='\0';
	i=0;
	Get_code(root,arr,huff_code,&i);
	
	printf("HUFFMAN CODES are\n");
	for(i=0;i<n;i++)
	{
		printf("%c %s\n",arr[i].c,arr[i].c_code);
	}
	return 0;
}
void Get_code(node *root,data arr[],char huff_code[],int *i)
{
	char temp[100];
	if(root->left==NULL)
	{
		arr[*i].c=root->ch;
		strcpy(arr[*i].c_code,huff_code);
		(*i)++;
	}
	else 
	{
		strcpy(temp,huff_code);
		strcat(huff_code,"0");
		Get_code(root->left,arr,huff_code,i);
		strcpy(huff_code,temp);
		strcat(huff_code,"1");
		Get_code(root->right,arr,huff_code,i);
	}
}
void copy(node **a,node **b)
{
	
	(*a)->ch=(*b)->ch;
	(*a)->freq=(*b)->freq;
	(*a)->left=(*b)->left;
	(*a)->right=(*b)->right;
}
void swap(node **x,node **y)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	copy(&temp,x);
	copy(x,y);
	copy(y,&temp);
}
void Create_Min_Heap(node* code[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		Min_Heapify(code,i,n);
	}
}
void Min_Heapify(node* code[],int i,int n)
{
	int l,r,min;
	l=(i*2)+1;
	if(l<n&&((code[l]->freq)<(code[i]->freq)))
	{
		min=l;
	}
	else 
	min=i;
	r=l+1;
	if(r<n&&((code[r]->freq)<(code[min]->freq)))
	{
		min=r;
	}
	if(i!=min)
	{
		swap(&code[i],&code[min]);
		Min_Heapify(code,min,n);
	}
}
node* Create_Huffman_Tree(node* code[],int n)
{	
	node *x,*y,*z;
	int i,j;
	Create_Min_Heap(code,n);
	for(i=1;i<n;i++)
	{
		z=(node*)malloc(sizeof(node));
		x=Extract_Min(code,n-i+1);
		y=Extract_Min(code,n-i);
		z->left=x;
		z->right=y;
		z->freq=(x->freq)+(y->freq);
		Insert(code,z,n-i-1);
		
	}
	return Extract_Min(code,1);
}
node* Extract_Min(node* code[],int n)
{
	if(n>0)
	{
		node *ptr;
		ptr=code[0];
		code[0]=code[n-1];
		Min_Heapify(code,0,n-1);
		int i;
		return ptr;
	}
	else 
	return NULL;
}
void Insert(node* code[],node *z,int n)
{
	code[n]=z;
	Adjust_key(code,n);
}
void Adjust_key(node* code[],int i)
{
	int parent;
	if(i!=0)
	{
		parent=(i-1)/2;
		if((code[i]->freq)<(code[parent]->freq))
		{
			swap(&code[i],&code[parent]);
			Adjust_key(code,i);
		}
	}
}
