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

class DFStraversal
{
  private:
   // struct Node* root;
  public:
//    DFStraversal(struct Node* ptr) {root =ptr;}
      struct Node* GetNode(int data)
      {
        struct Node* newNode= new struct Node();
	(*newNode).left=newNode->right=nullptr;
	return newNode;
      }
    
    void Preorder(struct Node* root)
    {
      if(root != nullptr)
      {
         Preorder(root->left);
	 std::cout<<root->data<<" ,";
	 Preorder(root->right);
	 std::cout<<root->data<<" ,";
      }

    }

 };
 int main()
 {
    DFStraversal* obj;
  
   return 0;
 }
