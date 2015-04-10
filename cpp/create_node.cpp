#include<iostream>
#include<cstdlib>
using namespace std;

struct node* newNode(int);
void printTree(node*);
struct node{
	int data;
	struct node* left;
	struct node* right;
	};
	
struct node* newNode(int data)
{
	node* node=(struct node*)malloc(sizeof(node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int main()
{
	struct node* root;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	printTree(root);
}

void printTree(node* node)
{
	if(node==NULL)
		return;
	else
	{
		printTree(node->left);
		cout<<node->data;
		printTree(node->right);
	}
}
	
