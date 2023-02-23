#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node* previous;

    //constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};
void print(node* &head, node* &tail){
    if(head == NULL) return;
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"head : "<<head->data<<" tail : "<<tail->data<<endl;
}
void InsertAtHead(int data,node* &head,node* &tail)
{
    node* newnode = new node(data);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    newnode->next = head;
    head->previous = newnode;
    head = newnode;
}
void InsertAtTail(int data,node* &head,node* &tail)
{
    node* newnode = new node(data);
    if(tail == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    tail->next = newnode;
    newnode->previous = tail;
    tail = newnode;
}
void InsertNodePosition(int pos,int data,node* &head,node* &tail)
{
    //insert node at 1st position
    if(pos == 1) return InsertAtHead(data,head,tail);

    node* temp = head;
    int c = 1;
    while(c<pos-1 && temp!=NULL)
    {
        temp = temp->next;
        c++;
    }
    //insert at last position
    if(temp->next==NULL) return InsertAtTail(data,head,tail);
    node* newnode = new node(data);
    //insert at any middle positions..
    newnode->next = temp->next;
    temp->next->previous = newnode;
    temp->next = newnode;
    newnode->previous = temp;
}

void deletenodebypos(int pos,node* &head,node* &tail){
    //delete node at position 1
    node* temp = head;
    if(pos==1 and temp){
        head = head->next;
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
    }
    //delete node at middle or lat position
    node* prev = NULL;
    int c = 1;
    while(c<pos && temp){
        prev = temp;
        temp = temp->next;
        c++;
    }
        cout<<"temp : "<<temp->data<<" prev : "<<prev->data<<endl;

    if(temp==NULL) {
        cout<<"pos error"<<endl;
        return;
    }
    if(temp==tail) {
        tail = prev;
        prev->next = NULL;
        delete temp;
        return;
    }
    prev->next = temp->next;
    temp->next->previous = prev;
    temp->next = NULL;
    temp->previous = NULL;
    delete temp;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    InsertNodePosition(1,1,head,tail);
    InsertAtTail(4,head,tail);
    InsertNodePosition(2,2,head,tail);
    InsertNodePosition(3,3,head,tail);
    deletenodebypos(4,head,tail);
    print(head, tail);
}