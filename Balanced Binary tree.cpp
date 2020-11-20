#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

bool isBalanced(node* root, int* height)
{
    int lh=0, rh =0;
    bool l=0, r=0;
    if(root == NULL){
       *height =0;
        return true;
    }
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right,&rh);
    *height = max(lh, rh)+1;

    if(abs(lh-rh)>=2) return false;
    else return l && r;  /* If this node is balanced and left and right subtrees
                           are balanced then return true */
}

node* newNode(int data)
{
   node* Node = new node();
   Node->data = data;
   Node->left = NULL;
   Node-> right = NULL;
   return (Node);
}
int main()
{
  int height = 0;
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);

  if(isBalanced(root, &height)) printf("Tree is balanced");
  else printf("Tree is not balanced");
  return 0;
}
