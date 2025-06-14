#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
    data = val;
    next = nullptr;
    }
};

class linkedlist{
    private:
    node* head;
    public:
    linkedlist(){
    head=nullptr;
}
void insert_at_begin(int data){
    node* new_node = new node(data);
    new_node->next=head;
    head=new_node;
}
void display(){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    node* temp = head;
    while(temp !=nullptr){
        cout<<temp->data<<"";
        temp=temp->next;
    }
}
};

int main(){
    linkedlist l1;
    l1.insert_at_begin(6);
    l1.insert_at_begin(5);
    l1.insert_at_begin(4);
    l1.insert_at_begin(3);
    l1.insert_at_begin(2);
    l1.insert_at_begin(1);
    l1.display();

}