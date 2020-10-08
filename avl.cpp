#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node* left;
  node* right;
  int h;
};

node* createnode()
{
  node *temp = new node;
  return temp;
}
int geth(node *head)
{
  return head==NULL?0:head->h;
}
void updateh(node *head)
{
  head->h = max(geth(head->left),geth(head->right))+1;
}

node* lrotation(node *a)
{
  node *c=a->right;
  a->right=c->left;
  c->left=a;
  updateh(a);
  updateh(c);
  return c;
}

node* rrotation(node *a)
{
  node *c=a->left;
  a->left=c->right;
  c->right=a;
  updateh(a);
  updateh(c);
  return c;
}

node* balance(node *a)
{
int bal = geth(a->left)-geth(a->right);
if(bal>1)
{
  if(geth(a->left->left)>geth(a->left->right))
  {
    a=rrotation(a);
  }
  else
  {
    a->left=lrotation(a->left);
    a=rrotation(a);
  }
}
else if (bal<-1)
{
  if(geth(a->right->right)>geth(a->right->left))
  {
    a=lrotation(a);
  }
  else
  {
    a->right=rrotation(a->right);
    a=lrotation(a);
  }
}
return a;
}

void inorder(node *root) {
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->val<<"  "<<geth(root)<<"\n";
  inorder(root->right);
}
node* insert(node *root,int value)
{
  if(root == NULL)
  {
    root=createnode();
    root->val=value;
    updateh(root);
    return root;
  }
  if(value>root->val)
  {
    root->right=insert(root->right,value);
  }
  else
  {
    root->left=insert(root->left,value);
  }
  root=balance(root);
  updateh(root);
  return root;
}
int main(void)
{
  int n;
  int num;
  node *root=NULL;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>num;
    root=insert(root,num);
  }
  inorder(root);
  return 0;
}
