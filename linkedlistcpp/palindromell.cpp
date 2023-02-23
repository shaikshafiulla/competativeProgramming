#include<iostream>
using namespace std;
class node{
    public :
        int data;
        node* next;

        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

    void print(node* &head)
    {
        node* current = head;
        while(current!=NULL){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    node* findmid(node* &head)
    {
        if(head==NULL) return NULL;
        node* slow = head;
        node* fast = head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    node* reverse(node* head){
        node* pre = NULL;
        node* cur = head;
        node* next = NULL;
        while(cur!=NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    bool checkpalindrome(node* &head)
    {
        if(head==NULL || head->next==NULL) return false;
        //find mid element..
        node* middle = findmid(head);
        //reverse the second half of the linked list... after the middle node
        node* temp = middle->next;
        middle->next = reverse(temp);
        //compare
        node* cur = head;
        node* cur2 = middle->next;
        print(head);
        while(cur2!=NULL) {
            if(cur2->data!=cur->data) {
                return false;
            }
            cur2 = cur2->next;
            cur = cur->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        print(head);
        return true;
    }
int main(){
    node* head = new node(3);
    node* node1 = new node(1);
    node* node2 = new node(7);
    node* node3 = new node(7);
    node* node4 = new node(1);
    node* node5 = new node(3);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    cout<<checkpalindrome(head);
}