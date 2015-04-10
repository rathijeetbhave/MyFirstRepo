#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

int diameterOpt(struct node* ,int*);
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
   node* node = (struct node*)
                       malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}



int main()
{
	int height=0;
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
 
  cout<<"Diameter of the given binary tree is %d\n", diameterOpt(root,&height);
 
  //getchar();
  return 0;
}



int diameterOpt(struct node *root, int* height)
{
  /* lh --> Height of left subtree
      rh --> Height of right subtree */
  int lh = 0, rh = 0;
  
  /* ldiameter  --> diameter of left subtree
      rdiameter  --> Diameter of right subtree */
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0; /* diameter is also 0 */
  }
  
  /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);
  
  /* Height of current node is max of heights of left and
     right subtrees plus 1*/
  *height = max(lh, rh) + 1;
  
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}


int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

