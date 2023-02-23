#include<bits/stdc++.h>
using namespace std;
bool pos_error;
class  Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* head,Node* tail)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Head : "<<head->data<<" "<<"tail : "<<tail->data<<endl;
}
void InsertAtStart(int data,Node* &head){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void InsertAtEnd(int data,Node* &head,Node* &tail){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void InsertAtPosition(int data,int pos,Node* &head,Node* &tail){
    //insert at position 1
    if(pos==1) {
    InsertAtStart(data,head);
    return;
    }
    //insert at middle position or end position ...
    int c = 1;
    Node* temp = head;
    while(c<pos-1)
    {
        if(temp->next==NULL) {
        pos_error = true;
        cout<<"position error"<<endl;
        return;
        }
        temp = temp->next;
        c++;
    }
    if(temp->next==NULL) {
        InsertAtEnd(data,head,tail);
        return;
    }
    Node* newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
    
}
void delete_node(int key,Node* &head,Node* &tail){
    
    Node* temp= head;
    Node* prev = NULL;
    //if key itself has value equal to head value
    if(temp!=NULL && key==temp->data) {
        head = head->next;
        delete temp;
        return;
    }
    else
        { 
            //traverse through the entire linkedlist and find for the key value
            while(temp!=NULL && temp->data!=key){
                prev = temp;
                temp = temp->next;
            }
            if(temp==NULL){
                cout<<"not found"<<endl;
                return;
            }
            else if(temp==tail){
                tail = prev;
                prev->next = NULL;
                delete temp;
                return;
            }
            prev->next = temp->next;
            delete temp;
    }
    
}

int main(){
    Node* node = new Node(2);
    Node* head = node;
    Node* tail = node;
    //InsertAtStart(1,head);
    InsertAtEnd(3,head,tail);
     InsertAtEnd(4,head,tail);
      InsertAtEnd(5,head,tail);
   // InsertAtPosition(4,4,head,tail);
    delete_node(45,head,tail);
    print(head,tail);


    return 0;
}