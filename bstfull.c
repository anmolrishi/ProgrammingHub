#include<stdio.h>
#include<stdlib.h>


struct node{
  int val;
  int leftsub;
  int rightsub;
  int size;
  struct node *left;
  struct node *right;
  struct node *parent;
};

struct node *parent;

struct node *newnode(int val){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->left=temp->right=NULL;
  temp->val=val;
  return temp;
}

void inorder(struct node *root){

  if(root!=NULL){
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
  }
}

void printPostorder(struct node* root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ",root->val);
}
void pre(struct node* root)
{
    if (root == NULL)
        return;
    printf("%d ",root->val);

    pre(root->left);

    // then recur on right subtree
    pre(root->right);

    // now deal with the node
}

struct node *insert(struct node *root, int val){
  //printf("inseting")

  if(root==NULL)
  {
    struct node *temp=newnode(val);
    temp->size=1; temp->rightsub=0; temp->leftsub=0;
    return temp;
  }

  if(val>root->val)
  {
    root->rightsub+=1;
    root->right=insert(root->right,val);
  }
  else if(val<root->val)
  {
    root->leftsub+=1;
    root->left=insert(root->left,val);
  }

  return root;
}

struct node *kthmin (struct node *root, int k){
  printf("k=%d root->leftsub %d root->rightsub %d root->size %d\n",k,root->leftsub, root->rightsub, root->size);
  if(root!=NULL){
  if(root->leftsub>=k)
    return kthmin(root->left,k);
  else if(k-root->leftsub==1)
    {printf("min= %d \n", root->val); return(root);}
  else
    return kthmin(root->right,k-root->leftsub-1);
  }

}

struct node *del(struct node *root, int val){

  if(root==NULL) return root;

  if(val<root->val)
    root->left=del(root->left,val);
  else if(val>root->val)
    root->right=del(root->right, val);
  else
    {
      if(root->right==NULL)
      {
        struct node *temp=root->left;
        free(root);
        return temp;
      }
      else if(root->left==NULL)
      {
        struct node *temp=root->right;
        free(root);
        return temp;
      }

        struct node *temp=root->right;

        while(temp->left!=NULL)
          temp=temp->left;

        root->val=temp->val;

        root->right=del(root->right,temp->val);

      }

    return root;

}


struct node *suc(struct node *root, int val){
  if(val<root->val) {parent=root; root->left=suc(root->left,val);}
  else if(val>root->val){parent=root; root->right=suc(root->right,val);}
  else{
    struct node *temp=root->right;
    if(root->right!=NULL)
    {
      while(temp->left!=NULL)
        temp=temp->left;
        printf("temp->val %d\n",temp->val);
    return temp;
    }
    else{

      if(root->right!=NULL){
        while(parent->left->val!=root->val){
          root=parent;
        }
        printf("parent->val %d\n",parent->val);

        return parent;
      }

    }
  }
}

int main(void){

  struct node *root=NULL;
  struct node *temp=NULL;
  int a[10]={5,4,6,11,10,15,12,20},op;
  for(int i=0;i<8;i++)
  {
    if(i==0)
    {
      root=insert(root,a[i]);
    }
    else
    {
      temp=insert(root,a[i]);
    }

  }

  printf("Existing BST: \n");
  inorder(root);
  printf("\n");

  printf("\nOPTIONS:\n1.Insert\n2.Kthmin\n3.Delete\n4.Inorder\n5.Postorder\n6.Preorder\n7.Successor\n\n");
  scanf("%d",&op);

  do{
    if(op==1)
    {
      int n; printf("Enter n: "); scanf("%d", &n);
      temp=insert(root,n);
    }
    else if(op==2)
    {
      int k; printf("Enter k : "); scanf("%d",&k);
      temp=kthmin(root,k);
      printf("Kth min is: %d\n",temp->val);
    }
    else if(op==3)
    {
      int n; printf("Enter n: "); scanf("%d", &n);
      temp=del(root,n);
    }
    else if(op==4)
    {
      inorder(root);
      printf("\n");
    }
    else if(op==5)
    {
      printPostorder(root);
      printf("\n");
    }
    else if(op==6)
    {
	pre(root);
   	printf("\n"); 
    }
    else if(op==7)
    {
      struct node *temp2=NULL;
      int n; printf("Enter n: "); scanf("%d", &n);
      temp2=suc(root,n);
      printf("Successor is: %d \n",temp2->val);
    }

    printf("\nOption? "); scanf("%d",&op);
  }while(op!=0);


}
