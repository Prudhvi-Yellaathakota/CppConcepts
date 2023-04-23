//Depth First search Tree Traversal
#include<iostream>
#include<string>
using namespace std;
struct Node
{
 int data;
 struct Node* left;
 struct Node* right;
 //struct Node():left(nullptr),right(nullptr){}
};

struct Node* GetNode(int data)
{
  struct Node* newNode= new struct Node();
  newNode->data= data;
  newNode->left=newNode->right=nullptr;
  return newNode;
}
struct Node* Insert(struct Node* root, int data) 
{
	if(root ==nullptr)
	  root=GetNode(data);
	else if(data <= (root->data))
	{
		Insert((root->left),data);
	}
	else
		Insert((root->right),data);
	return root;
}
void InorderTraversal(struct Node* root)
{
    if(root == nullptr) return; 
    InorderTraversal(root->left);
	std::cout<<root->data<<" ,";
	InorderTraversal(root->right);
}

int main()
{
    struct Node* root=NULL;
	root= Insert(root,10); root=  Insert(root,15);
	root= Insert(root,14); root= Insert(root,3); root=  Insert(root,25);
	InorderTraversal(root);
	return 0;
}
