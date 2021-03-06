#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node* next;
    Node* prev;

    public:
    Node* createNode(int d);
    void buildList(Node* np);
    Node* find(Node* np ,int pos);
    void insert(Node* np,Node* newNode,int pos);
    void remove(Node* np,int pos);
    void makeEmpty(Node* np);
    void printList(Node* np);
}*head,*tmp,*p;


Node* Node::createNode(int d){
   Node* np = new Node();
   np->data = d;
   np->next = NULL;
   np->prev = NULL;
   return np;
}


Node* Node::find(Node* np,int pos){
    for(int i = 0;i<pos;i++ ){
        if(i == pos-2){
            return np;
        }
        np=np->next;
    }
}

void Node::buildList(Node* np){
     Node* t = new Node();
    if(head == NULL){
        head = np;
        np->next = head;
        np->prev = head;
    }
    else{
        t = head->prev;
        t->next = np;
        np->prev = t;
        np->next = head;
        head->prev = np;
    }
}

void Node::insert(Node* np,Node* newNode,int pos){
    Node* t= new Node();

    if(pos == 1){
        t=head->prev;
        t->next=newNode;
        newNode->prev=t;
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return ;
    }
    np = find(np,pos);

    if(np->next == NULL){
        np->next = newNode;
        newNode->prev = np;
        newNode->next = head;
        head->prev = newNode;
        return ;
    }
    else{
        t=np->next;
        np->next=newNode;
        t->prev=newNode;
        newNode->next=t;
        newNode->prev=np;
        return ;
    }
}

void Node::remove(Node* np,int pos){
    Node* t = new Node();

    if(head == NULL)
        cout<<"underflow";

    if(pos == 1){
        Node* tmp = head;
        t=head->prev;
        tmp=head;
        head=head->next;
        t->next = head;
        head->prev = t;
        delete tmp;
        return ;
    }

    np = find(np,pos);

    if(np->next->next == NULL){
        t=np->next;
        delete t;
        np->next = head;
        head->prev = np;
        return ;
    }
    else{
        t=np->next;
        np->next->next->prev = np;
        np->next = np->next->next;
        delete t;
        return ;
    }
}

void Node::makeEmpty(Node* np){
    Node* t = new Node();
    while(np != NULL){
        t=np;
        np=np->next;
        head = np;
        delete t;
    }
}

void Node::printList(Node* np){
    while(true){
        cout<<" "<<np->data<<"->";
        if(np->next == head){
            return;
        }
        np = np->next;
    }
}

int main(){
    head = NULL;
    int data,nd,pos1,pos2;
    char ch = 'y';
    Node n;


    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter data for new node: ";
        cin>>data;
        p = n.createNode(data);
        n.buildList(p);
        n.printList(head);
        cout<<"\nDo u want to add new element(y/n): ";
        cin>>ch;
    }
    n.printList(head);
    ch='y';
    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter Value and position of new node: ";
        cin>>nd>>pos1;
        p = n.createNode(nd);
        n.insert(head,p,pos1);
        n.printList(head);
        cout<<"\nDo u want to insert new element(y/n): ";
        cin>>ch;
    }
    ch='y';
    while(ch == 'y' || ch == 'Y'){
        cout<<"\nEnter positon of node to remove: ";
        cin>>pos2;
        n.remove(head,pos2);
        n.printList(head);
        cout<<"\nDo u want to remove element(y/n): ";
        cin>>ch;
    }

    /*cout<<"\n list empty";
    n.makeEmpty(head);
    n.printList(head);*/
    return 0;
}
