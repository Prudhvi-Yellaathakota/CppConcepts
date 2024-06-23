#include<iostream>
#include<cassert>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    Node(): data(0), next(nullptr){}
    Node( Node& node) // deep copy constructor to handle delete node scenario
    {
        // Node* temp = new Node();
        // temp->data = node.data;
        // temp->next = node.next;
    }
};
class Linkedlist
{
    private:
    Node* head;
    public:
    Linkedlist() { head =nullptr;}
    Node* createNode(int val);
    void insertNode(Node* node);
    void PrintList() const;
    void DeleteNode();
    void ReverseList();
    void FindMiddle()const;
    ~Linkedlist()
    {
        while(head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;  
        }
    }
};
int main()
{
    Node* temp = nullptr;
    Linkedlist* linkedlist = new Linkedlist();

    int option = -1;
    std::cout<<"*************SIngleLinkedList*************************\n\n";
    do{
        std::cout<<"1) InsertNode at Begin\n 2) DeleteNode At end\n 3)PrintList\n 4)ReverseLinkedList\n 5)FindMiddle\n 9)Terminate\n";
        std::cout<<"enter your choice: "; std::cin>>option; std::cout<<endl;
       // system("clear");
        switch(option)
        {
            case 1:  //insert at begin
            {
                int val;
                std::cout<<std::endl<<"enter value to be inserted: "; std::cin>>val; std::cout<<endl;
                temp = linkedlist->createNode(val);
                linkedlist->insertNode(temp);
                break;
            }
            
            case 2:  //delete at end;
            {
               linkedlist->DeleteNode();
               break;
            }
            case 3:  //PrintList;
            {
               linkedlist->PrintList();
               break;
            }
            case 4:  //ReverseLinkedList
            {
                linkedlist->ReverseList();
                break;
            }
            case 5:  //FindMiddle
            {
                linkedlist->FindMiddle();
                break;
            }
            case 9: //Terminate
             { 
                delete linkedlist;
                exit(0);
                //break;  // no point writing break stmt here
             }
             default: 
             {
                std::cout<<"invalid option\n";
                break;
             }

        }

    }while(option != 0);

    delete temp;
    delete linkedlist;
    return 0;
}

/**//////////////////////////// */
Node* Linkedlist::createNode(int val)
{
    Node* newnode = new Node(val);
    newnode->next = nullptr;
    return newnode;
}
void Linkedlist::PrintList() const
{
    Node* temp = nullptr;
    if(head != nullptr)
    {
        temp = head;
    }
    while(temp != nullptr)
    {
        std::cout<<temp->data;
        if(temp->next != nullptr) std::cout<<"->";
        temp = temp->next;
    }
    std::cout<<"\n\n";
}
void Linkedlist::insertNode(Node* node) //at begin
{
    assert(node);  //check, if node is not nullptr;
    if(head == nullptr)
    {
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

void Linkedlist::DeleteNode() //at end
{
    if(head == nullptr)
    {
        std::cout<<"List is empty!\n\n";
    }
    else if(head->next == nullptr)
    {
        delete head;
    }
    else
    {
        Node* temp = head;
        while(temp->next->next != nullptr)  //fast
        {
            temp = temp ->next;  //slow
        }
        delete temp->next;
        temp->next = nullptr; 
    }
}
void Linkedlist::ReverseList()
{
    if(head == nullptr || head->next == nullptr)
    {
        std::cout<<"List is empty, can't reverse it \n";
    }
        Node*  prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;   
        while(curr != nullptr)
        {
            next = curr->next;  // next to store the current next link, then next iteration stores upcoming next pointer
            curr->next = prev;  //assign null 
            prev = curr;  //assign currentval to previous
            curr = next;  // to increment till the end of iteration
        }
        head = prev;
}
void Linkedlist::FindMiddle()const
{
    Node* fast = head;
    Node* slow = head;
    int middle = 0;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        middle++;
    }
    std::cout<<"middle: "<<slow->data<<" count: "<<middle<<std::endl;
}